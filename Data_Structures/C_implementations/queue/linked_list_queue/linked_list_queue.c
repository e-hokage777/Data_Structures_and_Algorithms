#include <stdio.h>
#include <stdlib.h>
#include "./ll_queue.h"

int main(){
    struct L_Queue queue;
    queue.front = NULL;
    queue.rear = NULL;
    enqueue(&queue, 5);
    enqueue(&queue, 23);
    enqueue(&queue, 25);
    enqueue(&queue, 125);
    printf("Dequing %d\n", dequeue(&queue));
    printf("Dequing %d\n", dequeue(&queue));

    print(queue);
    return 0;
}