#include <stdio.h>
#include "demofunction.h"

int main()
{
    printf("===== Simple Calculator =====\n");
    printf("1. Addition (+)\n");
    printf("2. Subtraction (-)\n");
    printf("3. Multiplication (*)\n");
    printf("4. Division (/)\n");
    printf("5. Modulus (%%)\n");
    int num1;
    int num2;
    char op;

    printf("\nEnter your first number ");
    scanf("%d",&num1);
    printf("Enter your operator(+,-,/,*,%%): ");
    scanf(" %c",&op);
    printf("Enter your second number ");
    scanf("%d",&num2);

    int result = calculate_directly(num1,op,num2);
    printf("Result: %d\n",result);

    return 0;
}
