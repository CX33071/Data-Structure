#include "Stack_array.h"
void StackCheckCapacity(Stack* ps){
    assert(ps);
    if(ps->top==ps->capacity){
        int newcapacity = ps->capacity == 0 ? 2 : ps->capacity * 2;
        STdatatype* temp =
            (STdatatype*)realloc(ps->a, sizeof(STdatatype) * newcapacity);
            if(temp==NULL){
                printf("error");
                return;
            }
            ps->a = temp;
            ps->capacity = newcapacity;
    }
}
void StackInit(Stack* ps){
    assert(ps);
    ps->a = NULL;
    ps->capacity = 0;
    ps->top = 0;
}
void StackDestroy(Stack* ps){
    assert(ps);
    if(ps->a!=NULL){
        free(ps->a);
        ps->a = NULL;
    }
    ps->top = 0;
    ps->capacity = 0;
}
void StackPush(Stack* ps, STdatatype x){
    assert(ps);
    StackCheckCapacity(ps);
    ps->a[ps->top] = x;
    ps->top++;
}
void StackPop(Stack* ps){
    assert(ps);
    if(StackEmpty(ps)){
        printf("error");
        return;
    }
    ps->top--;
}
STdatatype StackTop(Stack* ps){
    assert(ps);
    if(StackEmpty(ps)){
        printf("error");
        return -1;
    }
    return ps->a[ps->top - 1];
}
int StackSize(Stack* ps){
    assert(ps);
    return ps->top;
}
int StackEmpty(Stack* ps){
    assert(ps);
    return ps->top == 0;
}