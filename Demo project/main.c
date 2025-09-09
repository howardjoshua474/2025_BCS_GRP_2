#include <stdio.h>
int calculate(int a,char op,int b){
//attribute definition
    int result;
 switch(op){
    case '+':
        result=a+b;
        ( printf("\n%d %c %d =%d\n",a,op,b,result));
        break;
    case '-':
        result=a-b;
        ( printf("\n%d %c %d =%d\n",a,op,b,result));
        break;
    case '*':
        result=a*b;
        ( printf("\n%d %c %d =%d\n",a,op,b,result));
        break;
    case '/':
        if (b==0){ printf("Math Error!!");}
        else{result =a/b;
        ( printf("\n%d %c %d =%d\n",a,op,b,result));
        }
        break;
    case '%':
        if (b==0){ printf("Math Error!!");}
        else{result= a/b;
        ( printf("\n%d %c %d =%d\n",a,op,b,result));
        }
        break;
    default :
        printf("Invalid Operator!\n");
        return 0;
 }


}
int main(){
    printf("=====Simple Calculator=====\n");
    printf("1. Addition (+)\n");
    printf("2. Subtraction (-)\n");
    printf("3. Multiplication (*)\n");
    printf("4. Division (/)\n");
    printf("5. Modulus (%%)\n");
int x,y;
int op;
int result;

//prompt user input
    printf("Enter first number: ");
    scanf("%d",&x);

    printf("Enter second number: ");
    scanf("%d",&y);

    printf("Enter operator(+,-,*,/):");
    scanf(" %c",&op);


    result= calculate(x,op,y);


return 0;

}



