
/**
 * 102, 3
   1023, 3102
 */
struct cmp_greater {
    bool operator()(int a, int b) {
        string s1 = to_string(a);
        string s2 = to_string(b);
        string s3 = s1 + s2;
        string s4 = s2 + s1;

        return s3 > s4;
    }
};
/**
 * 最大数
 * @param nums int整型vector
 * @return string字符串
 */
string solve(vector<int>& nums) {
    // write code here
    cmp_greater g;
    sort(nums.begin(), nums.end(), g);
    string s;
    for (auto &n:nums) {
        s += to_string(n);
    }
    // 针对 0,0 这种输入
    if (s[0] == '0') {
        s = "0";
    }

    return s;
}