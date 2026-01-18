#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
// #define N 10
// typedef struct Stack{
//     int a[N];
//     int top;
// } Stack;
typedef int STdatatype;
typedef struct Stack{
    STdatatype* a;
    int top;
    int capacity;
} Stack;
void StackCheckCapacity(Stack* ps);
void StackInit(Stack* ps);
void StackDestroy(Stack* ps);            
void StackPush(Stack* ps, STdatatype x);  
void StackPop(Stack* ps);                 
STdatatype StackTop(Stack* ps);           
int StackSize(Stack* ps);                 
int StackEmpty(Stack* ps);               
