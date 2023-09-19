#include <stdio.h>
#include <string.h>
#include "../c_stack.h"

#define MAX_STR_SIZE 80

// function to check if character is an operand
int isOperand(char c)
{
    switch (c)
    {
    case '0':
    case '1':
    case '2':
    case '3':
    case '4':
    case '5':
    case '6':
    case '7':
    case '8':
    case '9':
        return 1;
        break;
    default:
        return 0;
    }
}

// function to check if `c` is an operand
int isOperation(char c)
{
    switch (c)
    {
    case '+':
    case '-':
    case '/':
    case '*':
        return 1;
        break;
    default:
        return 0;
    }
}

// function to check if equal precedence
int isEqualPrecedence(char a, char b)
{
    if (a == b)
    {
        return 1;
    }

    if (a == '+' && b == '-')
        return 1;
    if (a == '-' && b == '+')
        return 1;
    if (a == '*' && b == '/')
        return 1;
    if (a == '/' && b == '*')
        return 1;

    return 0;
}

// function to check if 'a' if of lower precedence than 'b'
int isLowerPrecedence(char a, char b)
{
    // return true if equal due to associativity rules
    if (isEqualPrecedence(a, b))
        return 1;

    // this also works for associativity rule as well as normal precedence stuff
    if (a == '+' || a == '-')
        return 1;

    return 0;
}

// function to check where 'c' is an opening parenthesis
int isOpeningParenthesis(char c)
{
    switch (c)
    {
    case '(':
    case '{':
    case '[':
        return 1;
        break;
    default:
        return 0;
    }
}

// function to check where 'c' is a closing parenthesis
int isClosingParenthesis(char c)
{
    switch (c)
    {
    case ')':
    case '}':
    case ']':
        return 1;
        break;
    default:
        return 0;
    }
}

// function to convert infix to postfix
char *infix_to_postfix(char string[])
{
    struct Node opStack;
    opStack.data = NULL;
    opStack.link = NULL;
    char res[MAX_STR_SIZE] = "";
    char operand[MAX_STR_SIZE] = "";
    char temp; // to hold temporary characters for `strncat` function
    for (int i = 0; i < strlen(string); ++i)
    {
        if (isOperand(string[i]))
        {
            strncat(operand, &string[i], 1);
        }
        else if (isClosingParenth(string[i]))
        {
            // appending operands in variable
            if (operand != "")
            {
                strcat(res, operand);
                strcat(res, " ");
                strcpy(operand, "");
            }
            while (!isOpeningParenthesis(top(opStack)))
            {
                temp = pop(&opStack);
                strncat(res, &temp, 1); // appending higher precedence operations
                strcat(res, " ");
            }

            pop(&opStack);
        }
        else if (isOperation(string[i]) || isOpeningParenthesis(string[i]))
        {
            if (operand != "")
            {
                strcat(res, operand);
                strcat(res, " ");
                strcpy(operand, "");
            }

            while (!isEmpty(opStack) && !isOpeningParenthesis(top(opStack)) && isLowerPrecedence(string[i], top(opStack)))
            {
                temp = pop(&opStack);
                strncat(res, &temp, 1); // appending higher precedence operations
                strcat(res, " ");
            }

            push(&opStack, string[i]); // pushing the lower precedence operation
        }
    }

    // appending operands in variable
    if (operand != "")
        strcat(res, operand);

    // appending remaining operations
    while (!isEmpty(opStack))
    {
        temp = pop(&opStack);
        strcat(res, " ");
        strncat(res, &temp, 1);
    }

    printf("%s\n", res);
}

int main()
{
    char expression[MAX_STR_SIZE];
    printf("Enter your expression: ");
    scanf("%[^\n]%*c", expression);
    infix_to_postfix(expression);
    return 0;
}