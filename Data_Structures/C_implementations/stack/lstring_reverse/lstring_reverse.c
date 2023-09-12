#include <stdio.h>
#include <stdlib.h>

struct Node{
    char data;
    struct Node *next;
};

void append(struct Node *stringHead, char c){
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = c;
    temp->next = NULL;

    struct Node* tempHead = stringHead;
    while(tempHead->next != NULL){
        tempHead = tempHead->next;
    }
    tempHead->next = temp;
}

void print(struct Node stringHead){
    struct Node *temp = stringHead.next;
    while(temp != NULL){
        printf("%c", temp->data);
        temp = temp->next;
    }
    printf("\n");
}


int main(){
    char s[50];
    printf("Your String: ");
    scanf("%s", &s);
    struct Node s1;
    s1.data=NULL;
    s1.next=NULL;
    for(int i = 0; i < strlen(s); ++i)
        append(&s1, s[i]);

    print(s1);
    return 0;
}