/**
 * 相邻列之差的和的最小值

给三个长度为 n 的数组,每 1 列选 1 个数，求相邻列之差绝对值的和的最小值

输入案例
5   9   5   4   4
4   7   4   10  3
2   10  9   2   3

这里选择 5 7 5 4 4.所以输出等于 |7-5|+|5-7|+|4-5|+|4-4|=5 所以输出就是 5。
 */
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

 /**
  * 枚举法，递归结构
  *
  * @param p 指针数组
  * @param len 数组长度
  * @param j 当前要遍历的列
  * @param r 累加和
  * @param lastNum 上一列遍历的数
  * @param s 输出字符串
  */
void enum_1(int *p[3], int len, int j, int r, int lastNum, string s) {
    int i;

    // 遍历到最后一列
    if (j == len-1) {
        for (i = 0; i < 3; i++) {
            int t =  r;
            t += abs(p[i][j] - lastNum);    // 绝对值只差累加
            char msg[20];
            snprintf(msg, 20, "|%d-%d|=%d", p[i][j], lastNum, t);
            cout << s << msg << endl;
        }
    } else {
        // 遍历到元 j 列
        for (i = 0; i < 3; i++) {
            string tStr;
            int t = r;
            if (j == 0) {

            } else {
                t += abs(p[i][j] - lastNum);    // 绝对值只差累加
                char msg[20];
                snprintf(msg, 20, "|%d-%d|+", p[i][j], lastNum);
                tStr = s + msg;
            }
            enum_1(p, len, j+1, t, p[i][j], tStr);         // 遍历下一列
        }

    }
}

void test_1() {
    int a1[5] = {5, 9, 5, 4, 4};
    int a2[5] = {4, 7, 4, 10, 3};
    int a3[5] = {2, 10, 9, 2, 3};

    int len = 5;

    int *p[3] = {a1, a2, a3};
    enum_1(p, len, 0, 0, 0, "");
}

int main() {
    test_1();

    return 0;
}