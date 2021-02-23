/*
 * 实现一个 string 类
 */

#include <iostream>
#include <cstring>
using namespace std;

class String {
public:
    // 普通构造函数
    String(const char *str = NULL);
    // 拷贝构造函数
    String(const String &other);
    // 赋值函数
    String &operator = (String &other);
    // 析构函数
    ~String();

    // 重载 << 运算符
    friend ostream &operator<<(ostream &out, const String &str);

private:
    char* m_str;
};

ostream & operator<<(ostream &out, const String &str) {
    out << str.m_str;
    return out;
}

String::String(const char *str) {
    //如果str为NULL，存空字符串
    if(str == NULL) {
        m_str = new char[1]; //分配一个字节
        *m_str = '\0';      //赋一个’\0′
    } else {
        m_str = new char[strlen(str) + 1];    //分配空间容纳str内容
        strcpy(m_str, str);     //复制str到私有成员m_str中
    }
}

String::~String() {
    // 如果m_str不为NULL，释放堆内存
    if(m_str != NULL) {
        cout << "[" << this << "]" <<  " ~String(): " << m_str << endl;
        delete [] m_str;
        m_str = NULL;
    }
}


String::String(const String &other){
    m_str = new char[strlen(other.m_str)+1]; //分配空间容纳str内容
    strcpy(m_str, other.m_str); //复制other.m_str到私有成员m_str中
}


String& String::operator=(String &other){
    //若对象与other是同一个对象，直接返回本{
    if(this == &other) {
        return *this;
    } else {
        delete [] m_str; //否则，先释放当前对象堆内存
        m_str = new char[strlen(other.m_str)+1]; //分配空间容纳str内容
        strcpy(m_str, other.m_str); //复制other.m_str到私有成员m_str中
        return *this;
    }

}

int main() {
    String s("hello");
    String s1("world");

    s = s1;
    cout << s << endl;

    return 0;
}