/**
 * JZ20 包含min函数的栈
 *
描述
定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数，并且调用 min函数、push函数 及 pop函数 的时间复杂度都是 O(1)
push(value):将value压入栈中
pop():弹出栈顶元素
top():获取栈顶元素
min():获取栈中最小元素

示例:
输入:    ["PSH-1","PSH2","MIN","TOP","POP","PSH1","TOP","MIN"]
输出:    -1,2,1,-1
解析:
"PSH-1"表示将-1压入栈中，栈中元素为-1
"PSH2"表示将2压入栈中，栈中元素为2，-1
“MIN”表示获取此时栈中最小元素==>返回-1
"TOP"表示获取栈顶元素==>返回2
"POP"表示弹出栈顶元素，弹出2，栈中元素为-1
"PSH-1"表示将1压入栈中，栈中元素为1，-1
"TOP"表示获取栈顶元素==>返回1
“MIN”表示获取此时栈中最小元素==>返回-1

示例1
输入： ["PSH-1","PSH2","MIN","TOP","POP","PSH1","TOP","MIN"]
返回值：-1,2,1,-1
 */

/**
运行时间：4ms
超过8.82% 用C++提交的代码
占用内存：544KB
超过25.73%用C++提交的代码
*/
class Solution {
    stack<int> stack1;
    stack<int> minStack;
public:
    void push(int value) {
        stack1.push(value);

        if (!minStack.empty()) {
            int min = minStack.top();
            if (value < min) {
                minStack.push(value);
            } else {
                minStack.push(min);
            }
        } else {
            minStack.push(value);
        }
    }
    void pop() {
        stack1.pop();
        minStack.pop();
    }
    int top() {
        return stack1.top();
    }
    int min() {
        return minStack.top();
    }
};