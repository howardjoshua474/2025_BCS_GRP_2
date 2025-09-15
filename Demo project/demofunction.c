#include "demofunction.h"
int add(int num1,int num2){
return num1 + num2;
}
int subtract(int num1,int num2){
return num1 - num2;
}
int multiply(int num1,int num2){
return num1 * num2;
}
int divide(int num1,int num2){
return num1 / num2;
}
int calculate_modulus(int num1,int num2){
return num1 % num2;
}

int calculate_directly(int num1,char op,int num2){
 switch(op){
 case '+':
     return add(num1,num2);
 case'-':
    return subtract(num1,num2);
 case'*':
    return multiply(num1,num2);
 case'/':
    return divide(num1,num2);
 case'%':
    return calculate_modulus(num1,num2);
 default:
    return 0;
}
}
