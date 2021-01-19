//
// Created by lemon local on 2020/7/17.
//
#include <stdio.h>
#include <string.h>
#define N 100


//void swap(int a, int b) {
//    int t;
//    t = a;
//    a = b;
//    b = t;
//}
//int c;
//int main(void) {
//    void test();
//
//
//    test();
//
//
//
//    return 0;
//}


//void swap_2(int *p1, int *p2) {
//    int t;
//    t = *p1;
//    *p1 = *p2;
//    *p2 = t;
//}

//
//void test() {
//    c = 1;
//}
//
int main(void) {
    int binarySearch_1(int num[], int numSize, int target);

    int num[] = {-1, 100, 95, 67, 56, 44, 39, 37, 25, 23, 19, 17, 15, 9, 6, 4};
    int n = 11;

    int pos = binarySearch_1(num, n, 67);
    printf("pos = %d\n", pos);

    return 0;
}

int binarySearch_1(int num[], int numSize, int target) {
    int y = target;
    int *a = num;

    int d = 1, u = 15;
    int m = (d+u)/2;
    if (y == a[m]) {
        //printf("%d\n", m);
        return m;
    } else {
        //
        // 当目标值比中间值小时
        //
//        while (y < a[m]) {
//            d = (d+u)/2 + 1;
//            if (d > m) {
//                return -1;
//            }
//            m = (d+u)/2;
//            if (y == a[m]) {
//                return m;
//            }
//        }
//
//        //
//        // 当目标值比中间值大时
//        //
//        while (y > a[m]) {
//            u = (d+u)/2 - 1;
//            if (d > m) {
//                return -1;
//            }
//            m = (d+u)/2;
//            if (y == a[m]) {
//                return m;
//            }
//        }



        do {
            do {
                u = m;
                m = (d + u) / 2;
            } while (y > a[m]);
            do {
                d = m;
                m = (d+u)/2;
            }
            while (y < a[m]);
        }
        while (d <= u);
        // printf("%d\n", m);
        return m;
    }

    return -1;
}
