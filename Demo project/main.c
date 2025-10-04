#include <stdio.h>
#include <string.h>//provide a declaration of strcspn
#include "demofunction.h"

int main(){
/**
this number (-999999) in this project is used to signify an error that an unrecoverable error occurred during calculation
this way it provides a clear and a consistent signal across all the calculation functions. e,g
if the main.c function receives -999999 as the result, it knows to print an 'error' message specified to the user
instead of the number.
**/

    printf("\n===== Simple Calculator =====\n");
    printf("\n1. Addition (+)\n");
    printf("2. Subtraction (-)\n");
    printf("3. Multiplication (*)\n");
    printf("4. Division (/)\n");
    printf("5. Modulus (%%)\n");
    printf("6. enter expression\n");
    printf("\n============================\n");

    int use_stored_result = 0;
    int stored_result = 0;
    int do_again = 1;
    int choice;

/**
LOOP: while
DESCRIPTION: it iterates through the whole code prompting the user to enter choice
from the menu until he/she puts a number not 1 and finally the loop breaks.

CONDITION:
    the condition when is met the while loop continues iterating prompting the user until he/she
    puts a number not 1 and finally the loop breaks.
**/

    while(do_again == 1){
/**
STATEMENT: if statement
DESCRIPTION:it checks if the user has input the correct choice which is a digit between 1 and 6 and also
// checks if scanf has failed to read an integer i.e  if the user has entered 'e' and the return value of the
scanf is not 1 then the error is loaded and otherwise if the return value is 1 then the condition is false
and the error is not executed.
and otherwise if it`s a letter or invalid number an error occurs.

ERROR:'it`s an invalid number',a digit is required.
**/
    printf("\n enter your choice according to the menu no.: ");
    if(scanf("%d",&choice) != 1){
        while(getchar() != '\n');// clear the input buffer on failure
        printf("error!! 'it`s an invalid number',a digit is required: menu\n");
        choice = 0;// set to invalid choice
        continue;
    }//read the readers choice
    while(getchar() != '\n');//buffer cleanup


/**
STATEMENT: if statement
DESCRIPTION: it checks if the user has put a number between 1 and 5 to proceed with any calculations
CONDITION:
    the condition when is met the user is able perform any calculation in the range of option 1 and 5
    and otherwise he/she chooses other options or an error occurs if he puts a number out of range.

ERROR:
**/
    if(choice >= 1 && choice <= 5){
        int num1;
        int num2;
        char op;
        char user_input_op;//for validating operator input

        //determine the operator based on choice

        switch(choice){
            case 1:op = '+';
            break;

            case 2:op = '-';
            break;

            case 3:op = '*';
            break;

            case 4:op = '/';
            break;

            case 5:op = '%';
            break;
        }
        //}

        //code for use sored result
        printf("\n To use the stored result? = %d (YES: PRESS 1 TO USE / NO: PRESS 0 TO IGNORE) ",stored_result);//prompts the user to use the stored result

/**
STATEMENT: if statement
DESCRIPTION:it checks if the user has input the correct digit which is either (1 and or 0)) and also
// checks if scanf has failed to read an integer i.e  if the user has entered 'e' or any other
character and the return value of the scanf is not 1 then the error is loaded and otherwise if the return
value is 1 then the condition is false and the error is not executed and otherwise if it`s a letter or
invalid number an error occurs.

ERROR:"error: enter 0 or 1\n".
**/
        if(scanf("%d",&use_stored_result) != 1){
            printf("error: enter 0 or 1\n");
            printf("Go back to the menu\n");
            while(getchar() != '\n');//clear input buffer on failure
            continue;
        }//reads the user input
        while(getchar() != '\n');//buffer cleanup

/**
STATEMENT: if statement

DESCRIPTION: it checks if the user has put number 1 to proceed to use the stored result and the stored result
becomes the first number and otherwise by pressing 0 to ignore and the condition becomes false and the else
part is executed.

CONDITION:
    the condition when is met the user is able to use the stored result as his/her first number and otherwise he/she is
    prompted to put the first number.

**/
        if(use_stored_result == 1){
            num1 = stored_result;
            printf("using stored result: %d\n",num1);
        }

/**
STATEMENT: else statement

DESCRIPTION:  it is considered,if the user does not use the stored result,thus running
the else code that will prompt him/her to put the first number and otherwise then the stored result becomes the first number.
**/
        else{

            NUM1_INPUT:// label to JUMP back to on error
            printf("\nEnter your first number: ");

/**
STATEMENT: if statement
DESCRIPTION:it checks if the user has input the correct digit NUM2 and not other character and also
// checks if scanf has failed to read an integer i.e  if the user has entered 'e' or any other
character and the return value of the scanf is not 1 then the error is loaded and otherwise if the return
value is 1 then the condition is false and the error is not executed and otherwise if it`s a letter or
invalid number an error occurs.

ERROR: "first input is not a valid number. Try again".
**/
        if(scanf("%d",&num1) != 1){
            printf("first input is not a valid number. Try again\n");
            while(getchar() != '\n');// input buffer cleanup
            goto NUM1_INPUT;// JUMP back and ask for num1 again

        }
            while(getchar() != '\n');//remaining input buffer cleanup after successful input

        }

        //
/**
LOOP:while.

DESCRIPTION:operator validation loop,where the user is required to put the
correct operator basing on the choice.
**/

        do{
            //prompt the user to put the required operator
        printf("Enter your operator(+,-,/,*,%%),must be '%c': ",op);

/**
STATEMENT: if statement
DESCRIPTION:it checks if the user has input the correct operator and also checks the input by
checking if scanf has failed to read an integer i.e  if the user has entered 'e' or any other
character and the return value of the scanf is not 1 then the error is loaded and otherwise if the return
value is 1 then the condition is false and the error is not executed and otherwise if it`s a letter or
invalid number an error occurs.

ERROR:"Error reading input. Please try again".
**/
       if(scanf(" %c",&user_input_op) != 1){
            printf("Error reading input. Please try again.\n");
            while(getchar() != '\n');//clear the buffer
            continue;//restart the loop immediately
            }
        while(getchar() != '\n');//clear the buffer

        //validation check

/**
STATEMENT: if statement

DESCRIPTION:It checks the operator entered,if the operator is correct basing on the choice made
and otherwise error ocurrs.

ERROR:"Error!! You chose option %d, which requires the '%c' operator to continue."
**/
        if(user_input_op != op){

                //incorrect operator entered
                printf("Error!! You chose option %d, which requires the '%c' operator to continue.\n",choice,op);

            }
            else{

                op = user_input_op;//keep op updated
                break;//exit the loop and continue to the second number

            }

        }while(1);//loop indefinitely until 'break' is hit

        NUM2_INPUT:// label to JUMP back to on error
        printf("\nEnter your second number: ");

/**
STATEMENT: if statement
DESCRIPTION:it checks if the user has input the correct digit NUM2 and not other character and also
// checks if scanf has failed to read an integer i.e  if the user has entered 'e' or any other
character and the return value of the scanf is not 1 then the error is loaded and otherwise if the return
value is 1 then the condition is false and the error is not executed and otherwise if it`s a letter or
invalid number an error occurs.

ERROR: "second input is not a valid number. Try again".
**/
        if(scanf("%d",&num2) != 1){
            printf("second input is not a valid number. Try again\n");
            while(getchar() != '\n');// input buffer cleanup
            goto NUM2_INPUT;// JUMP back and ask for num2 again

        }
        while(getchar() != '\n');//remaining input buffer cleanup after successful input

        //calculate and store the result
        int result = calculate_directly(num1,op,num2);
        printf("Result: %d\n",result);
        stored_result = result;
        printf("\n");
    }

/**
STATEMENT: else if statement

DESCRIPTION: it checks if the user has put a number equal to 6 to proceed to calculate
expression of form 2+4-5 and otherwise is prompted to have the choice again

CONDITION:
    the condition when is met the user is able to proceed to calculate expression of form 2+4-5

**/
    else if(choice == 6){

        char expression[100];// declares a character array expression to store user input expression
        printf("\nenter your expression ( e.g 2-5+6): ");//prompts the user to enter an expression

        if(fgets(expression,sizeof(expression),stdin)== NULL){
            do_again = 0;
            continue;
        }
        // removes newline character
        expression[strcspn(expression, "\n")] = 0;
        //stores the result of the expression
        stored_result = calculate_expression(expression);

        //this checks if the calculate expression function returns the error number
/**
STATEMENT: if statement

DESCRIPTION:It checks the stored result returned by the calculate directly function and if the return value is -999999
then an error occurs and otherwise the stored result is returned and printed.

ERROR:Invalid expression. please make sure the expression contains numbers and operators(e.g.,2+5.)"
**/
        if(stored_result == -999999){
            printf("Error: Invalid expression. please make sure the expression contains numbers and operators(e.g.,2+5.)\n");
            }
        else{
           printf("Result: %d\n",stored_result);
        }

    }
    //statement else- for invalid choice input not in the range between 1 and 6
    else{
        printf("\n invalid choice. Please enter a number between 1 and 6.\n");
    }

        // prompts the user to whether to loop again to have the choice again from the menu
        printf("\nDo you want to have your choice from the menu(YES, 1 /NO: 0)? ");

/**
STATEMENT: if statement

DESCRIPTION:reads the user input if he/she puts 1 the prompt for choosing the choice
is brought back and otherwise the loop breaks and also checks if scanf has failed to
read an integer i.e if the user has entered 'e' or any other character and the return value of
the scanf is not 1 then the error is loaded and otherwise if the return value is 1 then the condition
is false and the error is not executed and otherwise if it`s a letter or invalid number an error occurs.

ERROR:"Error reading input. Please try again".
**/
        if(scanf("%d",&do_again) != 1){
            do_again = 0;//end the loop on bad input
        }
}

        return 0;
    }


