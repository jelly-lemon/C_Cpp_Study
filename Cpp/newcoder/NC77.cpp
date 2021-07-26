/**
    * 运行时间：14ms
超过33.67% 用C++提交的代码
占用内存：1936KB
超过1.14%用C++提交的代码
    */
vector<int> reOrderArray(vector<int>& array) {
    // write code here
    vector<int> v1, v2;
    for (auto &n:array) {
        if (n % 2 == 1) {
            v1.push_back(n);
        } else {
            v2.push_back(n);
        }
    }
    for (auto &n:v2) {
        v1.push_back(n);
    }


    return v1;
}