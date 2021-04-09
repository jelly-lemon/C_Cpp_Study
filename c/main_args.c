/**
 * 解析命令行参数
 *
 * getopt.h是一个 GNU 标准库的头文件，它包含一些从命令行上提取参数的函数。
 * getopt.h不是 ANSI C 标准库的一部分
 *
 * getopt()只支持短格式选项，而getopt_long()既支持短格式选项，又支持长格式选项
 */

#include <stdio.h>
#include <unistd.h>

/**
 * --help
 * --ip
 * --port
 */

int main(int argc, char *argv[]) {
    int ch;
    // optind：全局变量，下一个检索位置
    // opterr：
    printf("optind:%d opterr:%d\n", optind, opterr);
    // 没有冒号，表示不需要值传递，起到一个开关作用。称之为开关参数
    // 字母后有冒号，表示参数后面必须带有值（比如有参数 -b，我们想传值 test。连续写法 -btest，空格写法 -b test）（等号写法呢？）
    // 如果有两个冒号，表示可有可不有，但有参数时，必须用连续写法
    // 参数之间用空格隔开
    while ((ch = getopt(argc, argv, "ab:c:de::")) != -1) {
        printf("optind: %d\n", optind);
        switch (ch) {
            case 'a':
                printf("HAVE option: -a\n");
                break;
            case 'b':
                printf("HAVE option: -b\n");
                // optarg 存放参数值
                printf("The argument of -b is %s\n\n", optarg);
                break;
            case 'c':
                printf("HAVE option: -c\n");
                printf("The argument of -c is %s\n\n", optarg);
                break;
            case 'd':
                printf("HAVE option: -d\n");
                break;
            case 'e':
                printf("HAVE option: -e\n");
                printf("The argument of -e is %s\n\n", optarg);
                break;
            case '?':
                printf("Unknown option: %c\n", (char) optopt);
                break;
        }
    }
}