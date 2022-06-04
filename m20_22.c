#include <stdio.h>

void main() {
    float amnt, a, b, final;
    
    printf("Enter in how many times you would like to add:");
    scanf("%f",&amnt);
    while (amnt > 0) {
        printf("Enter in two numbers");
        scanf("%f",&a);
        scanf("%f",&b);
        final = a + b;
        printf("%f \n",final);
        --amnt;
    }
}