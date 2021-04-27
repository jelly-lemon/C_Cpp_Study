/**
 * 哈希表
 *
 * 通过 key --> hash 值 --> 找到 value 存储位置 --> 取出 value
 *
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>


#define MAX_STR_LEN 20
#define MIN_STR_LEN 10

#define HASH_TABLE_MAX_SIZE 10000
typedef struct HashNode_Struct HashNode;

struct HashNode_Struct {
    char *sKey; // key
    int nValue; // value
    HashNode *pNext;    // 链地址法
};


HashNode *hashTable[HASH_TABLE_MAX_SIZE]; // 创建一个容量为 HASH_TABLE_MAX_SIZE 的哈希表（线性表）
int hash_table_size;  // 哈希表中目前存在的键值对数目

/**
 * 初始化哈希表
 */
void hash_table_init() {
    hash_table_size = 0;
    memset(hashTable, 0, sizeof(HashNode *) * HASH_TABLE_MAX_SIZE); // 数组里的每一个字节全部置为 0
}

/**
 * 计算字符串，也就是 key 的 hash 值
 *
 * @param skey key 值
 * @return key 的 hash 值
 */
unsigned int hash_table_hash_str(const char *skey) {
    unsigned int h = 0; // 32 位
    if (skey == NULL || *skey == '\0') {
        return h;
    }
    // 计算字符串的 hash 值（这个公式的来由？随便编一个就行？）
    while (*skey != '\0') {
        h = (h << 5) - h + *skey;
        skey++;
    }
    return h;
}

/**
 * 哈希表的插入
 *
 * @param skey key，字符串
 * @param nvalue value，整数
 */
void hash_table_insert(const char *skey, int nvalue) {
    if (hash_table_size >= HASH_TABLE_MAX_SIZE) {
        printf("out of hash table memory!\n");
        return;
    }
    // 根据 hash 值进行取余运算，得到插入位置
    unsigned int pos = hash_table_hash_str(skey) % HASH_TABLE_MAX_SIZE;

    HashNode *pHead = hashTable[pos];
    while (pHead) {
        // 判断是否存在相同的 key
        // 如果存在，就遍历链表，找到最后一个节点
        if (strcmp(pHead->sKey, skey) == 0) {
            printf("%s already exists!\n", skey);
            return;
        }
        pHead = pHead->pNext;
    }

    // 创建节点，保存键值对（如何处理冲突的呢？链地址法）
    HashNode *pNewNode = (HashNode *) malloc(sizeof(HashNode));
    memset(pNewNode, 0, sizeof(HashNode));  // 将结构体里面所有字节置为 0 有何用处？
    pNewNode->sKey = (char *) malloc(sizeof(char) * (strlen(skey) + 1));
    strcpy(pNewNode->sKey, skey);
    pNewNode->nValue = nvalue;

    // 将键值对节点地址保存在指针变量中
    pNewNode->pNext = hashTable[pos];
    hashTable[pos] = pNewNode;

    hash_table_size++;
}

/**
 * 从哈希表中删除键值对
 *
 * @param skey key 值
 */
void hash_table_remove(const char *skey) {
    // 计算哈希值，得到存储位置
    unsigned int pos = hash_table_hash_str(skey) % HASH_TABLE_MAX_SIZE;
    if (hashTable[pos]) {
        HashNode *pHead = hashTable[pos];
        HashNode *pLast = NULL;
        HashNode *pRemove = NULL;
        while (pHead) {
            if (strcmp(skey, pHead->sKey) == 0) {
                pRemove = pHead;
                break;
            }
            pLast = pHead;
            pHead = pHead->pNext;
        }
        // 如果存在，则删除
        if (pRemove) {
            if (pLast) {
                pLast->pNext = pRemove->pNext;
            }
            else {
                hashTable[pos] = NULL;
            }

            free(pRemove->sKey);
            free(pRemove);
        }
    }
}

/**
 * 根据 key 查找 value
 *
 * @param skey
 * @return value
 */
HashNode *hash_table_lookup(const char *skey) {
    unsigned int pos = hash_table_hash_str(skey) % HASH_TABLE_MAX_SIZE;
    if (hashTable[pos]) {
        HashNode *pHead = hashTable[pos];
        while (pHead) {
            if (strcmp(skey, pHead->sKey) == 0)
                return pHead;
            pHead = pHead->pNext;
        }
    }
    return NULL;
}

/**
 * 打印哈希表
 */
void hash_table_print() {
    printf("===========content of hash table=================\n");
    int i;
    for (i = 0; i < HASH_TABLE_MAX_SIZE; ++i)
        if (hashTable[i]) {
            HashNode *pHead = hashTable[i];
            printf("%d=>", i);
            while (pHead) {
                printf("%s:%d  ", pHead->sKey, pHead->nValue);
                pHead = pHead->pNext;
            }
            printf("\n");
        }
}

/**
 * 释放哈希表
 */
void hash_table_release() {
    int i;
    for (i = 0; i < HASH_TABLE_MAX_SIZE; ++i) {
        if (hashTable[i]) {
            HashNode *pHead = hashTable[i];
            while (pHead) {
                HashNode *pTemp = pHead;
                pHead = pHead->pNext;
                if (pTemp) {
                    free(pTemp->sKey);
                    free(pTemp);
                }

            }
        }
    }
}

/**
 * 随机生成字符串
 *
 * @param r
 */
void rand_str(char r[]) {
    int i;
    int len = MIN_STR_LEN + rand() % (MAX_STR_LEN - MIN_STR_LEN);
    for (i = 0; i < len - 1; ++i)
        r[i] = 'a' + rand() % ('z' - 'a');
    r[len - 1] = '\0';
}

int main(int argc, char **argv) {
    srand(time(NULL));
    hash_table_init();
    printf("insert testing.........\n");
    int n = 10;
    const char *key1 = "aaammd";
    const char *key2 = "xzzyym";
    const char *key3 = "cdcded";

    hash_table_insert(key1, 110);
    hash_table_insert(key2, 220);
    hash_table_insert(key3, 330);
    char str[MAX_STR_LEN + 1];
    while (n--) {
        rand_str(str);
        hash_table_insert(str, n);
    }
    hash_table_print();

    printf("\nlookup testing..........\n");
    HashNode *pNode = hash_table_lookup(key1);
    printf("lookup result:%d\n", pNode->nValue);
    pNode = hash_table_lookup(key2);
    printf("lookup result:%d\n", pNode->nValue);

    printf("\nremove testing..........\n");
    printf("before remove %s:\n", key3);
    hash_table_print();
    hash_table_remove(key3);
    printf("after remove:\n");
    hash_table_print();
    hash_table_release();

    system("pause");
    return 0;
}