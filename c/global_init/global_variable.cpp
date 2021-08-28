/**
全局变量谁先初始化？

问：a.h 文件中有全局变量 x，b.h 文件中有全局变量 y，
 global_variable.cpp 文件包含了这两个头文件，
如果保证全局初始化的顺序？
答：类 B 的构造函数含有类 A 对象，这样类 B 先初始化时若 A
 还未实例化，会先实例化类 A

问：我如何判断有没有被初始化？
答：在构造函数中 printf
 */
#include "b.h"
#include "a.h"


int main(){

    return 0;
}