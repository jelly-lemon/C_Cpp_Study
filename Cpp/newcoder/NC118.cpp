/*
 * 数组中的逆序对
 在数组中的两个数字，如果前面一个数字大于后面的数字，则这两个数字组成一个逆序对。输入一个数组,求出这个数组中的逆序对的总数P。并将P对1000000007取模的结果输出。 即输出P%1000000007

对于50\%50%的数据,size\leq 10^4size≤10
4

对于75\%75%的数据,size\leq 10^5size≤10
5

对于100\%100%的数据,size\leq 2*10^5size≤2∗10
5
 题目保证输入的数组中没有的相同的数字
 */
/*
 运行时间：1327ms
超过0.33%用C++提交的代码
占用内存：2716KB
超过97.63%用C++提交的代码
 */
int InversePairs(vector<int> data) {
    long long count = 0;
    int len = data.size();
    for (int i = 0; i < len; i++) {
        for (int j = i+1; j < len; j++) {
            if (data[i] > data[j])
                count++;
        }
    }
    return count%1000000007;
}