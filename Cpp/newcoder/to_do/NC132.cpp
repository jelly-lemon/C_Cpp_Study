/*
 * 编号为 1 到 n 的 n 个人围成一圈。从编号为 1 的人开始报数，报到 m 的人离开。
下一个人继续从 1 开始报数。
n-1 轮结束以后，只剩下一个人，问最后留下的这个人编号是多少？
 输入：5,2
 返回值：3
 */

/**
 * 思路 1：使用 vector 来模拟环形
 * 结果运行超时
 */
int ysf(int n, int m) {
    // write code here
    vector<int> v;
    for (int i = 1; i <= n; i++) {
        v.push_back(i);
    }
    int count = 0;
    int start = 0;
    while (count < n-1) {
        int i = 0;
        int step = 0;
        for (int j = start; ; j++) {
            if (j >= n)
                j = 0;
            if (v[j] != 0) {
                step++;
                if (step == m) {
                    count++;
                    v[j] = 0;
                    start = j+1;
                    break;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (v[i] != 0)
            return v[i];
    }
    return 0;
}