#include <vector>
#include <iostream>
using namespace std;

void print_vector(vector<int> v) {
    for (vector<int>::iterator it=v.begin(); it != v.end(); it++) {
        cout << *it << " ";
    }
}

/**
 * 列表的创建
 */
void test_1() {
    // 容量为 10
    vector<int> v1(10);
    print_vector(v1);
    cout << endl;

    // 容量，每个元素初始值
    vector<int> v2(10, 1);
    print_vector(v2);
    cout << endl;

    // 从数组中获取值
    int a[] = {1,2,3,4,5};
    vector<int> v3(a, a+5);
    print_vector(v3);
    cout << endl;
}


/**
 * 插入元素，容量不足时，容量乘2扩大
 */
void test_2() {
    int a[10] = {4,5,6,3,1,2,9,8,7,0};

    vector<int> v1(10, 1);
    cout << "v1 " << "size:" << v1.size() << " capacity:" << v1.capacity() << endl;

    // 末尾插入元素
    v1.push_back(5);
    cout << "v1 " << "size:" << v1.size() << " capacity:" << v1.capacity() << endl;

    // 插入一个数组
    v1.insert(v1.end(), a, a+10);
    cout << "v1 " << "size:" << v1.size() << " capacity:" << v1.capacity() << endl;

    v1.push_back(6);
    v1.push_back(7);
    cout << "v1 " << "size:" << v1.size() << " capacity:" << v1.capacity() << endl;
}


int main() {
    test_2();

    return 0;
}