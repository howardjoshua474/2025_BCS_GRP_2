#include <stdio.h>
#include "demofunction.h"

int main()
{
    int num1;
    int num2;
    char op;

    printf("Enter your first number ");
    scanf("%d",&num1);
    printf("Enter your operator(+,-,/,*,%%): ");
    scanf(" %c",&op);
    printf("Enter your second number ");
    scanf("%d",&num2);

    int result = calculate_directly(num1,op,num2);
    printf("Result: %d\n",result);

    return 0;
}
