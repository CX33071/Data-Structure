#include "Queue_Linklist.h"
int main() {
    Queue q;
    QueueInit(&q); 
    QueuePush(&q, 1);
    QueuePush(&q, 2);
    QueuePush(&q, 3);
    printf("元素个数：%d\n", QueueSize(&q));  
    printf("队头元素：%d\n", QueueFront(&q));       
    printf("队尾元素：%d\n", QueueBack(&q));         
    QueuePop(&q);
    printf("出队后队头元素：%d\n", QueueFront(&q));  
    printf("队列是否为空：%d\n", QueueEmpty(&q));   
    QueueDestroy(&q);
    return 0;
}
