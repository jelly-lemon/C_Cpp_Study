/**
 * 第二个 0 变为 1
 *
 * 输入：10  即 (1010)2
 * 输出：14  即 (1110)2
 */

#include <iostream>
#include <stack>

using namespace std;

/**
 * AC
 *
 *
 */
int changeNumber(int num) {
    stack<int> myStack;
    // write code here
    int targetP;
    int n = num;
    int count = 0;
    int rightLen;
    for (rightLen = 0; rightLen < sizeof(int)*8; rightLen++) {
        // 【易错点】 n & 1 == 0 写法错误， == 优先级高于 &
        if ((n & 1) == 0) {
            count++;
            if (count == 2) {
                break;
            }
        }
        n = n >> 1;
    }

    // 第二个 0 变为 1
    n += 1;

    // 右边归位
    for (int i = 0; i < rightLen; i++) {
        if ((num & 1) == 1) {
            myStack.push(1);
        } else {
            myStack.push(0);
        }
        num = num >> 1;
    }
    while (!myStack.empty()) {
        n = n << 1;
        if (myStack.top() == 1) {
            n += 1;
        }
        myStack.pop();
    }

    return n;
}

int main() {
    int rt = changeNumber(10);

    cout << rt << endl;

    return 0;
}