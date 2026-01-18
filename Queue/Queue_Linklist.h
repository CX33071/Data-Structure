#pragma once
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
typedef int QTdatatype;
typedef struct Queuenode{
    QTdatatype data;
    struct Queuenode* next;
} Queuenode;
typedef struct Queue{
    Queuenode* phead;
    Queuenode* ptail;
} Queue;
Queuenode* Buyqueuenode(QTdatatype x);
void QueueInit(Queue* pq);
void QueueDestroy(Queue* pq);          
void QueuePush(Queue* pq, QTdatatype x);  
void QueuePop(Queue* pq);                 
QTdatatype QueueFront(Queue* pq);        
QTdatatype QueueBack(Queue* pq);        
int QueueSize(Queue* pq);                 
int QueueEmpty(Queue* pq); 