#ifndef IQUEUE_H
#define IQUEUE_H

#include <stdio.h>
#include <stdlib.h>

#define MAX_QUEUE_SIZE 3


struct I_Queue{
    int front;
    int rear;
    int data[MAX_QUEUE_SIZE];
};

// function to check if the queue is empty
int isEmpty(struct I_Queue queue){
    return ((queue.front == -1) && (queue.rear == -1));
}

// function to add element at the rear of the queue
void enqueue(struct I_Queue *queue, int data){
    if(isEmpty(*queue)){
        printf("first enqueue\n");
        queue->front = queue->rear = 0;
    }else{
        queue->rear = (queue->rear + 1) % MAX_QUEUE_SIZE;
    }
    queue->data[queue->rear] = data;
}

// function to remove element from the front of the queue
int dequeue(struct I_Queue *queue){
    if(isEmpty(*queue)){
        return;
    }

    int return_value = queue->data[queue->front];

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

int peak_front(struct I_Queue queue){
    if(!isEmpty(queue))
        return queue.data[queue.front];
}

int peak_rear(struct I_Queue queue){
    if(!isEmpty(queue))
        return queue.data[queue.rear];
}

// function to print all the elements in the queue
void iqueue_print(struct I_Queue queue){
    int index = queue.front;
    while(index != queue.rear){
        printf("%d ", queue.data[index]);
        index = (index + 1) % MAX_QUEUE_SIZE;
    }
    printf("%d ", queue.data[index]);
    printf("\n");
}

#endif;