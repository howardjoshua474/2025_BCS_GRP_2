#include "demofunction.h"
/**int add(int num1,int num2){
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
int get_remainder(int num1,int num2){
return num1 % num2;
}**/

int calculate_directly(int num1,char op,int num2){
 switch(op){
 case '+':
     return num1+num2;
 case'-':
    return num1-num2;
 case'*':
    return num1*num2;
 case'/':
    return num1/num2;
 case'%':
    return num1%num2;
 default:
    return 0;
}
}
int use_result(int result,char op,int num3){
    switch(op){
 case '+':
     return result+num3;
 case'-':
    return result-num3;
 case'*':
    return result*num3;
 case'/':
    return result/num3;
 case'%':
    return result%num3;
 default:
    return 0;
    }
}
