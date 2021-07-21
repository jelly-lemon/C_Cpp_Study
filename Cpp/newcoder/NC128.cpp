/*
 * 给定一个整形数组arr，已知其中所有的值都是非负的，将这个数组看作一个容器，请返回容器能装多少水。
 *
 * 输入：（元素大小就是容器高度）
 * [3,1,2,5,2,4]
 *
 * 输出：
 * 5
 */

/**
 * 思路 1：记录每一个元素左边最大值和右边最大值，
 * 那么该元素位置盛水量 = min(左最大，右最大) - 该元素
 *
 * 吐槽一下：运行时间很不稳定，每次提交运行时间都相差很大
 *
 * 运行时间：462ms
超过73.89% 用C++提交的代码
占用内存：43412KB
超过19.68%用C++提交的代码
 */
long long maxWater(vector<int>& arr) {
    // write code here
    if (arr.size() == 0)
        return 0;

    int len = arr.size();
    int leftMax[len];
    int rightMax[len];
    leftMax[0] = rightMax[len-1] = 0;
    for (int i = 1; i < len; i++) {
        leftMax[i] = max(arr[i-1], leftMax[i-1]);
    }
    for (int i = len-1-1; i >= 1; i--) {
        rightMax[i] = max(arr[i+1], rightMax[i+1]);
    }

    long long r = 0;
    for (int i = 1; i < len-1; i++) {
        int t = min(leftMax[i], rightMax[i]) - arr[i];
        if (t > 0)
            r += t;
    }

//         delete[] leftMax, rightMax;
    return r;
}