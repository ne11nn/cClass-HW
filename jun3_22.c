#include <stdio.h>

void main()
{
    int a;

    printf("Enter in a number: ");
    scanf("%d",&a);

    if (a % 2 == 1)
    {
        printf("Number is odd");
    }
    else
    {
        printf("Number is even");
    }
}