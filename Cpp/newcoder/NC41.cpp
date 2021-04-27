/**
 * 最长无重复字串
 *
 * 给定一个数组arr，返回arr的最长无的重复子串的长度(无重复指的是所有数字都不相同)。
 */
#include <map>
#include <vector>
#include <set>
using namespace std;


/**
 * 用 map 实现，超时
 *
 * @param arr int 整型 vector the array
 * @return int整型
 */
int maxLength(vector<int> &arr) {
    // write code here
    vector<int>::iterator iter_i = arr.begin();
    int maxLen = 0;
    for (; iter_i != arr.end(); iter_i++) {
        // 创建一个 map，用来保存子数组
        map<int, int> mymap;
        vector<int>::iterator iter_j = iter_i;
        for (; iter_j != arr.end(); iter_j++) {
            // 如果没在 map 中，就添加到 map 中
            if (mymap.find(*iter_j) == mymap.end()) {
                mymap[*iter_j] = *iter_j;
                if (iter_j + 1 == arr.end()) {
                    if (mymap.size() == arr.size()) {
                        return arr.size();
                    } else {
                        maxLen = maxLen < mymap.size() ? mymap.size() : maxLen;
                    }
                }
            } else {
                // 在 map 中，说明从起点开始，已经到最大长度了。
                maxLen = maxLen < mymap.size() ? mymap.size() : maxLen;
                break;
            }
        }
    }
    return maxLen;
}

/**
 * 暴力法，挨个比对
 */
int maxLength(vector<int> &arr) {

};

/**
 * 使用 set，超时
 */
int maxLength(vector<int> &arr) {
    vector<int>::iterator iter_i = arr.begin();
    int maxLen = 0;
    for (; iter_i != arr.end(); iter_i++) {
        // 创建一个 set，用来保存子数组
        set<int> myset;
        vector<int>::iterator iter_j = iter_i;
        for (; iter_j != arr.end(); iter_j++) {
            // 如果没在 set 中，就添加到 set 中
            if (myset.find(*iter_j) == myset.end()) {
                myset.insert(*iter_j);
                // 遍历到了原数组最后一个元素
                if (iter_j + 1 == arr.end()) {
                    // 判断原数组是不是没有一个数字重复，如果是，可以直接返回了
                    if (myset.size() == arr.size()) {
                        return arr.size();
                    } else {
                        maxLen = maxLen < myset.size() ? myset.size() : maxLen;
                    }
                }
            } else {
                // 在 set 中，说明从起点开始，已经到最大长度了。
                maxLen = maxLen < myset.size() ? myset.size() : maxLen;
                break;
            }
        }
    }
    return maxLen;
};
