#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
typedef int QTdatatype;
#define QUEUE_CAPACITY 5
typedef struct Queue{
    QTdatatype a[QUEUE_CAPACITY];
    int front;
    int last;
} Queue;
void QueueInit(Queue* pq);    
void QueueDestroy(Queue* pq);  
void QueuePush(Queue* pq, QTdatatype x); 
void QueuePop(Queue* pq);                
QTdatatype QueueFront(Queue* pq);      
QTdatatype QueueBack(Queue* pq);         
int QueueSize(Queue* pq);                
int QueueEmpty(Queue* pq);  