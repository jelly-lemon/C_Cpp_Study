#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
    char *s1 = "12345";
    char *s2 = "1234";
    printf("%d\n", strlen(strcpy(s1, s2)));

    return 0;
}

