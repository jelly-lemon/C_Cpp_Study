#include <getopt.h>
#include <stdio.h>

/**
 * 命令行参数解析
 *
 * 开关选项、可选选项、必填选项
 */
int main(int argc, char *argv[]) {
    char ch;

    //
    // 一个冒号就表示这个选项后面必须带有参数（没有带参数会报错
    // 但是这个参数可以和选项连在一起写，也可以用空格隔开，比如-a123 和-a   123（中间有空格） 都表示123是-a的参数
    // 两个冒号的就表示这个选项的参数是可选的，即可以有参数，也可以没有参数，但要注意有参数时，参数与选项之间不能有空格（有空格会报错的哦），这一点和一个冒号时是有区别的
    //
    while ((ch = getopt(argc, argv, "ab:c:de::")) != -1)
    {
        printf("optind: %d\n", optind);
        switch (ch)
        {
            case 'a':
                printf("HAVE option: -a\n\n");
                break;
            case 'b':
                printf("HAVE option: -b\n");
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
                printf("Unknown option: %c\n",(char)optopt);
                break;
        }
    }

    return 0;
}