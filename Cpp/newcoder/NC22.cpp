/*
 给出两个有序的整数数组 A 和 B，请将数组 A 合并到数组 B 中，变成一个有序的数组
注意：
可以假设 A 数组有足够的空间存放 B 数组的元素， A 和 B 中初始的元素数目分别为 m 和 n
 */
/*
 运行时间：3ms
超过54.41%用C++提交的代码
占用内存：504KB
超过28.48%用C++提交的代码
 */
class Solution {
public:
    // 1,3,5,7,9
    // 2,4,6,8,10
    //
    // 9,7,5,3,1
    // 10,8,6,4,2

    // 1,3,5,7,9
    // 10,8,6,4,2

    // 1
    // 2
    // 升序还是降序？
    void merge(int A[], int m, int B[], int n) {
        if (A == NULL or B == NULL)
            return;
        if (m == 0) {
            memcpy(A, B, sizeof(int)*n);
            return;
        }
        if (n == 0)
            return;

        int i, j, k;
        bool aIsAsc = true;
        bool bIsAsc = true;
        if (m > 1) {
            for (i = 1; i < m; i++) {
                if (A[i] < A[i-1]) {
                    aIsAsc = false;
                    break;
                }
            }
        }
        if (n > 1) {
            for (i = 1; i < n; i++) {
                if (B[i] < B[i-1]) {
                    bIsAsc = false;
                    break;
                }
            }
        }
        if (!aIsAsc) {
            for (i = 0; i < m/2; i++) {
                int t = A[i];
                A[i] = A[m-1-i];
                A[m-1-i] = t;
            }
        }
        i = m - 1;
        j = bIsAsc ? n - 1 : 0;
        k = m + n - 1;
        for (int p = k; p >= 0; p--) {
            if (i < 0) {
                A[p] = B[j];
                if (bIsAsc)
                    j--;
                else
                    j++;
                continue;
            }
            if (j < 0 or j >= n) {
                A[p] = A[i];
                i--;
                continue;
            }
            if (A[i] >= B[j]) {
                A[p] = A[i];
                i--;
            } else {
                A[p] = B[j];
                if (bIsAsc)
                    j--;
                else
                    j++;
            }
        }
    }
};