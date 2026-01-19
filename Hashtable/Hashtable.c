#include "HashTable.h"
int Hashfunc(HTdatatype key){
    return key % HT_SIZE;
}
HashNode* BuyHashNode(HTdatatype key){
    HashNode* newnode = (HashNode*)malloc(sizeof(HashNode));
    if(newnode==NULL){
        printf("error");
        exit(-1);
    }
    newnode->key = key;
    newnode->next = NULL;
    return newnode;
}
void HashTableInit(HashTable* pht){
    assert(pht);
    for (int i = 0; i < HT_SIZE;i++){
        pht->table[i] = NULL;
    }
    pht->size = 0;
}
void HashTableDestroy(HashTable* pht){
    assert(pht);
    for (int i = 0; i < HT_SIZE;i++){
        HashNode* cur = pht->table[i];
        while(cur!=NULL){
            HashNode* next = cur->next;
            free(cur);
            cur = next;
        }
        pht->table[i] = NULL;
    }
    pht->size = 0;
}
void HashTableInsert(HashTable* pht, HTdatatype key){
    assert(pht);
    HashNode*newnode=BuyHashNode(key);
    int index = Hashfunc(key);
    newnode->next = pht->table[index];
    pht->table[index] = newnode;
    pht->size++;
}
bool HashTableFind(HashTable* pht, HTdatatype key){
    assert(pht);
    int index = Hashfunc(key);
    HashNode* cur = pht->table[index];
    while(cur!=NULL){
        if(cur->key==key){
            return true;
        }
        cur = cur->next;
    }
    return false;
}
void HashTableErase(HashTable* pht, HTdatatype key){
    assert(pht);
    int index = Hashfunc(key);
    HashNode* prev = NULL;
    HashNode* cur = pht->table[index];
    while(cur!=NULL){
        if(cur->key==key){
            if(prev==NULL){
                pht->table[index] = cur->next;
            }else{
                prev->next = cur->next;
            }
            free(cur);
            cur = NULL;
            pht->size--;
            return;
        }
        prev = cur;
        cur = cur->next;
    }
}
void HashTablePrint(HashTable* pht){
    assert(pht);
    for (int i = 0; i < HT_SIZE;i++){
        printf("下标%d:", i);
        HashNode* cur = pht->table[i];
        while(cur!=NULL){
            printf("%d -> ", cur->key);
            cur = cur->next;
        }
        printf("NULL\n");
    }
    printf("哈希表有效元素个数:%d\n", pht->size);
}