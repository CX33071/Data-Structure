#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
typedef int Sldatatype;
typedef struct Slistnode{
    Sldatatype data;
    struct Slistnode* next;
} Slistnode;
void SlistPrint(Slistnode* phead);
Slistnode* Buylistnode(Sldatatype x);
void SlistPushBack(Slistnode** pphead, Sldatatype x);
void SlistPushFront(Slistnode** pphead, Sldatatype x);  
void SlistPopBack(Slistnode** pphead);
void SlistPopFront(Slistnode** pphead);  
Slistnode* SlistFind(Slistnode* phead, Sldatatype x);
void SlistInsert(Slistnode** phead,
                 Slistnode* pos,
                 Sldatatype x);  
void SlistInsertAfter(Slistnode** phead, Slistnode* pos, Sldatatype x);
void SlistErase(Slistnode** pphead, Slistnode* pos);
void SlistDestroy(Slistnode** pphead);