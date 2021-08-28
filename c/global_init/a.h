#pragma once

#include<iostream>

using namespace std;
int x;

class A {
public:
    A() {
        x = 5;
        cout << "全局变量 x 初始化" << endl;
    }
};

A g_a;