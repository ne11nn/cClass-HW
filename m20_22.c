#include <stdio.h>

void main() {
    float amnt, a, b, final;

    scanf("%f",&amnt);
    while (amnt > 0) {
        scanf("%f",&a);
        scanf("%f",&b);
        final = a + b;
        printf("%f \n",final);
        --amnt;
    }
}