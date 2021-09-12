/**
大小端存储判断
*/
#include <iostream>
using namespace std;

/**
 判断是否小端存储
 */
bool isLittleEndian(){
    union U
    {
        int  i;
        char c;
    };
    U u;
    u.i = 0x12345678;
    return u.c == 0x78;
}

int main() {
    if (isLittleEndian()) {
        cout << "isLittleEndian" << endl;
    }
}