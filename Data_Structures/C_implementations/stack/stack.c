#include <stdio.h>
# define MAX_STACK_SIZE 50

struct Stack{
    int top;
    int stackList[MAX_STACK_SIZE];
};

void push(struct Stack *stackPointer, int data){
    stackPointer->stackList[++stackPointer->top] = data;
}

int pop(struct Stack *stackPointer){
    return stackPointer->stackList[stackPointer->top--];
}

int top(struct Stack *stackPointer){
    return stackPointer->stackList[stackPointer->top];
}

void print(struct Stack stack){
    for(int i = 0; i <= stack.top; ++i){
        printf("%d ", stack.stackList[i]);
    }
    printf("\n");
}


int main(){
    struct Stack stack1;
    stack1.top = -1;
    push(&stack1, 2);
    push(&stack1, 3);
    push(&stack1, 7);
    print(stack1);
    printf("Popped value: %d \n", pop(&stack1));
    print(stack1);
    printf("Value on top of stack: %d\n", top(&stack1));
    print(stack1);
    return 0;
}