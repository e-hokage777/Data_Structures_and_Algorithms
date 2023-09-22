#include <stdio.h>
#include <stdlib.h>
#include <string.h>
// #include "../c_stack.h"
#include "../f_stack.h"
#include "infix_to_postfix.h"

#define MAX_STR_SIZE 80

float binEval(float value1, float value2, char operation)
{
    switch (operation)
    {
    case '*':
        return value1 * value2;
        break;
    case '/':
        return value1 / value2;
        break;
    case '+':
        return value1 + value2;
        break;
    case '-':
        return value1 - value2;
        break;
    default:
        return 0;
    }
}

float eval_postfix(char expression[])
{
    struct F_Stack fStack;
    fStack.link = NULL;
    char operand[MAX_STR_SIZE];
    for (int i = 0; i < strlen(expression); ++i)
    {
        if (isOperand(expression[i]))
        {
            strncat(operand, &expression[i], 1);
        }
        else if (expression[i] == ' ')
        {
            if (strlen(operand) > 0)
            {
                float value;
                sscanf(operand, "%f", &value);
                f_push(&fStack, value);
                strcpy(operand, "");
            }
        }
        else if (isOperation(expression[i]))
        {
            float op2 = f_pop(&fStack);
            float op1 = f_pop(&fStack);
            float res = binEval(op1, op2, expression[i]);
            f_push(&fStack, res);
        }
    }

    return f_top(fStack);

}

int main()
{
    char expression[MAX_STR_SIZE];
    char res[MAX_STR_SIZE];
    printf("Experssion => ");
    scanf("%[^\n]%*c", &expression);
    infix_to_postfix(expression, res);
    float eval_res = eval_postfix(res);
    printf("Evaluation Result: %.3f", eval_res);
}