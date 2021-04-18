/**
 * 【空类大小问题】
 * 一个空的类或结构体，占多少字节（指实例化出来的对象）？
 * 空类和空字节：占 1 个字节
 * 即使空类带上空构造函数和空析构函数，仍然占 1 个字节
 *
 * 我们平常所说类型的大小，是指用这个类型实例化出来的对象所占空间大小。
 */
#include <iostream>
using namespace std;

class EmptyClass{

};

struct EmptyStruct {

};

class EmptyClass_1 {
public:
    EmptyClass_1();
};

EmptyClass_1::EmptyClass_1() {

}


class EmptyClass_2 {
public:
    EmptyClass_2();
    ~EmptyClass_2();
};

EmptyClass_2::EmptyClass_2() {

}

EmptyClass_2::~EmptyClass_2() {

}

int main() {
    cout << "EmptyClass:" << sizeof(EmptyClass) << endl;
    cout << "EmptyClass_1:" << sizeof(EmptyClass_1) << endl;
    cout << "EmptyClass_2:" << sizeof(EmptyClass_2) << endl;
    cout << "EmptyStruct:" << sizeof(EmptyStruct) << endl;

    return 0;
}