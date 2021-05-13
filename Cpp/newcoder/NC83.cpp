/**
 * 给定一个double类型的数组arr，其中的元素可正可负可0，返回子数组累乘的最大乘积。
 */

#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;



void printVector(vector<double> &arr) {
    for (double &a:arr) {
        printf("%6.2f ", a);
    }
    cout << endl;
}

/**
 * 动态规划
 */
double maxProduct(vector<double> arr) {
    printVector(arr);


    return 0;
}


/**
 * 暴力法
 */
double maxProduct_1(vector<double> arr) {
    printVector(arr);


    return 0;
}


void test_0() {
    vector<double > v1 = {-1, -2, -3, -4};
    vector<double> v2 = {0, 0, 0, 0};
    vector<double> v3 = {1, 2, 3, 4};
    vector<double> v4 = {-1, 2, -3, 4};
    vector<double> v5 = {0, 0.5, -3, 4};
    vector<double> v6 = {3, 0.5, 0.4, 0.6, 9};
    vector<double> v7 = {3, -1, -2, 4};
    vector<double> v8 = {1, 3, -1, -2, -3, 2, 4};   // 48


    maxProduct(v1);
    maxProduct(v2);
    maxProduct(v3);
    maxProduct(v4);
    maxProduct(v5);
    maxProduct(v6);
    maxProduct(v7);
    maxProduct(v8);
}

void test_1() {

}



int main() {


    return 0;
}