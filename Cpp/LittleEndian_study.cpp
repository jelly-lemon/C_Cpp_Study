/**
大小端存储判断
*/
#include <iostream>
#include <cstdio>
using namespace std;

/**
 判断是否小端存储
 小端存储：从内存的低地址开始，先存储数据的低序字节再存高序字节。简言之，高字节存高地址！
 原理：
 在栈中申请一个共用体变量。栈中由高地址向低地址扩张；
 c 是 int 的第一个字节，也就是高字节。
 */
bool isLittleEndian(){
    union U
    {
        int  i;
        char c;
    };
    U u1, u2;
    // 【注意】一个地址对应一个字节
    printf("%#x\n", &u1.c);
    printf("%#x\n", &u2.c);

    u1.i = 0x12345678;
    return u1.c == 0x78;
}

int main() {
    if (isLittleEndian()) {
        cout << "isLittleEndian" << endl;
    }
}