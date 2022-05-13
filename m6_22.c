#include<stdio.h>

void main() {
    float a,b,c,ave;

    printf("Number A: ");
    scanf("%f",&a);

    printf("Number B: ");
    scanf("%f",&b);

    printf("Number C: ");
    scanf("%f",&c);

    ave = (a+b+c)/3;
    printf("Average: %f",ave);
}