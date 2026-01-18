#include "Queue_array.h"
void QueueInit(Queue* pq){
    assert(pq);
    pq->front = 0;
    pq->last = 0;
}
void QueueDestroy(Queue* pq){
    assert(pq);
    pq->front = 0;
    pq->last = 0;
}
void QueuePush(Queue* pq, QTdatatype x){
    assert(pq);
    pq->a[pq->last] = x;
    pq->last=(pq->last + 1) % QUEUE_CAPACITY;
}
void QueuePop(Queue* pq){
    assert(pq);
    if(QueueEmpty(pq)){
        return;
    }
    pq->front = (pq->front + 1) % QUEUE_CAPACITY;
}
QTdatatype QueueFront(Queue* pq){
    assert(pq);
    return pq->a[pq->front];
}
QTdatatype QueueBack(Queue* pq){
    assert(pq);
    return pq->a[(pq->last - 1 + QUEUE_CAPACITY) % QUEUE_CAPACITY];
}
int QueueSize(Queue* pq){
    assert(pq);
    return (pq->last - pq->front + QUEUE_CAPACITY) % QUEUE_CAPACITY;
}
int QueueEmpty(Queue* pq){
    assert(pq);
    return pq->front == pq->last;
}