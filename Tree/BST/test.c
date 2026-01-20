#include "BST.h"
int main() {
    BSTNode* root = NULL; 
    root = BSTreeInsert(root, 5);
    root = BSTreeInsert(root, 3);
    root = BSTreeInsert(root, 7);
    root = BSTreeInsert(root, 2);
    root = BSTreeInsert(root, 4);
    root = BSTreeInsert(root, 6);
    root = BSTreeInsert(root, 8);
    printf("\nBST中序遍历(升序)：");
    BSTreeInOrder(root);
    printf("\n");
    printf("BST节点总数：%d\n", BSTreeSize(root));
    BSTdatatype findVal1 = 4;
    BSTNode* findNode1 = BSTreeFind(root, findVal1);
    findNode1 ? printf("找到值\n")
              : printf("未找到值\n");
    // 删除叶子节点 2 (无左右孩子)
    printf("删除叶子节点 2 后，中序遍历：");
    root = BSTreeErase(root, 2);
    BSTreeInOrder(root);
    printf("\n");
    // 删除单孩子节点 8 (只有左孩子)
    printf("删除单孩子节点 8 后，中序遍历：");
    root = BSTreeErase(root, 8);
    BSTreeInOrder(root);
    printf("\n");
    // 删除双孩子节点 5 (根节点，左右都有孩子)
    printf("删除双孩子节点 5 后，中序遍历：");
    root = BSTreeErase(root, 5);
    BSTreeInOrder(root);
    printf("\n");
    BSTreeDestroy(root);
    root = NULL;
    return 0;
}
