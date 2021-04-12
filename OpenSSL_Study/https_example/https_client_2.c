#include "openssl/bio.h"
#include "openssl/ssl.h"
#include "openssl/err.h"
#include "applink.c"

int main() {
    SSL_CTX *ctx;

    /* Load encryption & hashing algorithms for the SSL program */
    SSL_library_init();

    /* Load the error strings for SSL & CRYPTO APIs */
    SSL_load_error_strings();

    // # 创建 SSL_CTX
    ctx = SSL_CTX_new(TLS_client_method());



    return 0;
}