#include "BST.h"
BSTNode* BuyBSTNode(BSTdatatype x){
    BSTNode* newnode = (BSTNode*)malloc(sizeof(BSTNode));
    if(newnode==NULL){
        printf("error");
        exit(-1);
    }
    newnode->data = x;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}
BSTNode* BSTreeInsert(BSTNode* root, BSTdatatype x){
    if (root == NULL) {
         return BuyBSTNode(x);
    }
    if(x<root->data){
        root->left = BSTreeInsert(root->left, x);
    }else if(x>root->data){
        root->right = BSTreeInsert(root->right, x);
    }else{
        printf("值已存在，无需插入");
    }
    return root;
}
BSTNode* BSTreeFind(BSTNode* root, BSTdatatype x){
    assert(root);
    if (x < root->data) {
        return BSTreeFind(root->left, x);
    } else if (x > root->data) {
        return BSTreeFind(root->right, x);
    } else {
        return root;
    }
}
BSTNode* BSTreeFindMin(BSTNode* root) {
    assert(root);
    while(root->left!=NULL){
        root = root->left;
    }
    return root;
}
BSTNode* BSTreeErase(BSTNode* root, BSTdatatype x) {
    if(root==NULL){
        return NULL;
    }
    if(x<root->data){
        root->left = BSTreeErase(root->left, x);
    }else if(x>root->data){
        root->right = BSTreeErase(root->right, x);
    }else{
        if(root->left==NULL){
            BSTNode* right = root->right;
            free(root);
            return right;
        }else if(root->right==NULL){
            BSTNode* left = root->left;
            free(root);
            return left;
        }else{
            BSTNode* minNode = BSTreeErase(root->right, minNode->data);
        }
    }
    return root;
}
void BSTreeInOrder(BSTNode* root){
    if(root==NULL){
        return;
    }
    BSTreeInOrder(root->left);
    printf("%d ", root->data);
    BSTreeInOrder(root->right);
}
int BSTreeSize(BSTNode* root){
    return root == NULL ? 0
                        : BSTreeSize(root->left) + BSTreeSize(root->right) + 1;
}
void BSTreeDestroy(BSTNode* root){
    if(root==NULL){
        return;
    }
    BSTreeDestroy(root->left);
    BSTreeDestroy(root->right);
    free(root);
    root = NULL;
}