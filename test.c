#include <math.h>
#include <stdio.h>

int main() {
    float x,y,z;
    scanf("%f%f",&x,&y);
    z = x/y;
    while (1) {
        if (fabs(z) > 1.0) {
            x = y; y = z; z = x/y;
        } else {
            break;
        }
    }
    printf("%f", y);
}