/*
 * 怎么观察智能指针什么时候调用了析构函数？
 */
#include <vector>
#include <memory>
#include <iostream>

using namespace std;

/**
 * 创建一个 vector
 *
 * @return
 */
shared_ptr<vector<int>> newVector() {
    shared_ptr<vector<int>> vec = make_shared<vector<int>>();

    return vec;
}

/**
 * 给 vector 赋值
 *
 * @param vec
 * @return
 */
shared_ptr<vector<int>> makeVector(shared_ptr<vector<int>> vec) {
    int a;
    cin >> a;
    while (a) {
        vec->push_back(a);
        cin >> a;
    }
    return vec;
}

/**
 * 打印 vector
 *
 * @param vec
 */
void getVector(shared_ptr<vector<int>> vec) {
    // 写法 1
    for (vector<int>::iterator it = vec->begin(); it != vec->end(); it++) {
        cout << *it << " ";    //使用迭代器，正确
    }

    // 写法 2
//    for (int & it : *vec) {
//        cout << it << " ";
//    }


}

int main() {
    getVector(makeVector(newVector()));

    return 0;
}