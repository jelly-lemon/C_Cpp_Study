#include <string>
using namespace std;

class A {
public:
    static string rootDir;
    static void setRootDir(string dir);
};

void A::setRootDir(string dir) {
    rootDir = dir;
}

// 十分重要!!!类的静态成员变量需要在类外分配内存空间
// 而且前面要加类型，太操蛋了
string A::rootDir;

int main() {


    return 0;
}