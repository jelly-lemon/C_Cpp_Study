/**

 c99
__STDC_VERSION__ = 199901

 c11
__STDC_VERSION__ = 201112

 c17
__STDC_VERSION__ = 201710

 __STRICT_ANSI__是gcc编译器的的一个预定义宏，当使用了-ansi编译选项，就会定义这个宏。
 -ansi 支持符合ANSI标准的C程序。这样就会关闭GNU C中某些不兼容ANSI C的特性,例如asm, inline和 typeof关键字,以及诸如unix和vax这些表明当前系统类型的预定义宏.
 */

#include <stdio.h>

int main(void) {
#ifdef __STDC_VERSION__
    printf("__STDC_VERSION__ = %ld \n", __STDC_VERSION__);
#endif
#ifdef __STRICT_ANSI__
    puts("__STRICT_ANSI__");
#endif
    return 0;
}