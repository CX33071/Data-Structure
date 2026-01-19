#include "HashTable.h"
int main() {
    HashTable ht;
    HashTableInit(&ht);
    HashTableInsert(&ht, 1);
    HashTableInsert(&ht, 11);
    HashTableInsert(&ht, 21);
    HashTablePrint(&ht);
    printf("\n查找元素11：%s\n", HashTableFind(&ht, 11) ? "找到" : "没找到");
    HashTableErase(&ht, 11);
    HashTablePrint(&ht);
    HashTableDestroy(&ht);
    return 0;
}
