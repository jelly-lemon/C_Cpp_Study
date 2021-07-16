/**
 * 吐槽：以前学习 C 语言的时候课本上有这道题，但是现在却忘记怎么做的了。。。好像有个什么逆波兰式？
 * （原来是数据结构这门课）
 *
 * 前缀表达式 == 波兰式
 * 中缀表达式：我们平常用的表达式
 * 后缀表达式 == 逆波兰式
 * 波兰表达式和逆波兰表达式有个好处，就算将圆括号去掉也没有歧义。
 *
 * 中缀表达式a + b*c + (d * e + f) * g，其转换成后缀表达式则为a b c * + d e * f  + g * +。

 中缀转后缀：
 遇到数字 --> 输出；
 遇到 + - --> 出栈并输出，直到遇到 ( 或者栈空停止；
 遇到 * / --> 压入栈；
 遇到 ( --> 压入栈；
 遇到 ) --> 依次出栈并输出，直到将 ( 出栈；【注意】( 不输出
 遍历完毕 --> 出栈并输出，直到栈为空。


 根据逆波兰式求解表达式过程：
 遍历逆波兰式，遇到数字 -> 压栈，遇到操作符 -> 取栈顶两个数字进行运算 -> 结果压栈；
 遍历完毕，栈顶就是表达式结果。
 *
 * 请写一个整数计算器，支持加减乘三种运算和括号。
 * 输入："1+2"
 * 返回值：3
 */
#include<string>
#include<stack>
#include<vector>
#include <stdexcept>
#include <map>
#include <iostream>
#include <sstream>
using namespace std;

string getString(char c) {
    string s;
    stringstream stream;
    stream << c;
    s = stream.str();

    return s;
}

/**
 * 前缀转后缀
 */
vector<string> getPostfixExpression(string s) {
    //
    // 定义运算符优先级
    //
    map<char, int> level;
    level['+'] = 1;
    level['-'] = 1;
    level['*'] = 2;
    level['/'] = 2;
    level['('] = 3;

    //
    // 遍历中缀表达式
    //
    stack<char> myStack;
    vector<string> postfixExpression;
    for (int i = 0; i < s.length(); i++) {
        //
        // 数字
        //
        if ('0' <= s[i] && s[i] <= '9') {
            int start = i;
            i++;
            while (i < s.length()) {
                if ('0' <= s[i] && s[i] <= '9') {
                    i++;
                } else {
                    break;
                }
            }
            int end = i;
            string num = s.substr(start, end-start);
            postfixExpression.push_back(num);
            i--;
        } else {
            //
            // 运算符
            //
            switch (s[i]) {
                case '+':
                case '-':
                    //
                    // 弹出比自己优先级高的
                    //
                    while(!myStack.empty()) {
                        char op = myStack.top();
                        if (op == '(') {
                            break;
                        } else if (level[s[i]] <= level[op]) {
                            myStack.pop();
                            postfixExpression.push_back(getString(op));
                        }
                    }
                    myStack.push(s[i]);
                    break;
                case '*':
                case '(':
                    myStack.push(s[i]);
                    break;
                case ')':
                    char op;
                    while ((op = myStack.top()) != '(') {
                        postfixExpression.push_back(getString(op));
                        myStack.pop();
                    }
                    myStack.pop();
                    break;
                default:
                    string msg = "unknown op: " + s.substr(i, 1);
                    throw invalid_argument(msg);
            }
        }
    }


    //
    // 如果栈中还有数据
    //
    while(!myStack.empty()) {
        char op = myStack.top();
        myStack.pop();
        postfixExpression.push_back(getString(op));
    }

    return postfixExpression;
}

/**
 * 根据后缀表达式求值
 */
int getExpressionResult(vector<string> postfixExpression) {
    stack<int> numStack;
    for (auto &s : postfixExpression) {
        if (s == "+" || s == "-" || s == "*" || s == "/") {
            int n2 = numStack.top();
            numStack.pop();
            int n1 = numStack.top();
            numStack.pop();
            int rt = 0;
            if (s == "+") {
                rt = n1 + n2;
            } else if(s == "-") {
                rt = n1 - n2;
            } else if(s == "*") {
                rt = n1 * n2;
            }
            numStack.push(rt);
        } else {
            int n = atoi(s.c_str());
            numStack.push(n);
        }
    }

    return numStack.top();
}

/**
 * 运行时间：4ms
超过13.95% 用C++提交的代码
占用内存：380KB
超过53.01%用C++提交的代码

 * 输入的是字符串，并且数字还可以大于 1 位数
 */
int solve(string s) {
    vector<string> postfixExpression = getPostfixExpression(s);
    int n = getExpressionResult(postfixExpression);

    return n;
}


void test_0() {
    vector<string> postfixExpression = getPostfixExpression("1+2*3+(4*5+6)*7");
    for (auto &s : postfixExpression) {
        cout << s << " ";
    }
    cout << endl;

    int n = getExpressionResult(postfixExpression);
    cout << "rt: " << n << endl;
}

int main() {
    test_0();

    return 0;
}
