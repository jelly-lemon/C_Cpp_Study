/**
 * set 集合
 */

#include <set>
#include <iostream>
using namespace std;

/**
 * 打印 set
 */
void printSet(set<int> &pSet) {
    set<int>::iterator p1 = pSet.begin();
    while (p1 != pSet.end()) {
        cout << *p1 << " ";
        p1++;
    }
    cout << endl;
}

/**
 * 创建 set
 *
 * set 是有序的，unordered_set 才是无序的
 * set 添加元素不是 push，而是 insert
 */
void test_0() {
    set<int> mySet;
    mySet.insert(1);
    mySet.insert(2);
    mySet.insert(3);
    mySet.insert(4);
    mySet.insert(1);    //【知识点】set 不会保存重复的元素
    printSet(mySet);
}

/**
 * 在 set 中查找
 */
void test_1() {
    set<int> mySet;
    mySet.insert(1);
    mySet.insert(2);
    mySet.insert(3);
    mySet.insert(4);
    mySet.insert(1);    //【知识点】set 不会保存重复的元素
    if (mySet.find(1) != mySet.end()) {
        cout << "find 1" << endl;
    } else {
        cout << "can't find 1" << endl;
    }
}

/**
 * 获取当前 set 中元素数量
 */
void test_2() {
    set<int> mySet;
    mySet.insert(1);
    mySet.insert(2);
    mySet.insert(3);
    cout << "size(current number of all elements): " << mySet.size() << endl;
    cout << "max size: " << mySet.max_size() << endl;
}

int main() {
    test_0();

    return 0;
}