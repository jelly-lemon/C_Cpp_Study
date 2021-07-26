/**
* 描述
给出一组可能包含重复项的数字，返回该组数字的所有排列。

示例1
输入：
[1,1,2]

返回值：
[[1,1,2],[1,2,1],[2,1,1]]

 【难点】：用回溯法的话，怎么得出该节点下面的子节点是哪些？
*/


void dfs(vector<int> &num, vector<vector<int> > &rt, vector<bool> visited, vector<int> newVec) {
    if (newVec.size() == num.size()) {
        rt.push_back(newVec);
        return;
    }
    for (int i = 0; i < num.size(); i++) {
        if (visited[i]) {
            continue;
        }
        // 【难点】同一层相同元素，不能再次进入，判断条件容易分不清
        if (i > 0 && num[i] == num[i-1] && visited[i-1] == true) {
            continue;
        }
        newVec.push_back(num[i]);
        visited[i] = true;
        dfs(num, rt, visited, newVec);
        newVec.pop_back();
        visited[i] = false;
    }
}

/**
运行时间：6ms
超过55.14% 用C++提交的代码
占用内存：556KB
超过69.90%用C++提交的代码
*/
vector<vector<int> > permuteUnique(vector<int> &num) {
    vector<int> newVec;
    vector<vector<int> > rt;
    sort(num.begin(), num.end());
    vector<bool> visited(num.size(), false);

    dfs(num, rt, visited, newVec);

    return rt;
}