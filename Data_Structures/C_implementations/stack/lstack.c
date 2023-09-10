// Linked list implementation of a Stack Data Structure
#include <stdio.h>

struct Node{
    int data;
    struct Node *link;
};

void push(struct Node *top, int data){
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->link = top->link;
    temp->data = data;
    top->link = temp;
}

int isEmpty(struct Node top){
    return (top.link == NULL);
}

void pop(struct Node *top){
    if(!(isEmpty(*top))){
        struct Node *temp = top->link;
        top->link = temp->link;
        free(temp);
    }
}

int top(struct Node top){
    if(!isEmpty(top))
        return top.link->data;
}

void print(struct Node top){
    struct Node *temp = top.link;
    printf("Stack content: ");
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->link;
    }
    
    printf("\n");
}

int main(){
    struct Node stack1;
    stack1.link = NULL;
    push(&stack1, 5);
    push(&stack1, 9);
    print(stack1);
    pop(&stack1);
    print(stack1);
    push(&stack1, 64);
    print(stack1);
    printf("Stack top: %d\n", top(stack1));
    printf("Is Stack Emtpy: %d\n", isEmpty(stack1));
    pop(&stack1);
    pop(&stack1);
    pop(&stack1);
    print(stack1);
    printf("Is Stack Emtpy: %d\n", isEmpty(stack1));
    return 0;
}