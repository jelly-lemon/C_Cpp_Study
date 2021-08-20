#include <stdio.h>
#include <stdlib.h>
/**
 calloc 在动态分配完内存后，自动初始化该内存空间为零，
 而 malloc 不做初始化，分配到的空间中的数据是随机数据。
 */
void test_0() {
    // 对象个数，对象长度
    int *p = (int*)calloc(1, 4);
    printf("%d\n", *p);
}

/**
 realloc

 - 原有空间后面有足够大小的空间：直接追加空间，原来空间的数据不发生变化
 - 原有空间之后没有足够多的空间时：在堆空间上另找一个合适大小的连续空间来使用。这样函数返回的是一个新的内存地址。

 不安全的原因：
 如果申请内存失败，realloc 会返回返回 NULL。
 但是 ptr 的内存是没有被释放的。如果直接将 realloc 的返回值赋给 ptr。
 那么当申请内存失败时，就会造成ptr原来指向的内存丢失，造成内存泄露。
 */
void test_1() {
    int*ptr = malloc(100*sizeof(int));
    // 申请失败返回 NULL
    ptr = realloc(ptr, 1000*sizeof(int));//这样可以吗？(如果申请失败会如何？)
}


int main() {
    test_0();

    return 0;
}