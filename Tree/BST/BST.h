#pragma once
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
typedef int BSTdatatype;
typedef struct BSTreeNode{
    BSTdatatype data;
    struct BSTreeNode* left;
    struct BSTreeNode* right;
} BSTNode;
BSTNode* BuyBSTNode(BSTdatatype x);                  
BSTNode* BSTreeInsert(BSTNode* root, BSTdatatype x);  
BSTNode* BSTreeFind(BSTNode* root, BSTdatatype x);
BSTNode* BSTreeFindMin(BSTNode* root);
BSTNode* BSTreeErase(BSTNode* root, BSTdatatype x);
void BSTreeInOrder(BSTNode* root);   
int BSTreeSize(BSTNode* root);       
void BSTreeDestroy(BSTNode* root);  