/**
 * 描述
在一个长度为n的数组里的所有数字都在0到n-1的范围内。 数组中某些数字是重复的，但不知道有几个数字是重复的。也不知道每个数字重复几次。请找出数组中任一一个重复的数字。 例如，如果输入长度为7的数组[2,3,1,0,2,5,3]，那么对应的输出是2或者3。存在不合法的输入的话输出-1
示例1
输入：
[2,3,1,0,2,5,3]

 返回值：2
说明：2或3都是对的
 */

/**
     * 运行时间：8ms
超过29.77% 用C++提交的代码
占用内存：940KB
超过16.34%用C++提交的代码
     */
int duplicate(vector<int>& numbers) {
    // write code here
    unordered_set<int> hashSet;
    for (auto &n:numbers) {
        if (n < 0 || n > numbers.size() -1) {
            return -1;
        }
        if (hashSet.find(n) != hashSet.end()) {
            return n;
        } else {
            hashSet.insert(n);
        }
    }

    return -1;
}