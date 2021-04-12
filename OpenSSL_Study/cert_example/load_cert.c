/**
 * 加载证书，并读取相关信息
 */

#include <stdio.h>
#include <assert.h>
#include <string.h>

#include <openssl/err.h>
#include <openssl/x509v3.h>
#include <openssl/pem.h>
#include "openssl/pkcs12.h"
#include "applink.c"


int loadP12(char *p12FilePath, char *p12Pwd, X509 **cert_x509, EVP_PKEY **pKey);
int showCertInfo(X509 *cert);
int showPrivateKey(EVP_PKEY *key);


/**
 * 加载 .p12 文件，解析得到 X509 证书和 EVP_PKEY 私钥
 *
 * @param p12FilePath .p12 文件路径
 * @param p12Pwd 解析 .p12 文件的密码
 * @param cert_x509 保存证书地址的指针变量
 * @param pKey 保存私钥地址的指针变量
 * @return 状态
 *
 * -- example --
 * X509 *cert;
 * EVP_PKEY *key;
 * LoadP12("../cert/client_1.p12", "123456", &cert, &key);
 */
int loadP12(char *p12FilePath, char *p12Pwd, X509 **cert_x509, EVP_PKEY **pKey) {
    BIO *fbio = NULL;
    PKCS12 *p12 = NULL;
    EVP_PKEY *key = NULL;
    X509 *cert = NULL;
    int err = 0;

    // 一定是 rb，因为 .p12 文件是二进制文件
    // 读取文件
    if ((fbio = BIO_new_file(p12FilePath, "rb")) == NULL) {
        printf("no such file\n");
        err = -1;
        goto error;
    }

    // 将文件转为 pkcs12 结构体
    if ((p12 = d2i_PKCS12_bio(fbio, NULL)) == NULL) {
        printf("can't convert to p12\n");
        err = -2;
        goto error;
    } else {
        BIO_free(fbio);
        printf("load .p12 file success\n");
    }

    if (PKCS12_verify_mac(p12, p12Pwd, strlen(p12Pwd))) {
        printf("password is ok\n");
    } else {
        printf("password is wrong\n");
        err = -3;
        goto error;
    }

    PKCS12_parse(p12, p12Pwd, &key, &cert, NULL);
    if (cert == NULL) {
        printf("can't get cert\n");
        err = -4;
        goto error;
    } else {
        printf("get cert success\n");
        (*cert_x509) = cert;
    }
    if (key == NULL) {
        printf("can't get key\n");
        err = -5;
        goto error;
    } else {
        printf("get key success\n");
        (*pKey) = key;
    }

    PKCS12_free(p12);
    return 1;

error:
    if (fbio != NULL) BIO_free(fbio);
    if (p12 != NULL) PKCS12_free(p12);
    if (key != NULL) EVP_PKEY_free(key);
    if (cert != NULL) X509_free(cert);

    return err;
}

/**
 * 打印证书信息
 *
 * @param cert 证书
 * @return 状态码
 */
int showCertInfo(X509 *cert) {
    char *data;
    int i;
    int san_names_num = -1;
    char common_name[100];
    int version;
    
    if (cert == NULL) {
        return -1;
    }
    printf("Cert info:\n");

    // version
    version = X509_get_version(cert);
    printf("\tversion:\n");
    printf("\t\t%d (0x%x)\n", version+1, version);

    // subject
    data = X509_NAME_oneline(X509_get_subject_name(cert), 0, 0);    // 持有者
    printf("\tsubject: \n");
    printf("\t\t%s\n", data);

    // issuer
    data = X509_NAME_oneline(X509_get_issuer_name(cert), 0, 0); // 颁发者
    printf("\tissuer: \n");
    printf("\t\t%s\n", data);

    // common name
    X509_NAME *xname = X509_get_subject_name(cert);
    common_name[0] = '\0';
    X509_NAME_get_text_by_NID (xname, NID_commonName, common_name,
                               sizeof (common_name));
    printf("\tcommon name:\n");
    printf("\t\t%s\n", common_name);

    // subject alt name
    STACK_OF(GENERAL_NAME) *san_names = NULL;
    san_names = (STACK_OF(GENERAL_NAME) *) X509_get_ext_d2i(cert, NID_subject_alt_name, NULL, NULL);
    if (san_names == NULL) {
        return 0;
    } else {
        printf("\tsubject_alt_name:\n");
        san_names_num = sk_GENERAL_NAME_num(san_names);
        for (i = 0; i < san_names_num; i++) {
            const GENERAL_NAME *current_name = sk_GENERAL_NAME_value(san_names, i);
            // 如果是域名
            if (current_name->type == GEN_DNS) {
                data = (char *) ASN1_STRING_get0_data(current_name->d.dNSName);
                printf("\t\t%s\n", data);
            } else if (current_name->type == GEN_IPADD) {
                // 如果是 ip
                const unsigned char *ipv4_addr;
                ipv4_addr = ASN1_STRING_get0_data(current_name->d.iPAddress);
                printf("\t\t%d.%d.%d.%d\n", ipv4_addr[0], ipv4_addr[1], ipv4_addr[2], ipv4_addr[3]);
            }
        }
        sk_GENERAL_NAME_pop_free(san_names, GENERAL_NAME_free);
    }

    return 0;
}

int showPrivateKey(EVP_PKEY *key) {
    // TODO 为啥既能得到公钥，又能得到私钥？EVP_PKEY 不是专门存私钥的嘛？
    PEM_write_PrivateKey(stdout, key, NULL, NULL, 0, 0, NULL);
    PEM_write_PUBKEY(stdout, key);
    return 0;
}

int main() {
    X509 *cert;
    EVP_PKEY *key;
    loadP12("../cert/client_1.p12", "123456", &cert, &key);

    showCertInfo(cert);

    showPrivateKey(key);


    return 0;
}