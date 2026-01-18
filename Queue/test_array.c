#include "Queue_array.h"
int main() {
    Queue q;
    QueueInit(&q);
    QueuePush(&q, 1);
    QueuePush(&q, 2);
    QueuePush(&q, 3);
    printf("队列元素个数：%d\n", QueueSize(&q));  
    printf("队头元素：%d\n", QueueFront(&q));         
    printf("队尾元素：%d\n", QueueBack(&q));         
    QueuePop(&q);
    QueueDestroy(&q);
    return 0;
}
