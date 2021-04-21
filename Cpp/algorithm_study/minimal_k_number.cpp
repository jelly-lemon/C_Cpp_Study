/**
 * 牛客网 NC119
 * 最小的 k 个数
 */
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

void printArray(vector<int> &arr) {
    for (int & iter : arr) {
        cout << iter << " ";
    }
    cout << endl;
}

/**
 * 获取最小的 k 个数
 *
 * @param input 输入数组
 * @param k 最小数数量
 * @return 最小的 k 个数组成的数组
 */
vector<int> GetLeastNumbers_1(vector<int> input, int k) {
    vector<int> out;

    if (k > input.size()) {
        return out;
    }

    priority_queue<int ,vector<int>, greater<int> > minHeap;
    vector<int>::iterator iter;
    for (iter = input.begin(); iter != input.end(); iter++) {
        minHeap.push(*iter);
    }

    for (int i = 0; i < k; i++) {
        out.push_back(minHeap.top());
        minHeap.pop();
    }
    return out;
}

void test_0() {
    vector<int> input({4,5,1,6,2,7,3,8});
    GetLeastNumbers_1(input, 4);
}

int main() {
    test_0();


    return 0;
}