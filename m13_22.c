#include <stdio.h>
#include <Windows.h>

void main(){ 
	float a,b,ans;

    printf("Enter in two numbers to add: ");
    while (scanf("%f%f",&a,&b) == 2)
    {
        ans = a + b;
        printf("%.2f + %.2f = %.2f\n",a,b,ans);
        Sleep(500);
        printf("Enter in two numbers to add: ");
    }
}
