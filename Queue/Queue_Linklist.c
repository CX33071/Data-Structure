#include "Queue_Linklist.h"
Queuenode* Buyqueuenode(QTdatatype x){
    Queuenode* newnode = (Queuenode*)malloc(sizeof(Queuenode));
    if(newnode==NULL){
        printf("error");
        exit(-1);
    }
    newnode->data = x;
    newnode->next = NULL;
    return newnode;
}
void QueueInit(Queue* pq){
    assert(pq);
    pq->phead = NULL;
    pq->ptail = NULL;
}
void QueueDestroy(Queue* pq){
    assert(pq);
    Queuenode* cur = pq->phead;
    while(cur!=NULL){
        Queuenode* next = cur->next;
        free(cur);
        cur = next;
    }
    pq->phead = NULL;
    pq->ptail = NULL;
}
void QueuePush(Queue* pq, QTdatatype x){
    assert(pq);
    Queuenode* newnode = Buyqueuenode(x);
    if(pq->phead==NULL){
        pq->phead = newnode;
        pq->ptail = newnode;
    }else{
        pq->ptail->next = newnode;
        pq->ptail = newnode;
    }
}
void QueuePop(Queue* pq){
    assert(pq);
    if(QueueEmpty(pq)){
        return;
    }
    Queuenode* temp = pq->phead;
    pq->phead = pq->phead->next;
    free(temp);
    temp = NULL;
    if(pq->phead==NULL){
        pq->ptail = NULL;
    }
}
QTdatatype QueueFront(Queue* pq){
    assert(pq);
    if(pq->phead==NULL){
        exit(-1);
    }
    return pq->phead->data;
}
QTdatatype QueueBack(Queue* pq){
    assert(pq);
    if(pq->phead==NULL){
        exit(-1);
    }
    return pq->ptail->data;
}
int QueueSize(Queue* pq){
    assert(pq);
    int count = 0;
    Queuenode* cur = pq->phead;
    while(cur!=NULL){
        count++;
        cur = cur->next;
    }
    return count;
}
int QueueEmpty(Queue* pq){
    assert(pq);
    if(pq->phead==NULL){
        return 1;
    }
    return 0;
}
