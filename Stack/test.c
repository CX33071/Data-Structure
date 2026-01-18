#include "Stack.h"
int main() {
    Stack st;
    StackInit(&st);  
    StackPush(&st, 1);
    StackPush(&st, 2);
    StackPush(&st, 3);
    printf("%d\n", StackSize(&st));  
    printf("%d\n", StackTop(&st));          
    StackPop(&st);
    printf("%d\n", StackTop(&st));  
    StackPop(&st);
    printf("%d\n", StackTop(&st)); 
    printf("%d\n", StackEmpty(&st));  
    StackDestroy(&st);
    return 0;
}
