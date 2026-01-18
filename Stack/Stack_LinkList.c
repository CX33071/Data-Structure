#include "Stack_LinkList.h"
Stacknode* Buystacknode(STdatatype x){
    Stacknode* newnode = (Stacknode*)malloc(sizeof(Stacknode));
    if(newnode==NULL){
        printf("error");
        exit(-1);
    }
    newnode->data = x;
    newnode->next = NULL;
    return newnode;
}
void StackInit(Stack* ps){
    assert(ps);
    ps->phead = NULL;
}
void StackDestroy(Stack* ps){
    assert(ps);
    Stacknode* cur = ps->phead;
    while(cur!=NULL){
        Stacknode* next = cur->next;
        free(cur);
        cur = next;
    }
    ps->phead = NULL;
}
void StackPush(Stack* ps, STdatatype x){
    assert(ps);
    Stacknode* newnode = Buystacknode(x);
    newnode->next = ps->phead;
    ps->phead = newnode;
}
void StackPop(Stack* ps){
    assert(ps);
    if(StackEmpty(ps)){
        return;
    }
    Stacknode* cur = ps->phead;
    ps->phead = ps->phead->next;
    free(cur);
    cur = NULL;
}
STdatatype StackTop(Stack* ps){
    assert(ps);
    if(StackEmpty(ps)){
        exit(-1);
    }
    return ps->phead->data;
}
int StackSize(Stack* ps){
    assert(ps);
    int count = 0;
    Stacknode* cur = ps->phead;
    while(cur!=NULL){
        count++;
        cur = cur->next;
    }
    return count;
}
int StackEmpty(Stack* ps){
    assert(ps);
    return ps->phead == NULL;
}
