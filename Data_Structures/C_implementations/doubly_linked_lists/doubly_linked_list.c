#include <stdio.h>

struct Node {
    int data;
    struct Node *prev, *next;
};

void append(struct Node **headPointer, int data){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    if(*headPointer == NULL){
        *headPointer = newNode;
        newNode->prev = NULL;
        return;
    }

    struct Node *temp = *headPointer;
    while(temp->next != NULL){
        temp = temp->next;
    }
    temp->next = newNode;
    newNode->prev = temp;
}

void insertAtHead(struct Node **headPointer, int data){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;
    
    if(*headPointer != NULL){
        (*headPointer)->prev = newNode;
        newNode->next = *headPointer;
    }

    *headPointer = newNode;
}

void insertAt(struct Node **headPointer, int index, int data){
    if(index == 0){
        insertAtHead(headPointer, data);
        return;
    }

    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    struct Node *temp = *headPointer;
    for(int i = 0; i < index; ++i){
        if(temp == NULL)
            return;

        temp = temp->next;
    }
    if(temp == NULL)
        append(headPointer, data);
    else{
        temp->prev->next = newNode; // -- there is an issue over here
        newNode->next = temp;
        newNode->prev = temp->prev;
        temp->prev = newNode;
    }
}

void print(struct Node *head){
    struct Node *temp = head;
    printf("List contents: ");
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void reversePrint(struct Node *head){
    struct Node *temp = head;
    if(temp == NULL) return;
    while(temp->next != NULL)
        temp = temp->next;
    while(temp != NULL){
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main(){
    struct Node* head = NULL;
    int n,x;
    printf("Number of Integers => ");
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        printf("Integer => ");
        scanf("%d", &x);
        append(&head, x);
        // insertAtHead(&head, x);
        reversePrint(head);
    }

    // insertAt(&head, 1, 17);
    print(head);
    return 0;
}