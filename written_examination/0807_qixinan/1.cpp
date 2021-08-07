/*
 * 挑选芭蕾舞演员，3 人一组，身高要么 height[j] > height[k] > height[l] 要么
height[j] < height[k] < height[l]

 身高不会出现重复。
 演员可以在多个小组。

 输入：
 [1,5,3,2,4]

 输出：
 3

 解释：
 可以组件 3 个小队：(1,3,4),(5,3,2), (1,2,4)
 */

/**
 * 思路 1：枚举法
 */
int TeamNums(vector<int>& height) {
    int len = height.size();
    int count = 0;
    for (int i = 0; i < len; i++) {
        for (int j = i + 1; j < len; j++) {
            for (int k = j + 1; k < len; k++) {
                if ((height[i] < height[j] && height[j] < height[k]) ||
                    height[i] > height[j] && height[j] > height[k]) {
                    count++;
                }
            }
        }
    }
    return count;
}