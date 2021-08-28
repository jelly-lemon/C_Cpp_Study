/**
 * 实现堆，时间复杂度：O(n)
 *


如果写成下面这种形式，时间复杂度就是 O(nlogn)：

// 将 arr[n] 向上调整至合适位置
void AdjustHeap(vector<int> &arr, int n)
{
    if(n<=0) return ;
    // 如果子节点比父节点大
    if(arr[(n-1)/2] > arr[n]) {
        swap(arr[(n-1)/2], arr[n]);
        AdjustHeap(arr, (n-1)/2);   //递归调整
    }
}
// 小根堆
void BuildHeap(vector<int> &arr)
{
    for(int i=1; i<arr.size(); i++) {
        AdjustHeap(arr, i);
    }
}
 */
#include <vector>
#include <iostream>
using namespace std;

void print(vector<int> &arr)
{
    for(auto n: arr) printf("%d\t", n);
    cout<<endl;
}

// 以arr[n]为根的子树，将arr[n]向下调整至合适位置
void Heapify(vector<int> &arr, int size, int n)
{
    int L = n*2+1, R = L+1;
    if(L>=size) return ;//无孩

    int big = arr[L];         // 取两孩之大者
    if(R<size) big = max(big, arr[R]);

    if(arr[n]>=big) return ;  //无需调整

    int c = L;      // 欲与父交换位置的孩子
    if(big!=arr[L]) c = R;
    swap(arr[n], arr[c]);
    Heapify(arr, size, c);
}

// 小根堆
void BuildHeap(vector<int> &arr)
{
    int last = (arr.size()-1)/2;
    for(int i=last; i>=0; i--) {
        Heapify(arr, arr.size(), i);
    }
}
// 顺便排序
void Sort(vector<int> &arr)
{
    int size = arr.size();
    for(int i=size-1; i>0; i--) {
        swap(arr[0], arr[i]);
        Heapify(arr, i, 0); //调整一下arr[0]
    }
}

int main()
{
    vector<int> vect{9, 10, 6, 3, 1, 6, 2, 8, 4};
    print(vect); //排序前
    BuildHeap(vect); //建堆
    Sort(vect);  //排序
    print(vect); //排序后
    return 0;
}