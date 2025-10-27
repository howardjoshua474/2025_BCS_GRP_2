#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "demofunction.h"

int main(){
        printf("====SIMPLE CALCULATOR====\n" );

        printf("Basic operations\n");
        for (int i=1;i<=5; i++){
            switch(i){
                case 1:printf("%d. Adition (+)\n",i);break;
                case 2:printf("%d. Subtraction (-)\n",i);break;
                case 3:printf("%d. Multiplication (*)\n",i);break;
                case 4:printf("%d. Division (/)\n",i);break;
                case 5:printf("%d. Modulus (%%)\n",i);break;
            }
        }
    int yes=1;
    char continuity[5];
    while (yes==1){
        float x,y,z;
        char op1,op2;
        float temp,Result;//temp for temporary result
        int num_inputs;
        char line[20];
    //enter expression
    printf("\n");
    printf("Enter expression:");
    fgets(line,sizeof(line),stdin);
    num_inputs=sscanf(line,"%f %c %f %c %f",&x,&op1,&y,&op2,&z);

     if(num_inputs==3){
            switch(op1){
                case '+':
                    Result=add(x,y);
                    break;
                case '-':
                    Result=subtract(x,y);
                    break;
                case '*':
                    Result=multiply(x,y);
                    break;
                case '/':
                    Result=divide(x,y);
                    break;
                case '%':
                    Result=modulus(x,y);
                    break;
                default:
                    printf("invalid operator!");
                    continue;
            }
        }
  //Step1a:Handle precedence (*,/,%)before(+,-)
  else if(num_inputs==5){
  if (op2=='*'||op2=='/'||op2=='%'){
    switch(op2){
        case '*':
            temp=multiply(y,z);
            break;
        case '/':
            temp=divide(y,z);
            break;
        case '%':
            temp=modulus(y,z);
            break;
        }
  //Step 1b:Handle first operator using result from second operator
        switch(op1){
        case '+':
            Result=add(x,temp);
            break;
        case '-':
            Result=subtract(x,temp);
            break;
        case '*':
            Result=multiply(x,temp);
            break;
        case '/':
            Result=divide(x,temp);
            break;
        case '%':
            Result=modulus(x,temp);
            break;
        default:
            printf("invalid operator!");
            continue;
        }
    }
  //step 2a:for op1=op2
    else{
        switch(op1){
        case '+':
            temp=add(x,y);
            break;
         case '-':
            temp=subtract(x,y);
            break;
         case '*':
            temp=multiply(x,y);
            break;
         case '/':
            temp=divide(x,y);
            break;
         case '%':
            temp=modulus(x,y);
            break;
        default:
            printf("invalid operator!");
            continue;
        }
  //Step 2b:continue with op 2
           switch(op1){
        case '+':
            Result=add(temp,z);
            break;
         case '-':
            Result=subtract(temp,z);
            break;
         case '*':
            Result=multiply(temp,z);
            break;
         case '/':
            Result=divide(temp,z);
            break;
         case '%':
            Result=modulus(temp,z);
            break;
        default:
            printf("invalid operator!");
            continue;
      }
    }
  }
  else{
    printf("invalid input format! Example: 4 + 2 or 4 + 3 * 2\n");
    continue;
  }

    printf("Result=%.3f\n",Result);
    printf("enter 1 to continue,0 to stop:");
    fgets(continuity,sizeof(continuity),stdin);
    sscanf(continuity,"%d",&yes);
    }
    return 0;
}
