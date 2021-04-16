/**
 * 解析命令行参数
 *
 * getopt.h是一个 GNU 标准库的头文件，它包含一些从命令行上提取参数的函数。
 * getopt.h不是 ANSI C 标准库的一部分
 *
 * getopt()只支持短格式选项，而getopt_long()既支持短格式选项，又支持长格式选项
 *
 * 在 windows 中，文件拖入其实就是给 main 函数传参，传的文件路径
 */

#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>

/**
 * 短格式写法
 */
void test_0(int argc, char *argv[]) {
    int ch;
    // optind：全局变量，下一个检索位置
    // opterr：是否将错误信息输出到stderr，为0时表示不输出，默认1，表示要输出错误信息
    // optarg：保存参数值；
    printf("optind:%d opterr:%d\n", optind, opterr);
    // 没有冒号，表示不需要值传递，起到一个开关作用。称之为开关参数
    // 字母后有冒号，表示参数后面必须带有值。称之为必须参数。
    // （比如有参数 -b，我们想传值 test。连续写法 -btest，空格写法 -b test）（等号写法呢？不行）
    // 如果参数之间有空格，那么用双引号括起来。
    // 如果有两个冒号，表示可有可不有，但有参数时，必须用连续写法。缺省参数。
    // 参数之间用空格隔开
    while ((ch = getopt(argc, argv, "ab:c:de::")) != -1) {
        // 如果遇到了非设定参数，getopt 返回 '?'，然后程序退出
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
                // optopt：存放不在选项字符串optstring中的选项
                printf("Unknown option: %c\n", (char) optopt);
                break;
        }
        printf("optind: %d\n", optind);
    }
}

/**
 * 支持长参数和短参数
 */
void test_1(int argc, char *argv[]) {
    // has_arg取值为required_argument(或者是1)时，参数输入格式为：
    // --选项 值 或者 --参数=值
    // optional_argument(或者是2)时，参数输入格式只能为：
    // --选项=值
    static struct option long_options[] = {
            // 结构体最后一项，val 表示用户输入了相关参数，返回的参数名
            {"help",   no_argument,       NULL, 'h'},
            {"file",   required_argument, NULL, 'f'},
            {"output", optional_argument, NULL, 'o'},
            {0,        0, 0,                    0}};
    // 数组的最后一个元素必须填充为0，用于标记结束


    static char *const short_options = (char *) "hf:o::";  // 短参数
    int option_index = 0;
    int ret = 0;

    while ((ret = getopt_long(argc, argv, short_options, long_options, &option_index)) != -1) {
        switch (ret) {
            case 'h':
                printf("HAVE option: -h\n");
                break;
            case 'f':
                printf("HAVE option: -f\n");
                printf("The argument of -f is %s\n\n", optarg);
                break;
            case 'o':
                printf("HAVE option: -c\n");
                printf("The argument of -c is %s\n\n", optarg);
                break;
            case '?':
                break;
        }
    }
}

/**
 * 只支持长参数
 */
void test_2(int argc, char *argv[]) {
    char c;

    struct option long_options[] =
            {
                    {"mass-ratio",         required_argument, 0, 'q'},
                    {"low-freq (Hz)",      required_argument, 0, 'f'},
                    {"total-mass (M_sun)", required_argument, 0, 'm'},
                    {"sample-rate",        required_argument, 0, 's'},
                    {"output-file",        required_argument, 0, 'o'},
                    {"help",               no_argument,       0, 'h'},
                    {"version",            no_argument,       0, 'V'},
                    {0,                    0,                 0, 0}
            };
    /* parse the arguments */
    while (1) {
        /* getopt_long stores long option here */
        int option_index = 0;

        // getopt_long_only会将--name和-name两种选项都当作长参数来匹配。
        // 在getopt_long在遇到-name时，会拆解成-n -a -m -e到optstring中进行匹配，
        // 而getopt_long_only只在-name不能在longopts中匹配时才将其拆解成-n -a -m -e这样的参数到optstring中进行匹配
        c = getopt_long_only(argc, argv, "q:t:d:hV",
                             long_options, &option_index);

        /* detect the end of the options */
        if (c == -1) {
            break;
        }

        switch (c) {
            case 0:
                fprintf(stderr, "Error parsing option '%s' with argument '%s'\n",
                        long_options[option_index].name, optarg);
                //exit(1);
                break;

            case 'h':
                /* help message */
                //print_usage(argv[0]);

                exit(0);
                break;

            case 'V':
                /* print version information and exit */
//                fprintf(stdout, "%s - Compute Ajith's Phenomenological Waveforms " \
//         "(arXiv:0710.2335) and output them to a plain text file\n" \
//            "CVS Version: %s\nCVS Tag: %s\n", PROGRAM_NAME, CVS_ID_STRING, \
//            CVS_NAME_STRING);
                exit(0);
                break;

            case 'q':
                /* set mass ratio */
                //massRatio = atof(optarg);
                break;

            case 'f':
                /* set low freq */
                //lowFreq = atof(optarg);
                break;

            case 'm':
                /* set total mass */
                //totalMass = atof(optarg);
                break;

            case 's':
                /* set sample rate */
                //sampleRate = atof(optarg);
                break;

            case 'o':
                /* set name of output file */
                //optarg_len = strlen(optarg) + 1;
                //outFile = (CHAR *) calloc(optarg_len, sizeof(CHAR));
                //memcpy(outFile, optarg, optarg_len);
                break;

            case '?':
                //print_usage(argv[0]);
                exit(1);
                break;

            default:
                fprintf(stderr, "ERROR: Unknown error while parsing options\n");
                //print_usage(argv[0]);
                exit(1);
        }
    }

    if (optind < argc) {
        fprintf(stderr, "ERROR: Extraneous command line arguments:\n");
        while (optind < argc) {
            fprintf(stderr, "%s\n", argv[optind++]);
        }
        exit(1);
    }
}


int main(int argc, char *argv[]) {
    int i;
    for (i = 0; i < argc; i++) {
        printf("%s\n", argv[i]) ;
    }
    system("pause");
    return 0;
}