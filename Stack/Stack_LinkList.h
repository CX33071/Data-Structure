#pragma once
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
typedef int STdatatype;
typedef struct Stacknode{
    STdatatype data;
    struct Stacknode* next;
} Stacknode;
typedef struct Stack{
    Stacknode* phead;
} Stack;
Stacknode* Buystacknode(STdatatype x);
void StackInit(Stack* ps);
void StackDestroy(Stack* ps);            
void StackPush(Stack* ps, STdatatype x);  
void StackPop(Stack* ps);                 
STdatatype StackTop(Stack* ps);           
int StackSize(Stack* ps);                
int StackEmpty(Stack* ps);              
