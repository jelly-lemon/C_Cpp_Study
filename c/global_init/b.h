#pragma once
#include<iostream>
#include "a.h"
using namespace std;

int y;

class B {
public:
    B(A &a) {
        y = 9;
        cout << "全局变量 y 初始化" << endl;
    }
};

// 类 B 实例化时依赖类 A 对象
B b(g_a);