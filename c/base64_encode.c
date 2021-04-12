/**
 * URL base64 编码解码
 */
#include <stdio.h>
#include <string.h>


char *base64_encode(const char *s) {
    if (s == NULL)
        return NULL;
    int n = strlen(s);
    if (n == 0)
        return NULL;
}