#ifndef BSTNODEQUEUE_H
#define BSTNODEQUEUE_H

#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 80


struct BST_NODE_QUEUE{
    int front;
    int rear;
    struct BstNode *data[MAX_QUEUE_SIZE];
};

// function to check if the queue is empty
int isEmpty(struct BST_NODE_QUEUE queue){
    return ((queue.front == -1) && (queue.rear == -1));
}

// function to add element at the rear of the queue
void enqueue(struct BST_NODE_QUEUE *queue, struct BstNode *data){
    if(isEmpty(*queue)){
        // printf("first enqueue\n");
        queue->front = queue->rear = 0;
    }else{
        queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
    }
    queue->data[queue->rear] = data;
}

// function to remove element from the front of the queue
struct BstNode *dequeue(struct BST_NODE_QUEUE *queue){
    if(isEmpty(*queue)){
        return;
    }
    // printf("Pointer: %d", queue->front);
    struct BstNode * return_value = queue->data[queue->front];

    // this means there is only one element in the array
    if(queue->front == queue->rear){
        queue->front = -1;
        queue->rear = -1;
    }
    else{
        queue->front = (queue->front + 1) % MAX_QUEUE_SIZE;
    }

    return return_value;
}

struct BstNode * peak_front(struct BST_NODE_QUEUE queue){
    if(!isEmpty(queue))
        return queue.data[queue.front];
}

struct BstNode *peak_rear(struct BST_NODE_QUEUE queue){
    if(!isEmpty(queue))
        return queue.data[queue.rear];
}

// function to print all the elements in the queue
void iqueue_print(struct BST_NODE_QUEUE queue){
    int index = queue.front;
    while(index != queue.rear){
        printf("%d ", queue.data[index]);
        index = (index + 1) % MAX_QUEUE_SIZE;
    }
    printf("%d ", queue.data[index]);
    printf("\n");
}

#endif;