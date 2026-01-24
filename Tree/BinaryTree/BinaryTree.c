#include "BinaryTree.h"
Queuenode* BuyQueueNode(BTNode* x) {
    Queuenode* newnode = (Queuenode*)malloc(sizeof(Queuenode));
    if (newnode == NULL) {
        printf("error");
        exit(-1);
    }
    newnode->data = x;
    newnode->next = NULL;
    return newnode;
}
void QueueInit(Queue* pq) {
    assert(pq);
    pq->phead = NULL;
    pq->ptail = NULL;
}
void QueueDestroy(Queue* pq) {
    assert(pq);
    Queuenode* cur = pq->phead;
    while (cur != NULL) {
        Queuenode* next = cur->next;
        free(cur);
        cur = next;
    }
    pq->phead = pq->ptail = NULL;
}
void QueuePush(Queue* pq, BTNode* x) {
    assert(pq);
    Queuenode* newnode = BuyQueueNode(x);
    if (pq->phead == NULL) {
        pq->phead = pq->ptail = newnode;
    } else {
        pq->ptail->next = newnode;
        pq->ptail = newnode;
    }
}
void QueuePop(Queue* pq) {
    assert(pq);
    if (QueueEmpty(pq)) {
        return;
    }
    Queuenode* temp = pq->phead;
    pq->phead = pq->phead->next;
    free(temp);
    temp = NULL;
    if (pq->phead == NULL) {
        pq->ptail = NULL;
    }
}
BTNode* QueueFront(Queue* pq) {
    assert(pq);
    return pq->phead->data;
}
bool QueueEmpty(Queue* pq) {
    assert(pq);
    return pq->phead == NULL;
}
BTNode* BuyBTNode(BTdatatype x) {
    BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
    if (newnode == NULL) {
        printf("error");
        exit(-1);
    }
    newnode->data = x;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}
BTNode* CreateBinaryTree() {
    BTNode* n1 = BuyBTNode(1);
    BTNode* n2 = BuyBTNode(2);
    BTNode* n3 = BuyBTNode(3);
    BTNode* n4 = BuyBTNode(4);
    BTNode* n5 = BuyBTNode(5);
    BTNode* n6 = BuyBTNode(6);
    n1->left = n2;
    n1->right = n3;
    n2->left = n4;
    n2->right = n5;
    n3->left = n6;
    return n1;
}
void PreOrder(BTNode* root) {
    if (root == NULL) {
        printf("NULL");
        return;
    }
    printf("%d ", root->data);
    PreOrder(root->left);
    PreOrder(root->right);
}
void InOrder(BTNode* root) {
    if (root == NULL) {
        printf("NULL");
        return;
    }
    InOrder(root->left);
    printf("%d ", root->data);
    InOrder(root->right);
}
void PostOrder(BTNode* root) {
    if (root == NULL) {
        printf("NULL ");
        return;
    }
    PostOrder(root->left);
    PostOrder(root->right);
    printf("%d ", root->data);
}
void LevelOrder(BTNode* root) {
    if (root == NULL) {
        return;
    }
    Queue q;
    QueueInit(&q);
    QueuePush(&q, root);
    while (!QueueEmpty(&q)) {
        BTNode* front = QueueFront(&q);
        QueuePop(&q);
        printf("%d ", front->data);
        if (front->left != NULL) {
            QueuePush(&q, front->left);
        }
        if (front->right != NULL) {
            QueuePush(&q, front->right);
        }
    }
    QueueDestroy(&q);
}
int BinaryTreeSize(BTNode* root) {
    return root == NULL
               ? 0
               : BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
}
int BinaryTreeHeight(BTNode* root) {
    if (root == NULL) {
        return 0;
    } else {
        int leftheight = BinaryTreeSize(root->left);
        int rightheight = BinaryTreeSize(root->right);
        return leftheight > rightheight ? leftheight + 1 : rightheight + 1;
    }
}
int BinaryTreeLeafSize(BTNode* root) {
    if (root == NULL) {
        return 0;
    }
    if (root->left == NULL && root->right == NULL) {
        return 1;
    }
        return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}
BTNode* BinaryTreeFind(BTNode* root, BTdatatype x) {
    if (root == NULL) {
        return NULL;
    }
    if (root->data == x) {
        return root;
    }
    BTNode* leftret = BinaryTreeFind(root->left, x);
    BTNode* rightret = BinaryTreeFind(root->right, x);
    if (leftret != NULL) {
        return leftret;
    }
    if (rightret != NULL) {
        return rightret;
    }
    return NULL;
}
void BinaryTreeDestroy(BTNode** root) {
    assert(root);
    if (*root == NULL) {
        return;
    }
    BinaryTreeDestroy(&((*root)->left));
    BinaryTreeDestroy(&((*root)->right));
    free(*root);
    *root = NULL;
}