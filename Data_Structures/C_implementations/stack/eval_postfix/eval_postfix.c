#include  <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../c_stack.h"
#include "infix_to_postfix.h"

#define MAX_STR_SIZE 80

int binEval(int value1, int value2, char operation){

}

int eval_postfix(char expression[]){
    struct Node opStack;
    opStack.data = NULL;
    opStack.link = NULL;
    char operand[MAX_STR_SIZE] = "";
    int operand1;
    int operand2;
    for(int i = 0; i < strlen(expression); ++i){
        if(!isOperation(expression[i])){
            push(&opStack, expression[i]);
        }
        else{
            // removing all while spaces
            while(!isEmpty(opStack) && !isOperand(top(opStack)))
                pop(&opStack);

            char value;
            while(!isEmpty(opStack) && isOperand(top(opStack))){
                value = pop(&opStack);
                strncat(operand, &value, 1);
            }
            // removing all while spaces
            while(!isEmpty(opStack) && !isOperand(top(opStack)))
                pop(&opStack);
            sscanf(operand, "%d", &operand1); // storing first value as first operand
            printf("Operand 1: %d\n", operand1);

            strcpy(operand, ""); // emptying the operand

            while(!isEmpty(opStack) && top(opStack) != ' '){
                value = pop(&opStack);
                strncat(operand, &value, 1);
            }

            // removing all while spaces
            while(!isEmpty(opStack) && !isOperand(top(opStack)))
                pop(&opStack);

            sscanf(operand, "%d", &operand2);
            printf("Operand 2: %d\n", operand2);

        }
    }

// NB: THIS IS A SERIOUS FLOW OF THIS IMPLEMENTATION !!!
//     Experssion => 12*14
//      Operand 1: 41 !!!
//      Operand 2: 21 !!!
//      TIP: when space reached convert to in and sore in int stack
}

int main(){
    char expression[MAX_STR_SIZE];
    char res[MAX_STR_SIZE];
    printf("Experssion => ");
    scanf("%[^\n]%*c", &expression);
    infix_to_postfix(expression, res);
    printf("%s\n", res);
    eval_postfix(res);
}