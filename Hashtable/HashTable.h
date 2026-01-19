#pragma once
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
typedef int HTdatatype;
typedef struct HashNode {
    HTdatatype key;
    struct HashNode* next;
} HashNode;
#define HT_SIZE 10
typedef struct HashTable {
    HashNode* table[HT_SIZE];
    int size;
} HashTable;
void HashTableInit(HashTable* pht);
void HashTableDestroy(HashTable* pht);
HashNode* BuyHashNode(HTdatatype key);
void HashTableInsert(HashTable* pht, HTdatatype key);
bool HashTableFind(HashTable* pht, HTdatatype key);
void HashTableErase(HashTable* pht, HTdatatype key);
void HashTablePrint(HashTable* pht);
