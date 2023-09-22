// Linked list implementation of a Stack Data Structure
#pragma once

#include <stdio.h>
#include <stdlib.h>

struct I_Stack{
    int data;
    struct I_Stack *link;
};

void i_push(struct I_Stack *top, int data){
    struct I_Stack *temp = (struct I_Stack *)malloc(sizeof(struct I_Stack));
    temp->link = top->link;
    temp->data = data;
    top->link = temp;
}

int i_isEmpty(struct I_Stack top){
    return (top.link == NULL);
}

void i_pop(struct I_Stack *top){
    if(!(i_isEmpty(*top))){
        struct I_Stack *temp = top->link;
        top->link = temp->link;
        free(temp);
    }
}

int i_top(struct I_Stack top){
    if(!i_isEmpty(top))
        return top.link->data;
}

void i_print(struct I_Stack top){
    struct I_Stack *temp = top.link;
    printf("Stack content: ");
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->link;
    }
    
    printf("\n");
}