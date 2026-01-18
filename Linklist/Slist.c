#include "Slist.h"
Slistnode* Buylistnode(Sldatatype x){
    Slistnode* newnode = (Slistnode*)malloc(sizeof(Slistnode));
    if(newnode==NULL){
        printf("error");
        exit(EXIT_FAILURE);
    }
    newnode->data = x;
    newnode->next = NULL;
    return newnode;
}
void SlistPrint(Slistnode* phead){
    Slistnode* cur = phead;
    while(cur!=NULL){
        printf("%d -> ", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}
void SlistPushBack(Slistnode** pphead, Sldatatype x){
    assert(pphead);
    Slistnode* newnode = Buylistnode(x);
    if(*pphead==NULL){
        *pphead = newnode;
    }else{
        Slistnode* temp = *pphead;
        while(temp->next!=NULL){
            temp = temp->next;
        }
        temp->next = newnode;
    }
}
void SlistPushFront(Slistnode** pphead, Sldatatype x){
    assert(pphead);
    Slistnode* newnode = Buylistnode(x);
    newnode->next = *pphead;
    *pphead = newnode;
}
void SlistPopBack(Slistnode** pphead){
    assert(pphead);
    if(*pphead==NULL){
        return;
    }
    if((*pphead)->next==NULL){
        free(*pphead);
        *pphead = NULL;
    }else{
        Slistnode* prev = NULL;
        Slistnode* tail = *pphead;
        while(tail->next!=NULL){
            prev = tail;
            tail = tail->next;
        }
        free(tail);
        prev->next = NULL;
    }
}
void SlistPopFront(Slistnode** pphead){
    assert(pphead);
    if(*pphead==NULL){
        return;
    }
    Slistnode* temp = *pphead;
    *pphead = (*pphead)->next;
    free(temp);
    temp = NULL;
}
Slistnode* SlistFind(Slistnode* phead, Sldatatype x){
    Slistnode* cur = phead;
    while(cur!=NULL){
        if(cur->data==x){
            return cur;
        }
        cur = cur->next;
    }
    return NULL;
}
void SlistInsert(Slistnode** phead, Slistnode* pos, Sldatatype x){
    assert(phead);
    if(pos==*phead){
        SlistPushFront(phead, x);
    }else{
        Slistnode* prev = *phead;
        while(prev->next!=pos){
            prev = prev->next;
        }
        Slistnode* newnode = Buylistnode(x);
        prev->next = newnode;
        newnode->next = pos;
    }
}
void SlistInsertAfter(Slistnode** phead, Slistnode* pos, Sldatatype x){
    assert(phead);
    if(*phead==NULL){
        return;
    }
    Slistnode* newnode = Buylistnode(x);
    newnode->next = pos->next;
    pos->next = newnode;
}
void SlistErase(Slistnode** pphead, Slistnode* pos){
    assert(pphead);
    if(*pphead==NULL){
        return;
    }
    if(pos==*pphead){
        SlistPopFront(pphead);
    }else{
        Slistnode* prev = *pphead;
        while(prev->next!=pos){
            prev = prev->next;
        }
        prev->next = pos->next;
        free(pos);
        pos = NULL;
    }
}
void SlistDestroy(Slistnode** pphead){
    assert(pphead);
    Slistnode* cur = *pphead;
    while(cur!=NULL){
        Slistnode* next = cur->next;
        free(cur);
        cur = next;
    }
    *pphead = NULL;
}