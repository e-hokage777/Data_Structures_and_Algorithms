#include <stdio.h>
#include <stdlib.h>
#include "./i_queue.h"

int main(){
    struct I_Queue queue;
    queue.front = -1;
    queue.rear = -1;
    enqueue(&queue, 10);
    enqueue(&queue, 3);
    enqueue(&queue, 5);
    dequeue(&queue);
    enqueue(&queue, 256);
    printf("Front of Queue: %d\n", peak_front(queue));
    printf("Rear of Queue: %d\n", peak_rear(queue));
    printf("%d %d\n", queue.front, queue.rear);
    iqueue_print(queue);
    return 0;
}