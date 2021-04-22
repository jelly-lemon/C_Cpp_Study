/**
 * 两数之和
 *
 * 思路 1：
 * 枚举法遍历
 *
 * 【易错点】输入的数字存在负数
 * 我为了节省步骤，用了判断并 continue
 * if (*iter_i > target) continue;
 * 但是存在负数的话，加数是可以大于结果的。
 *
 * 个人评价：【简单】
 * 主要考察 vector 的遍历操作
 */
#include <vector>
using namespace std;

class Solution {
public:
    /**
     *
     * @param numbers int整型vector
     * @param target int整型
     * @return int 整型vector
     */
    vector<int> twoSum(vector<int>& numbers, int target) {
        // write code here
        int i, j;   // i 和 j 分别代表第 1 个数和第 2 个数的下标
        vector<int> result;

        i = 1;
        vector<int>::iterator iter_i = numbers.begin();
        for (; iter_i != numbers.end(); iter_i++, i++) {
            vector<int>::iterator iter_j = iter_i + 1;
            j = i + 1;
            for (; iter_j != numbers.end(); iter_j++, j++) {
                if (*iter_i + *iter_j == target) {
                    result.push_back(i);
                    result.push_back(j);
                    return result;
                }
            }
        }
        return result;
    }
};