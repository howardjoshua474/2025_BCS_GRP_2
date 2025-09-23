#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "demofunction.h"

int main()
{
    printf("===== Simple Calculator =====\n");
    printf("1. Addition (+)\n");
    printf("2. Subtraction (-)\n");
    printf("3. Multiplication (*)\n");
    printf("4. Division (/)\n");
    printf("5. Modulus (%%)\n");
    printf("6. enter expression\n");
    int do_again =1;
    int choice;

    while(do_again == 1){
    printf("enter your choice according to the menu no.: ");
    scanf("%d",&choice);
    getchar();

    if(choice >= 1 && choice <= 5){
    int num1;
    int num2;
    int num3;
    char op;
    int numop;
    printf("Enter number of operators:");
    scanf("%d",&numop);
    //int i;
    //for(i=0;i<3;i++)
    int repeat = 1;
    while(repeat == 1){
        printf("\nEnter your first number: ");
        scanf("%d",&num1);
        printf("Enter your operator(+,-,/,*,%%): ");
        scanf(" %c",&op);
        printf("Enter your second number: ");
        scanf("%d",&num2);
        int result = calculate_directly(num1,op,num2);
        printf("Result: %d\n",result);
        if(numop==1){
                break;
        }
        printf("Enter second operator(+,-,/,*,%%): ");
        scanf(" %c",&op);
        printf("Enter third number: ");
        scanf("%d",&num3);
        int newresult= use_result(result,op,num3);
        printf("Result = %d",newresult);
        printf("\n");

        printf("If you want to exit(enter: 0) OR to continue(enter: 1): ");
        scanf("%d",&repeat);
        }
    }
    else if(choice == 6){
        char expression[100];
        printf("enter your expression ( e.g 2-5+6): ");
        fgets(expression,sizeof(expression),stdin);
        expression[strcspn(expression,"\n")] = 0;

        int result = 0;
        char op = '+';
        int num = 0;
        int i = 0;

        while(expression[i] != '\0'){
            if(isdigit(expression[i])){
                num = num * 10 + (expression[i] -'0');
                i++;
            }
            else if(strchr("+-*/%",expression[i])){
                result = calculate_directly(result,op,num);
                op = expression[i];
                num = 0;
                i++;
            }
        }
        result = calculate_directly(result,op,num);
        printf("\nResult: %d",result);

    }
    printf("\nDo you want to have your choice again from the menu(YES,enter: 1|NO,enter: 0): ");
        scanf("%d",&do_again);
    }
    return 0;
}
