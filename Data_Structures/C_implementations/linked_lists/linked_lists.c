#include <stdio.h>

struct Node
{
    int data;
    struct Node *next;
};

// struct Node *head;

/*
    Function to insert new value at beginning of lined list
*/
void insertFront(struct Node **headPointer, int value)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = value;
    temp->next = *headPointer;
    *headPointer = temp;
}

/*
    Function to insert new value at end of linked list
*/
void insert(struct Node **headPointer, int value)
{
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node)); // create a new node and return pointer
    temp->data = value;
    temp->next = NULL;
    if (*headPointer == NULL)
    {
        *headPointer = temp;
    }
    else
    {
        struct Node *nextNode = *headPointer;
        while (nextNode->next != NULL)
        {
            nextNode = nextNode->next;
        }
        temp->data = value;
        temp->next = NULL;
        nextNode->next = temp;
    }
}

/*
    Function to print items at the nth position of list
*/
void insertAt(struct Node **headPointer, int index, int value)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (index == 0)
    {
        insertFront(headPointer, value);
    }
    else
    {
        int count = 0;
        struct Node *temp = *headPointer;
        while (temp != NULL)
        {

            if (count + 1 == index)
            {
                newNode->next = temp->next;
                temp->next = newNode;
            }

            temp = temp->next;
            count += 1;
        }
    }
}

/*
    Function to print items in the list
*/

/*
    Function to delete a node
*/
void delete(struct Node **headPointer, int index)
{
    struct Node *temp = *headPointer;
    for (int i = 0; i < index - 1; ++i)
        temp = temp->next;

    if (temp == NULL)
        return;

    struct Node *nodeToDel;
    if (index == 0)
    {
        nodeToDel = *headPointer;
        *headPointer = nodeToDel->next;
    }
    else
    {
        nodeToDel = temp->next;
        temp->next = nodeToDel->next;
    }

    free(nodeToDel);
}

void reverse(struct Node** headPointer){
    struct Node* predecessor = NULL;
    struct Node* current = *headPointer;
    struct Node* next;

    while(current != NULL){
        next = current->next;
        current->next = predecessor;
        predecessor = current;
        current = next;
    }

    *headPointer = predecessor;
}

struct Node * r_reverse(struct Node *current, struct Node *previous){
    if(current == NULL){
        return previous;
    }

    struct Node *next = current->next;
    current->next = previous;
    r_reverse(next, current);
}

void recurse_reverse(struct Node **headPointer){
    // *headPointer = r_reverse(*headPointer, NULL);
    recurse_reverse3(headPointer, *headPointer);
}

void recurse_reverse2(struct Node **headPointer, struct Node* current, struct Node* previous){
    if(current = NULL){
        *headPointer = previous;
        return;
    }
    recurse_reverse2(headPointer, current->next, current);
    current->next = previous;
}

void recurse_reverse3(struct Node **headPointer, struct Node* current){
    if(current->next = NULL){
        *headPointer = current;
        return;
    }
    recurse_reverse3(headPointer, current->next);
    current->next->next = current;
    current->next = NULL;
}

void print(struct Node *head)
{
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

void recurse_print(struct Node* nodePointer){
    if(nodePointer == NULL){
        printf("\n");
        return;
    }

    printf("%d ", nodePointer->data);
    recurse_print(nodePointer->next);
}

void recurse_reverse_print(struct Node* nodePointer){
    if(nodePointer == NULL)
        return;

    recurse_reverse_print(nodePointer->next);
    printf("%d ", nodePointer->data);
}

int main()
{
    struct Node *head = NULL;
    int n, x, i;
    printf("Number of integers -> ");
    scanf("%i", &n);
    printf("\n");

    for (i = 0; i < n; ++i)
    {
        printf("Integer %i: ", i + 1);
        scanf("%i", &x);
        insert(&head, x);
        // printf("List Content: ");
        // print(head);
        // printf("\n");
    }

    // printf("List Content: ");
    // print(head);
    // printf("\n");

    // printf("List Content (After recursive reversal): ");
    // recurse_reverse(&head);
    // print(head);
    // printf("\n");

    printf("Recursive Reverse printing of list:\n");
    printf("List content => ");
    recurse_reverse_print(head);
    return 0;
}