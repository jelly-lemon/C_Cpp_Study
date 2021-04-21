/**
 * 重载运算符
 * 实现复制构造函数
 */
#include <cstdio>
#include <iostream>
using namespace std;

class Point {
    int x, y;

public:
    // 声明友元函数，该函数可以访问对象的私有变量
    friend ostream& operator<<(ostream &out, Point &p);

    Point():x(0), y(0) {
        cout << "new Point (" << x << "," << y << ")" << endl;
    };

    Point(int x, int y) {
        cout << "new Point (" << x << "," << y << ")" << endl;
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
        printf("this is (%d, %d)\n", x, y);
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

    /**
     * 当类中没有定义拷贝构造函数的时候，编译器会默认提供一个拷贝构造函数，进行成员变量之间的拷贝。
     * 拷贝构造函数参数必须是引用类型，这是编译器强制要求，否则会递归调用复制构造函数
     * 【易错点】推荐加上 const，避免意外修改原对象。但是 C++11 强制要求加上，
     * 不然提示 expects an l-value for 1st argument，即实参得是一个左值
     * 【知识点】成员函数可以访问本类对象的私有变量
     */
    Point(const Point &p):x(p.x), y(p.y) {

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
    Point c = a+b;  // 返回一个新的对象，然后复制给 c

    printf("x=%d, y=%d\n", c.getX(), c.getY());

    cout << c << endl;
}


int main() {
    test_0();

    return 0;
}