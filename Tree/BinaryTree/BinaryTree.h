#pragma once
#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
typedef int BTdatatype;
typedef struct BinaryTreeNode {
    BTdatatype data;
    struct BinaryTreeNode* left;
    struct BinaryTreeNode* right;
} BTNode;
typedef struct Queuenode {
    BTNode* data;
    struct Queuenode* next;
} Queuenode;
typedef struct Queue {
    Queuenode* phead;
    Queuenode* ptail;
} Queue;
Queuenode* BuyQueueNode(BTNode* x);
void QueueInit(Queue* pq);
void QueueDestroy(Queue* pq);
void QueuePush(Queue* pq, BTNode* x);
void QueuePop(Queue* pq);
BTNode* QueueFront(Queue* pq);
bool QueueEmpty(Queue* pq);
BTNode* BuyBTNode(BTdatatype x);
BTNode* CreateBinaryTree();
void PreOrder(BTNode* root);
void InOrder(BTNode* root);
void PostOrder(BTNode* root);
void LevelOrder(BTNode* root);
int BinaryTreeSize(BTNode* root);
int BinaryTreeHeight(BTNode* root);
int BinaryTreeLeafSize(BTNode* root);
BTNode* BinaryTreeFind(BTNode* root, BTdatatype x);
void BinaryTreeDestroy(BTNode** root);
