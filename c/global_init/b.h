#pragma once
#include<iostream>
#include"a.h"
using namespace std;

extern A a;
extern int x;
int y;
class B {
public:
    B() {
        cout << "B()" << endl;
    }
    B(A) {
        y = x;
        cout << "全局变量y初始化" << endl;
    }
};
B b(a);