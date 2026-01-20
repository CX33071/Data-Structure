#include "AVLTree.h"
int main() {
    AVLNode* root = NULL;
    root = AVLTreeInsert(root, 1);
    root = AVLTreeInsert(root, 2);
    root = AVLTreeInsert(root, 3);
    root = AVLTreeInsert(root, 4);
    root = AVLTreeInsert(root, 5);
    printf("AVL树中序遍历（升序）：");
    AVLTreeInOrder(root);
    printf("\n");
    bool isBalance = AVLTreeIsBalance(root);
    printf("AVL树是否平衡：%s\n", isBalance ? "是" : "否");
    AVLdatatype findVal = 3;
    AVLNode* findNode = AVLTreeFind(root, findVal);
    findNode ? printf("找到值：%d\n", findVal)
             : printf("未找到值：%d\n", findVal);
    AVLTreeDestroy(root);
    root = NULL;
    return 0;
}
