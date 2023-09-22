// Linked list implementation of a Stack Data Structure
#pragma once

#include <stdio.h>
#include <stdlib.h>

struct F_Stack{
    float data;
    struct F_Stack *link;
};

void f_push(struct F_Stack *top, float data){
    struct F_Stack *temp = (struct F_Stack *)malloc(sizeof(struct F_Stack));
    temp->link = top->link;
    temp->data = data;
    top->link = temp;
}

float f_isEmpty(struct F_Stack top){
    return (top.link == NULL);
}

float f_pop(struct F_Stack *top){
    if(!(f_isEmpty(*top))){
        struct F_Stack *temp = top->link;
        top->link = temp->link;
        float val = temp->data;
        free(temp);
        return val;
    }

    return 0;
}

float f_top(struct F_Stack top){
    if(!f_isEmpty(top))
        return top.link->data;
}

void f_print(struct F_Stack top){
    struct F_Stack *temp = top.link;
    printf("Stack content: ");
    while(temp != NULL){
        printf("%f ", temp->data);
        temp = temp->link;
    }
    
    printf("\n");
}