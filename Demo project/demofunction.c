#include <stdio.h>
#include <string.h>//declares strchr
#include <ctype.h>//declares isdigit
#include "demofunction.h"
/**
FUNCTION NAME: add
DESCRIPTION:adds two numbers
PARAMETERS:
    num1 (int):first number a user inputs
    num2 (int):second number a user inputs
RETURN TYPE:
    int: The sum of two numbers num1 and num2
**/
int add(int num1,int num2){
return num1 + num2;
}

/**
FUNCTION NAME: subtract
DESCRIPTION:subtracts two numbers
PARAMETERS:
    num1 (int):first number a user inputs
    num2 (int):second number a user inputs
RETURN TYPE:
    int: The difference of two numbers num1 and num2
**/
int subtract(int num1,int num2){
return num1 - num2;
}

/**
FUNCTION NAME: multiply
DESCRIPTION:multiplys two numbers
PARAMETERS:
    num1 (int):first number a user inputs
    num2 (int):second number a user inputs
RETURN TYPE:
    int: The product of two numbers num1 and num2
**/
int multiply(int num1,int num2){
return num1 * num2;
}

/**
FUNCTION NAME: divide
DESCRIPTION:divides two numbers
PARAMETERS:
    num1 (int):first number a user inputs
    num2 (int):second number a user inputs
RETURN TYPE:
    int: The quotient of two numbers num1 and num2
**/
int divide(int num1,int num2){
    if(num2 ==0){
        fprintf(stderr,"Error: Division by zero!\n");
        return 0;//return a safe value or handle error
    }
return num1 / num2;
}

/**
FUNCTION NAME: get_remainder
DESCRIPTION:gets the modulus two numbers
PARAMETERS:
    num1 (int):first number a user inputs
    num2 (int):second number a user inputs
RETURN TYPE:
    int: The modulus of two numbers num1 and num2
**/
int get_remainder(int num1,int num2){
    if(num2 ==0){
        fprintf(stderr,"Error: Modulus by zero!\n");
        return 0;//return a safe value or handle error
    }
return num1 % num2;
}

/**
FUNCTION NAME: calculate_directly
DESCRIPTION:returns a result which is of type int
PARAMETERS:
    num1 (int):first number a user inputs
    op (char):operator which is literally a string e.g +,/,*,-,%
    num2 (int):second number a user inputs
RETURN TYPE:
    int: The result of sum,product,difference,quontient,and modulus of two numbers num1 and num2
**/
int calculate_directly(int num1,char op,int num2){
 switch(op){
 case '+':
     return add(num1,num2);//adds two numbers
     break;
 case'-':
    return subtract(num1,num2);//subtracts two numbers
    break;
 case'*':
    return multiply(num1,num2);//multiplies two numbers
    break;
 case'/':
    return divide(num1,num2);//divides two numbers
    break;
 case'%':
    return get_remainder(num1,num2);//gets the modulus of two numbers
    break;
 default:
/**
This code is unreachable given the menu validation in the main.c
we log an error and return a consistent error code(-999999)
**/
    fprintf(stderr,"Error: internal system received Unknown operator '%c'\n",op);
    return -999999;//return the first number or a safe value
}
}

/**
FUNCTION NAME:calculate expression
DESCRIPTION:returns a result which is of type char
PARAMETERS:char *expression

RETURN TYPE:
     the result of the char:expression parsed by the user through the main.c
**/

int calculate_expression(char *expression){

        int result = 0;
        char op = '+';
        int num = 0;//current number being built
        int i = 0;//the index of the expression

        //counter to track if any digits were processed
        int digit_count = 0;
        //char* p = expression;
        //int stored_result = 0;
/**
LOOP: while

DESCRIPTION: it iterates through each character in the expression string and checks if it has reached the end of expression
            If the character is a digit ,it adds the digit to the num variable
            If the character is an operator, it calculates the result of the previous op'it`s an invalid number'eration using calculate directly function and
            updates the result variable
            After the loop, it calculates the result of the final operation using calculate directly function

CONDITION:expression[i] != '\0'
    the condition checks if the while loop has reached the end of expression
**/
        while(expression[i] != '\0'){//loops through each character in the expression

/**
STATEMENT: if statement

DESCRIPTION: checks if the character in the expression is a digit and it accumulates the digit into the num variable
**/
            if(isdigit(expression[i])){
                num = num * 10 + (expression[i] -'0');//accumulates the digit to build the number

                digit_count++;//increment count for every digit
                i++;
            }

/**
STATEMENT: else if
DESCRIPTION: checks if the character is an operator and it:
    1:stores the current num value in the nums array
    2:resets num to 0
    3:stores the current operator in op variable
**/

            else if(strchr("+-*/%",expression[i])){
                result = calculate_directly(result,op,num);//calculates the previous operation
                op = expression[i];//store the current character as the the new operator for the next step
                num = 0;//reset num to 0 to start accumulating the next number
                i++;
            }

/**
STATEMENT: else if

DESCRIPTION:logic to skip/ignore any non-digit/non-operator character like spaces
**/
            else if(expression[i] == ' '){
                        i++;// just increment and skip
                        continue;//go to the next iteration
                    }

/**
STATEMENT: else statement

DESCRIPTION: if its not space,and its an invalid character,it returns this error number -999999.

**/
            else {
                return -999999;
                }
            }

            result = calculate_directly(result,op,num);



/**
STATEMENT: if statement
DESCRIPTION: it does an Error check before returning,if no digits
were found,return is set to -999999.

CONDITION:
    if the condition is met is true the return is set to -999999 and other wise
result is returned to the function call in the main.c,calculate expression.

ERROR:
**/
        if(digit_count == 0){
            return -999999;
        }
        return result;
        }



