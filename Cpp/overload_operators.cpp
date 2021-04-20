/**
 * 重载运算符
 */
#include <cstdio>
#include <iostream>
using namespace std;

class Point {
    int x, y;

public:
    // 声明友元函数，该函数可以访问对象的私有变量
    friend ostream& operator<<(ostream &out, Point &p);

    Point() {
        cout << "new Point" << endl;
    };

    Point(int x, int y) {
        this->x = x;
        this->y = y;
    };

    /**
     * 形参一定要是引用。【优化点】如果是复制传递，浪费时间和空间
     *
     * @param a 加号右边的对象
     * @return 相加后的新对象
     */
    Point operator + (const Point &a) {
        cout << "this is x=" << this->x << ", y=" << this->y << endl;
        Point t;
        t.x = this->x + a.x;
        t.y = this->y + a.y;
        return t;
    };

    int getX() {
        return x;
    }

    int getY() {
        return y;
    }
};

/**
 * 输出运算符重载，如果要访问 Point 的私有变量，那么应该把该函数定义成友元函数
 *
 * @param out 就是 << 左边的参数，cout
 * @param p 对象
 * @return out 的引用，方便后面继续用 << 输出
 */
ostream& operator << (ostream &out, Point &p) {
    cout << "x=" << p.x << ", y=" << p.y;
    return out;
}

void test_0() {
    Point a(1, 3);
    Point b(2, 5);

    // 相当于调用 a 的 operator+ 函数
    Point c = a+b;  // 返回一个新的对象

    printf("x=%d, y=%d\n", c.getX(), c.getY());

    cout << c << endl;
}


int main() {
    test_0();

    return 0;
}