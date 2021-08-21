/*
 01比
时间限制： 1000MS
内存限制： 65536KB
题目描述：
小明有一个只包含0和1的字符串，现在小明希望将整个字符串尽可能的切割成多个字符串，要求是每个字符串里面0出现的次数和1出现的次数的比例是一致的。解释：假设一个字符串出现0的次数是a次，出现1的次数是b，另一个字符串出现0的次数是c次，出现1的次数是d次，那么这两个字符串01出现次数比例相同表示a:b=c:d，即a*d=b*c。注意这里a,b,c,d都是可以为0的。现在对于一个字符串的所有前缀字符串，输出最多可以切割成多少个符合要求的字符串。



输入描述
第一行一个整数n，表示01字符串的长度，1<=n<=500000

第二行一个长度为n的01字符串。

输出描述
一行n个整数，第i个数表示原字符串中下标由0到i组成的前缀字符串可以切割出多少符合要求的字符串。


样例输入
3
001
样例输出
1 2 1

提示
第一个前缀字符串是0，没法切，答案是1

第二个前缀字符串是00，可以切得到0，0，答案是2

第三个前缀字符串是001，可以切，但是切后没法保证比例要求，因此答案是1



样例2：

输入：

4

0000

输出：

1 2 3 4



样例3：

输入：

4

0101

输出：

1 1 1 2



样例4：

输入：

9

010100001

输出：

1 1 1 2 1 2 1 1 3
 */

#include <iostream>
#include <vector>

using namespace std;


int getZeroNumber(const string &s) {
    int count = 0;
    for (auto &c:s) {
        if (c == '0') {
            count++;
        }
    }

    return count;
}

/**
 * 输入：010100
 *
 *
 * @param s
 * @return
 */
int getMaxSubStrNumber(string &s) {
    if (s.length() == 0 || s.length() == 1) {
        return 1;
    }

    int zeroNumber = getZeroNumber(s);
    if (zeroNumber == s.length()) {
        return zeroNumber;
    } else if (zeroNumber == 0) {
        return s.length();
    }

    for (int subLen = 2; subLen <= s.length()/2; subLen++) {
        if (s.length() % subLen == 0) {
            int maxSubNumber = s.length() / subLen;
            string subStr = s.substr(0, subLen);
            zeroNumber = getZeroNumber(subStr);
            int oneNumber = subStr.length() - zeroNumber;
            int j;
            for (j = 1; j < maxSubNumber; j++) {
                subStr = s.substr(subLen*j, subLen*(j+1));
                int zeroNumber_1 = getZeroNumber(subStr);
                int oneNumber_1 = subStr.length() - zeroNumber_1;
                if (zeroNumber*oneNumber_1 != oneNumber*zeroNumber_1) {
                    break;
                }
            }
            if (j == maxSubNumber) {
                return maxSubNumber;
            }
        }
    }

    return 1;
}

/**
 * AC 9%，其余超时
 */
int main() {
    vector<int> vec;
    int n;
    cin >> n;
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        string subStr = s.substr(0, i+1);
        int n = getMaxSubStrNumber(subStr);
        vec.push_back(n);
    }

    for (auto &n:vec) {
        cout << n << " ";
    }

    return 0;
}