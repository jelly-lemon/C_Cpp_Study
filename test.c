# include <stdio.h>
#include <string.h>

void sayHello_1() {
    int b = 4;
    printf("%d\n", b);
    b++;
}

void sayHello_2() {
    static int b = 4;
    printf("%d\n", b);
    b++;
}

int main(void){
    sayHello_2();
    sayHello_2();
    sayHello_2();


    return 0;
}