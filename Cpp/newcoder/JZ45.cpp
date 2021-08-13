/**
 * 扑克牌顺子
 *
* 描述
现在有2副扑克牌，从扑克牌中随机五张扑克牌，我们需要来判断一下是不是顺子。
有如下规则：
1. A为1，J为11，Q为12，K为13，A不能视为14
2. 大、小王为 0，0可以看作任意牌
3. 如果给出的五张牌能组成顺子（即这五张牌是连续的）就输出true，否则就输出false。
例如：给出数据[6,0,2,0,4]
中间的两个0一个看作3，一个看作5 。即：[6,3,2,5,4]
这样这五张牌在[2,6]区间连续，输出true
数据保证每组5个数字，每组最多含有4个零，数组的数取值为 [0, 13]

示例 1
输入：[6,0,2,0,4]
返回值：true

 示例 2
输入：[0,3,2,6,4]
返回值：true

 示例 3
输入：[1,0,0,1,0]
返回值：false

 示例 4
输入：[13,12,11,0,1]
返回值：false
*/

/**
 * 思路：有重复的肯定不是。
 *
 * 最大值 - 最小值 < 5 即可。
 *
    运行时间：5ms
超过3.07% 用C++提交的代码
占用内存：620KB
超过13.45%用C++提交的代码
*/
bool IsContinuous( vector<int> numbers ) {
    set<int> mySet;

    int min = -1, max = -1;
    for (int i = 0; i < numbers.size(); i++) {
        int n = numbers[i];
        if (n != 0) {
            if (min == -1) {
                max = min = n;
            } else {
                if (n > max) {
                    max = n;
                }
                if (n < min) {
                    min = n;
                }
            }
            if (mySet.find(n) == mySet.end()) {
                mySet.insert(n);
            } else {
                return false;
            }
        }

    }

    if (max - min < 5) {
        return true;
    }

    return false;
}