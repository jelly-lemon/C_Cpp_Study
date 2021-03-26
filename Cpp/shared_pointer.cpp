/**
 * shared pointer 特点：当没有一个 share pointer 指向目标空间时，这个空间将被释放
 */

#include <vector>
#include <memory>
#include <iostream>

using namespace std;



/**
 * 创建一个 vector，返回 vector 的地址
 */
shared_ptr<vector<int>> newVector() {
    shared_ptr<vector<int>> pVec = make_shared<vector<int>>();

    return pVec;
}

/**
 * 给 vector 赋值
 */
shared_ptr<vector<int>> makeVector(shared_ptr<vector<int>> pVec) {
    pVec->push_back(1);
    pVec->push_back(2);
    pVec->push_back(3);

    return pVec;
}

/**
 * 打印 vector
 */
void printVector(shared_ptr<vector<int>> pVec) {
    for (vector<int>::iterator it = pVec->begin(); it != pVec->end(); it++) {
        cout << *it << " ";    //使用迭代器，正确
    }
}

int main() {
    shared_ptr<vector<int>> pVec = newVector();
    makeVector(pVec);
    printVector(pVec);
    cout << endl;

    cout << "引用计数：" << pVec.use_count() << endl;
    return 0;
}