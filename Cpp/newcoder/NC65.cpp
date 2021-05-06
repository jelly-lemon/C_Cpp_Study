/*
大家都知道斐波那契数列，现在要求输入一个整数n，请你输出斐波那契数列的第n项（从0开始，第0项为0，第1项是1）。
n <= 39
 */

/**
 * 递归写法（自顶向下），运行时间 603ms
 */
int Fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    return Fibonacci(n-1) + Fibonacci(n-2);
}

/**
 * 迭代写法（自底向上），运行时间 3ms
 */
int Fibonacci_1(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    int num_n1 = 0;
    int num_n2 = 1;
    int sum = 0;
    for (int i = 2; i <= n; i++) {
        sum = num_n1 + num_n2;
        num_n1 = num_n2;
        num_n2 = sum;
    }
    return sum;
}