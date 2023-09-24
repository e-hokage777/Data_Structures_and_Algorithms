#include <stdio.h>
#include <stdlib.h>
#include "./i_queue.h"

int main(){
    struct I_Queue queue;
    queue.front = -1;
    queue.front = -1;
    enqueue(&queue, 10);
    enqueue(&queue, 3);
    enqueue(&queue, 5);
    dequeue(&queue);
    iqueue_print(queue);
    return 0;
}