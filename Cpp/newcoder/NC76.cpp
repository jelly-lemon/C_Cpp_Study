/*
 用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
 */

/*
 运行时间：4ms
超过6.86%用C++提交的代码
占用内存：504KB
超过29.69%用C++提交的代码
 */
class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        if (!stack2.empty()) {
            int n = stack2.top();
            stack2.pop();
            return n;
        } else {
            if (!stack1.empty()) {
                while (!stack1.empty()) {
                    stack2.push(stack1.top());
                    stack1.pop();
                }
                int n = stack2.top();
                stack2.pop();
                return n;
            } else {
                return stack1.top();
            }
        }
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};