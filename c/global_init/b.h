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
        cout << "ȫ�ֱ���y��ʼ��" << endl;
    }
};
B b(a);