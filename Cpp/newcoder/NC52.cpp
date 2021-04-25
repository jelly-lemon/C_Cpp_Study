/*
题目描述
给出一个仅包含字符'(',')','{','}','['和']',的字符串，判断给出的字符串是否是合法的括号序列
括号必须以正确的顺序关闭，"()"和"()[]{}"都是合法的括号序列，但"(]"和"([)]"不合法。
 */
#include <iostream>
#include <stack>
#include <map>

using namespace std;

void printStack(stack<char> yourStack) {

}

/**
 *
 * @param s string字符串
 * @return bool布尔型
 */
bool isValid(string s) {
    // write code here
    stack<char> mystack;
    map<char, char> mymap;
    mymap['('] = ')';
    mymap['{'] = '}';
    mymap['['] = ']';

    for (char & iter : s) {
        // 如果是左括号，就压栈
        if (iter == '(' or iter == '{' or iter == '[') {
            mystack.push(iter);
        } else {
            // 【易错点】要先判断栈是否为空
            if (!mystack.empty()) {
                // 如果是右括号，就取栈顶元素，看是否匹配
                if (iter == mymap[mystack.top()]) {
                    mystack.pop();
                } else {
                    return false;
                }
            } else {
                return false;
            }
        }
    }
    return mystack.empty();
}

int main() {


    return 0;
}

