#include "BinaryTree.h"
int main() {
    BTNode* root = CreateBinaryTree();
    printf("前序遍历：");
    PreOrder(root);
    printf("\n");
    printf("中序遍历：");
    InOrder(root);
    printf("\n");
    printf("后序遍历：");
    PostOrder(root);
    printf("\n\n");
    printf("层序遍历：");
    LevelOrder(root);
    printf("\n");
    printf("二叉树总节点个数：%d\n", BinaryTreeSize(root));
    printf("二叉树的高度(最大深度)：%d\n", BinaryTreeHeight(root));
    printf("二叉树叶子节点个数：%d\n\n", BinaryTreeLeafSize(root));
    BTdatatype findVal = 5;
    BTNode* findNode = BinaryTreeFind(root, findVal);
    BinaryTreeDestroy(&root);
    printf("\n二叉树销毁完成，root = %p\n", root);
    return 0;
}
