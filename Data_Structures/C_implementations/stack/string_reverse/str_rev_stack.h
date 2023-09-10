#include <stdio.h>

struct Node{
    char data;
    struct Node *link;
};

struct Node revStack;

void push(char data){
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->link = revStack.link;
    temp->data = data;
    revStack.link = temp;
}

int isEmpty(struct Node top){
    return (top.link == NULL);
}


char top(){
    if(!isEmpty(revStack))
        return revStack.link->data;
}

char pop(){
    if(!(isEmpty(revStack))){
        char val = top();
        struct Node *temp = revStack.link;
        revStack.link = temp->link;
        free(temp);
        return val;
    }
}

void print(){
    struct Node *temp = revStack.link;
    printf("Stack content: ");
    while(temp != NULL){
        printf("%c ", temp->data);
        temp = temp->link;
    }
    
    printf("\n");
}

void reverseString(char string[]){
    int pos, m;
    pos = 0;
    m = 0;
    while(string[pos] != NULL){
        push(string[pos]);
        pos+=1;
    }

    for(m = 0; m < pos; ++m){
        string[m] = pop();
    }



}