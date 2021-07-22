#include <stdio.h>

/**
 * 对 url 进行解码
 */
void urldecode(char *p) {
    int i = 0;
    while (*(p + i)) {
        if ((*p = *(p + i)) == '%') {
            *p = *(p + i + 1) >= 'A' ? ((*(p + i + 1) & 0XDF) - 'A') + 10 : (*(p + i + 1) - '0');
            *p = (*p) * 16;
            *p += *(p + i + 2) >= 'A' ? ((*(p + i + 2) & 0XDF) - 'A') + 10 : (*(p + i + 2) - '0');
            i += 2;
        } else if (*(p + i) == '+') {
            *p = ' ';
        }
        p++;
    }
    *p = '\0';
}

void test_0() {
    char p[2048] = "webauth://-h%2010.66.241.189%20-u%20usbkey_test%20-p%20443%20-g%202084899A-964E-7681-CA13-DE29A2E151A2/";
    urldecode(p);
    printf("%s\n", p);
}


int main() {
    test_0();
}