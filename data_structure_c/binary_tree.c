/*
 * 二叉树的链式存储
 * */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define DataType char

typedef struct BinaryNode {
    DataType data;
    struct BinaryNode *lchild;
    struct BinaryNode *rchild;
    struct BinaryNode *parent;
} Tree;


//创建二叉树
Tree* CreateBtTree() {
    char data = getchar();
    struct BinaryNode *tree;
    //清除缓存
    while (getchar() != '\n') {
        continue;
    }
    if (data == '#') {
        tree = NULL;
    } else {
        struct BinaryNode *node = (struct BinaryNode*)malloc(sizeof(struct BinaryNode));
        memset(node, 0, sizeof(struct BinaryNode));
        node->data = data;
        tree = node;
        tree->lchild = CreateBtTree();
        tree->rchild = CreateBtTree();
   }
   return tree;
}


//先序遍历DLR
void PreorderTraversal(Tree *tree) {
    if (tree == NULL) {
        return;
    }
    printf("%c ", tree->data);
    PreorderTraversal(tree->lchild);
    PreorderTraversal(tree->rchild);
}

//中序遍历LDR
void InorderTraversal(Tree *tree) {
    if (tree == NULL) {
        return;
    }
    InorderTraversal(tree->lchild);
    printf("%c ", tree->data);
    InorderTraversal(tree->rchild);
}

//后序遍历LRD
void PostorderTraversal(Tree *tree) {
    if (tree == NULL) {
        return;
    }
    PostorderTraversal(tree->lchild);
    PostorderTraversal(tree->rchild);
    printf("%c", tree->data);
}

int main() {
    Tree *tree = CreateBtTree();
    printf("先序遍历\n");
    PreorderTraversal(tree);
    printf("\n");
    printf("中序遍历\n");
    InorderTraversal(tree);
}
