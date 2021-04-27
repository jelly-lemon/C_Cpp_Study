/*
 运行时间：297ms
超过31.94%用C++提交的代码
占用内存：504KB
超过69.76%用C++提交的代码
 */
int jumpFloor(int number) {
    int count = 0;
    if (number == 1) {
        return 1;
    }
    else if (number == 2) {
        return 2;
    } else if (number <= 0){
        return 0;
    } else {
        count = jumpFloor(number-1) + jumpFloor(number-2);
        return count;
    }
}