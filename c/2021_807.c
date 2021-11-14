#include <stdio.h>

void printArr(int a[], int len) {
    for (int i = 0; i < len; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

void fun(int *p, int len) {
    int i_max, i_min;
    i_max = i_min = 0;
    for (int i = 1; i < len; i++) {
        if (*(p+i) > *(p+i_max)) {
            i_max = i;
        }
        if (*(p+i) < *(p+i_min)) {
            i_min = i;
        }
    }
    int t;

    t = *(p+0);
    *(p+0) = *(p+i_max);
    *(p+i_max) = t;

    t = *(p+len-1);
    *(p+len-1) = *(p+i_min);
    *(p+i_min) = t;
}

/**
 调用函数 fun 查找数组中最大元素与第一位互换，
 最小元素与最后一位互换。使用指针实现。
 */
void test_0() {
    int a[] = {1, 7, 3, 2, 0, 9, 5, 4, 6, 8};
    int len = sizeof(a) / sizeof(int);
    printf("before:");
    printArr(a, len);

    fun(a, len);
    printf("after:");
    printArr(a, len);
}

struct Node{

};

/**
 两个递增有序链表L1与L2，P1 P2分别指向两链表头节点。
 利用两个链表的空间结点及指针P1 P2构造有序递减新链表L3。
 */
void test_1() {

}

/**
 选择合适的数据结构保存十个工人信息，
 包括编号、姓名、工龄和工资。
 使用冒泡法将工人按工龄从大到小排序，并输出排序后的结果。
 */
void test_3() {

}

/**
 有一长度为10的字符串，输入一个子串，
 调用find函数找出字符串中含有输入子串的个数，
 并在主函数中输出结果。
 */
void test_4() {

}

/**
 现有ABC三个顺序表，要求在顺序表A中删除BC中含有元素后构建新的顺序表并输出。
 结构体中数据为int类型。
 */
void test_5() {

}

int main() {
    test_0();


    return 0;
}