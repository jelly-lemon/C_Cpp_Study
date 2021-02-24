/*
 * 遍历二叉树
 */
#include <stdio.h>
#include <stdlib.h>

// 使用 BiTree 创建的变量是指针变量，相当于 Node *p
typedef struct Node {
    char data;
    struct Node *lchild, *rchild;
}BiTNode, *BiTree;


/**
 * 先序输入二叉树
 *
 * @param T 指向根节点的指针变量的地址
 */
void createBiTreeByPre(BiTree *T) {
    char ch;

    if (T == NULL) {
        return;
    }

    scanf("%c", &ch);
    if(ch == '#') {
        *T = NULL;
    } else {
        *T = (BiTree)malloc(sizeof(BiTNode));
        if(*T == NULL) {
            exit(-1);
        } else {
            (*T)->data = ch;
            createBiTreeByPre(&(*T)->lchild);
            createBiTreeByPre(&(*T)->rchild);
        }
    }
}

/**
 * TODO 按层输入二叉树
 *
 * @param T 指向根节点的指针变量的地址
 */
void createBiTreeByLevel(BiTree *T) {
    char ch;

    if (T == NULL)
        return;
    scanf("%c", &ch);
    if (ch == '#')
        *T = NULL;
    else {
        *T = (BiTree)malloc(sizeof(BiTNode));
        if (*T == NULL)
            exit(-1);
        else {
            (*T)->data = ch;
        }
    }
}

/**
 * 递归先序遍历
 *
 * @param T
 */
void PreOrderTraverse(BiTree T) {
    if (T == NULL)
        return;
    printf("%c ", T->data);
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
}

/**
 * 递归中序遍历
 *
 * @param T
 */
void InOrderTraverse(BiTree T) {
    if (T == NULL)
        return;
    InOrderTraverse(T->lchild);
    printf("%c ", T->data);
    InOrderTraverse(T->rchild);
}

/**
 * 递归后序遍历
 *
 * @param T
 */
void PostOrderTraverse(BiTree T) {
    if (T == NULL)
        return;

    PostOrderTraverse(T->lchild);
    PostOrderTraverse(T->rchild);
    printf("%c ", T->data);
}

/**
 * 递归按层遍历
 *
 * @param T
 */
void LevelTraverse(BiTree T) {

}

int main() {
    BiTree root;
    createBiTreeByPre(&root);
    PreOrderTraverse(root);
    printf("\n");
    InOrderTraverse(root);
    printf("\n");
    PostOrderTraverse(root);
    printf("\n");


    return 0;
}