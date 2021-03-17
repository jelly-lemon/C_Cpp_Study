/*
 * 重载运算符
 */
#include <stdio.h>
#include <iostream>
using namespace std;

class Point {

public:
    int x, y;

    Point() {

    };

    Point(int x, int y) {
        this->x = x;
        this->y = y;
    };

    /**
     * 形参一定要是引用。如果是复制传递，浪费时间和空间
     *
     * @param a
     * @return
     */
    Point operator+(const Point &a) {
        Point t;
        t.x = this->x + a.x;
        t.y = this->y + a.y;
        return t;
    };
};

/**
 * 输入运算符重载，如果要访问 Point 的私有变量，那么应该把该函数定义成友元函数
 *
 * @param out 就是 << 左边的参数，cout
 * @param p
 * @return out 的引用，方便后面继续用 << 输出
 */
ostream &operator<<(ostream &out, Point &p) {
    cout << "x=" << p.x << ", y=" << p.y;
    return out;
}


int main() {
    Point a(1, 3);
    Point b(2, 5);

    // 相当于调用 c 的 operator+ 函数
    Point c = a+b;  // 返回一个新的对象

    printf("x=%d, y=%d\n", c.x, c.y);

    cout << c << endl;

    return 0;
}