/**
     * 运行时间：3ms
超过54.87% 用C++提交的代码
占用内存：444KB
超过39.23%用C++提交的代码
     */
vector<int> FindNumsAppearOnce(vector<int>& array) {
    // write code here
    unordered_map<int, int> hashTab;
    vector<int> rt;

    for (auto &n:array) {
        if(hashTab.find(n) == hashTab.end()) {
            hashTab[n] = 1;
        } else {
            hashTab[n]++;
        }
    }
    for (auto &n:array) {
        if (hashTab[n] == 1) {
            rt.push_back(n);
        }
    }

    sort(rt.begin(), rt.end(), less<int>());

    return rt;
}