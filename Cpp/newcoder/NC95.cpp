/**
    运行时间：36ms
超过96.53% 用C++提交的代码
占用内存：4072KB
超过69.97%用C++提交的代码

 【易错】 1,2,2,3,4,5 中有序序列：2, 3, 4, 5

 思路：先排序，再去重，最后找有序序列
     * max increasing subsequence
     * @param arr int整型vector the array
     * @return int整型
     */
int MLS(vector<int>& arr) {
    if (arr.empty()) {
        return 0;
    }
    sort(arr.begin(), arr.end());
    vector<int> newArr;
    newArr.push_back(arr[0]);
    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] != newArr.back()) {
            newArr.push_back(arr[i]);
        }
    }


    int maxLen = 1;
    int t_max = 1;
    for (int i = 1; i < newArr.size(); i++) {
        if (newArr[i] - 1 == newArr[i-1]) {
            t_max++;
            if (maxLen < t_max) {
                maxLen = t_max;
            }
        } else {
            t_max = 1;
        }
    }

    return maxLen;
}