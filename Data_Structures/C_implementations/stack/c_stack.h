#ifndef C_STACK
#define C_STACK

#include<stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node{
    char data;
    struct Node *link;
};

// struct Node stack;

void push(struct Node *top, char data){
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->link = top->link;
    temp->data = data;
    top->link = temp;
}

int isEmpty(struct Node top){
    return (top.link == NULL);
}


char top(struct Node top){
    if(!isEmpty(top))
        return top.link->data;
}

char pop(struct Node *top){
    if(!(isEmpty(*top))){
        struct Node *temp = top->link;
        char retChar = temp->data;
        top->link = temp->link;
        free(temp);
        return retChar;
    }
    return NULL;
}

void print(struct Node top){
    struct Node *temp = top.link;
    printf("Stack content: ");
    while(temp != NULL){
        printf("%c ", temp->data);
        temp = temp->link;
    }
    
    printf("\n");
}

// void reverseString(char string[]){
//     int pos, m;
//     pos = 0;
//     m = 0;
//     while(string[pos] != NULL){
//         push(string[pos]);
//         pos+=1;
//     }

//     for(m = 0; m < pos; ++m){
//         string[m] = pop();
//     }
// }




/*
********* BALANCING PARENTHESIS SECTION
*/

// function to check if character is a an opening parenthesis
int isOpenParenth(char c){
    return (c == '(' || c == '{' || c == '[');
}

// function to check if character is a a closing parenthesis
int isClosingParenth(char c){
    return (c == ')' || c == '}' || c == ']');
}

// function to check if current closing parenthesis matches the open parenthesis
int isMatchingClosingParenth(char open, char close){
    switch(open){
        case '{':
            return close == '}';
            break;
        case '(':
            return close == ')';
            break;
        case '[':
            return close == ']';
            break;
        default:
            return 0;
    }
}


int checkBalancedParenthesis(char expression[]){
    struct Node bStack;
    for(int i = 0; i < strlen(expression); ++i){
        if(isOpenParenth(expression[i])){
            push(&bStack, expression[i]);
        }
        else if(isClosingParenth(expression[i])){
            if(!isMatchingClosingParenth(pop(&bStack), expression[i])){
                return 0;
            }
        }
    }

    return (isEmpty(bStack));
}

#endif