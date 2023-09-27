#pragma once

#include <stdio.h>
#include <stdlib.h>

struct LQ_Node
{
    int data;
    struct LQ_Node *next;
};

struct L_Queue
{
    struct LQ_Node *front;
    struct LQ_Node *rear;
};

int isEmpty(struct L_Queue queue)
{
    return ((queue.front == NULL) && (queue.rear == NULL));
}

void enqueue(struct L_Queue *queue, int data)
{
    struct LQ_Node *temp = (struct LQ_Node *)malloc(sizeof(struct LQ_Node));
    temp->data = data;
    temp->next = NULL;

    if (isEmpty(*queue))
    {
        queue->front = temp;
        queue->rear = temp;
    }
    else
    {
        queue->rear->next = temp;
        queue->rear = temp;
    }
}

int dequeue(struct L_Queue *queue)
{
    if(isEmpty(*queue))
        return;
        
    struct LQ_Node *temp = queue->front;
    int data = temp->data;
    if (queue->front == queue->rear)
    {
        queue->front = NULL;
        queue->rear = NULL;
    }
    else{
        queue->front = temp->next;
    }

    free(temp);
    return data;
}

int front(struct L_Queue queue)
{
    if (!isEmpty(queue))
        return queue.front->data;
}

int rear(struct L_Queue queue)
{
    if (!isEmpty(queue))
        return queue.rear->data;
}

void print(struct L_Queue queue)
{
    if (isEmpty(queue))
        return;

    struct LQ_Node *temp = queue.front;
    printf("Queue contents: ");
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    printf("\n");
}