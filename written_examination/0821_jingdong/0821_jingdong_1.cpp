/**
 *
对角线上的邻居
时间限制： 1000MS
内存限制： 65536KB
题目描述：
小明搬进了一个新的小区里，对里面的环境和住户都比较陌生，小明发现这个小区的房屋是一个网格型排列，所有房屋在一个网格状的地图上。小区一共有n户人家，我们假设每户人家的位置表示为（x，y）。小明觉得如果两家是邻居的话，他们的关系应该会更好一些。现在我们定义当两户人家处在相同的任意一个对角线上的时候，则两户人家为邻居。现在小明想要统计这样的邻居一共有多少对。



输入描述
第一行1个整数n，0<n<=10^5，表示有n户人家。

接下来n行，第i行包含两个整数xi，yi，0<xi，yi<=1000，表示第i户人家的位置为（xi，yi）。

输出描述
一行一个整数，表示有多少对邻居。


样例输入
5
3 4
4 5
5 6
4 7
3 8
样例输出
6

提示
对于样例输入，以下几对人家均为邻居

（3，4）与（4，5）

（3，4）与（5，6）

（4，5）与（5，6）

（5，6）与（4，7）

（5，6）与（3，8）

（4，7）与（3，8）
*/

#include <iostream>
#include <vector>
#include <map>
#include <list>

using namespace std;

/**
 * 72 %，其余超时
 */
int main() {
    int n;
    list<pair<int, int>> m;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        m.push_back(make_pair(n1, n2));
    }

    int count = 0;
    for (auto iter = m.begin(); iter != m.end(); iter++) {
        auto iter_j = iter;
        for (iter_j++; iter_j != m.end(); iter_j++) {
            int a1 = abs(iter->first - iter_j->first);
            int a2 = abs(iter->second - iter_j->second);
            if (a1 == a2) {
                count++;
            }
        }
    }

    cout << count << endl;
    return 0;
}