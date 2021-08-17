/**
JZ10 矩形覆盖

 描述
我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。
 请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，
 从同一个方向看总共有多少种不同的方法？


*/

/**
 * 思路：斐波那契数列变型
 *
    运行时间：3ms
超过51.25% 用C++提交的代码
占用内存：532KB
超过28.27%用C++提交的代码
    */
int rectCover(int number) {
    int *p = new int[number+1];
    p[0] = 0;
    p[1] = 1;
    p[2] = 2;

    for (int i = 3; i <= number; i++) {
        // i 表示 i 块瓷砖，p[i-1]表示 i-1 块的方案数
        p[i] = p[i-1] + p[i-2];
    }

    int rt = p[number];
    delete []p;
    return rt;
}