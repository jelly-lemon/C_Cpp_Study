/*
有一个整数数组，请你根据快速排序的思路，找出数组中第K大的数。
给定一个整数数组a,同时给定它的大小n和要找的K(K在1到n之间)，请返回第K大的数，保证答案存在。
 */

/*
 运行时间：3ms
超过60.70%用C++提交的代码
占用内存：480KB
超过73.43%用C++提交的代码
 */
int findKth(vector<int> a, int n, int K) {
    // write code here
    priority_queue<int, vector<int>, less<int> > maxHeap;
    for (int &n : a) {
        maxHeap.push(n);
    }
    for (int i = 0; i < K-1; i++) {
        maxHeap.pop();
    }
    return maxHeap.top();
}