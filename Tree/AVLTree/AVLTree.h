#pragma once
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
typedef int AVLdatatype;
typedef struct AVLTreeNode{
    AVLdatatype data;
    struct AVLTreeNode* left;
    struct AVLTreeNode* right;
    int height;
} AVLNode;
AVLNode* BuyAVLNode(AVLdatatype x);   
int AVLNodeHeight(AVLNode* root);     
int AVLBalanceFactor(AVLNode* root);
void AVLUpdateHeight(AVLNode* root);
AVLNode* AVL_RotateLL(AVLNode* root);
AVLNode* AVL_RotateRR(AVLNode* root);  
AVLNode* AVLTreeInsert(AVLNode* root, AVLdatatype x); 
AVLNode* AVLTreeFind(AVLNode* root, AVLdatatype x);  
void AVLTreeInOrder(AVLNode* root);                 
bool AVLTreeIsBalance(AVLNode* root);               
void AVLTreeDestroy(AVLNode* root);                  
