/**
 * 最长无重复字串
 */
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    /**
     * 用 map 实现，有问题
     *
     * @param arr int整型vector the array
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

    int maxLength_1(vector<int> &arr) {

    };
}