#include "AVLTree.h"
AVLNode* BuyAVLNode(AVLdatatype x){
    AVLNode* newnode = (AVLNode*)malloc(sizeof(AVLNode));
    if(newnode==NULL){
        printf("error");
        exit(-1);
    }
    newnode->data = x;
    newnode->height = 1;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}
int AVLNodeHeight(AVLNode* root){
    return root == NULL ? 0 : root->height;
}
int AVLBalanceFactor(AVLNode* root){
    if(root==NULL){
        return 0;
    }
    return AVLNodeHeight(root->left) - AVLNodeHeight(root->right);
}
void AVLUpdateHeight(AVLNode* root) {
    if(root==NULL){
        return;
    }
    int leftH = AVLNodeHeight(root->left);
    int rightH = AVLNodeHeight(root->right);
    root->height = (leftH > rightH ? leftH : rightH) + 1;
}
AVLNode* AVL_RotateLL(AVLNode* root){
    AVLNode* subL = root->left;
    AVLNode* subLR = subL->right;
    subL->right = root;
    root->left = subLR;
    AVLUpdateHeight(root);
    AVLUpdateHeight(subL);
    return subL;
}
AVLNode* AVL_RotateRR(AVLNode* root){
    AVLNode* subR = root->right;
    AVLNode* subRL = subR->left;
    subR->left = root;
    root->right = subRL;
    AVLUpdateHeight(root);
    AVLUpdateHeight(subR);
    return subR;
}
AVLNode* AVL_RotateLR(AVLNode* root){
    root->left = AVL_RotateRR(root->left);
    return AVL_RotateLL(root);
}
AVLNode* AVL_RotateRL(AVLNode* root){
    root->right = AVL_RotateLL(root->right);
    return AVL_RotateRR(root);
}
AVLNode* AVLTreeInsert(AVLNode* root, AVLdatatype x){
    if(root==NULL){
        return BuyAVLNode(x);
    }
    if(x<root->data){
        root->left = AVLTreeInsert(root->left, x);
    }else if(x>root->data){
        root->right = AVLTreeInsert(root->right, x);
    }else{
        printf("值已存在");
        return root;
    }
    AVLUpdateHeight(root);
    int bf = AVLBalanceFactor(root);
    if(bf>1&&AVLBalanceFactor(root->left)>=0){
        return AVL_RotateLL(root);
    }else if(bf<-1&&AVLBalanceFactor(root->right)<=0){
        return AVL_RotateRR(root);
    }else if(bf>1&&AVLBalanceFactor(root->left)<0){
        return AVL_RotateLR(root);
    }else if(bf<-1&&AVLBalanceFactor(root->right)>0){
        return AVL_RotateRL(root);
    }
    return root;
}
AVLNode* AVLTreeFind(AVLNode* root, AVLdatatype x){
    if(root==NULL){
        return NULL;
    }
    if(x<root->data){
        return AVLTreeFind(root->left, x);
    }else if(x>root->data){
        return AVLTreeFind(root->right, x);
    }else{
        return root;
    }
}
void AVLTreeInOrder(AVLNode* root){
    if(root==NULL){
        return;
    }
    AVLTreeInOrder(root->left);
    printf("%d ", root->data);
    AVLTreeInOrder(root->right);
}
bool AVLTreeIsBalance(AVLNode* root){
    if(root==NULL){
        return true;
    }
    int bf = AVLBalanceFactor(root);
    if(bf<-1||bf>1){
        printf("失衡节点：%d，平衡因子：%d\n", root->data, bf);
        return false;
    }
    return AVLTreeIsBalance(root->left) && AVLTreeIsBalance(root->right);
}
void AVLTreeDestroy(AVLNode* root){
    if(root==NULL){
        return;
    }
    AVLTreeDestroy(root->left);
    AVLTreeDestroy(root->right);
    free(root);
    root = NULL;
}