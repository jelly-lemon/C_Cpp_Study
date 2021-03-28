#include <math.h>
#include <stdio.h>

#define PI 3.14159265

/**
 * sin 函数，幅值[-0.5, 0.5]，中间轴为 y = 0.5
 *
 * @param x 角度
 */
double my_sin(int x) {
    double val = PI / 180;

    return sin(x *val)/2 + 0.5;
}

void test_1() {
    double val = PI / 180;

    // sin 参数：以弧度表示的角度
    // 角度转弧度：x = x*(3.14/180)
    printf("sin(0') = %lf\n", sin(0 * val));
    printf("sin(30') = %lf\n", sin(30 * val));
    printf("sin(45') = %lf\n", sin(45 * val));
    printf("sin(60') = %lf\n", sin(60 * val));
    printf("sin(90') = %lf\n", sin(90 * val));
    printf("sin(180') = %lf\n", sin(180 * val));
    printf("sin(270') = %lf\n", sin(270 * val));
    printf("sin(360') = %lf\n", sin(360 * val));
}

void test_2() {
    printf("sin(0') = %lf\n", my_sin(0));
    printf("sin(30') = %lf\n", my_sin(30));
    printf("sin(45') = %lf\n", my_sin(45));
    printf("sin(60') = %lf\n", my_sin(60));
    printf("sin(90') = %lf\n", my_sin(90));
    printf("sin(180') = %lf\n", my_sin(180));
    printf("sin(270') = %lf\n", my_sin(270));
    printf("sin(360') = %lf\n", my_sin(360));
}





int main() {
    test_2();


    return 0;
}