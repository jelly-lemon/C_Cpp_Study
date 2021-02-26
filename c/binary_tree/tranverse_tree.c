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

// 链表，用来构建队列
typedef struct link_list_Node {
    BiTNode *tree_node_addr;
    struct link_list_Node *next;
}List_Node;

void add(List_Node *pHead, BiTree *T) {
    if (pHead == NULL)
        return;

    List_Node *p = pHead->next;
    while (p->next != NULL) {
        p = p->next;
    }

    List_Node *new_node = (List_Node*)malloc(sizeof(List_Node));
    new_node->tree_node_addr = *T;
    p->next = new_node;
}

BiTNode *pop(List_Node *pHead) {
    if (pHead == NULL || pHead->next == NULL)
        return NULL;

    List_Node *p = pHead->next;
    pHead->next = p->next;

    return p->tree_node_addr;
}

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
 * 按层输入二叉树
 *
 * @param T 指向根节点的指针变量的地址
 */
void createBiTreeByLevel(BiTree *T) {
    // TODO 被二维指针搞晕
    char ch;
    List_Node *pHead = (List_Node*)malloc(sizeof(List_Node));
    BiTNode *t;

    if (T == NULL || *T == NULL)
        return;


    add(pHead, T);

    while ((ch = getchar()) != '\n') {
        t = pop(pHead);
        // 只输入一个 # 表示空二叉树
        if (ch == '#') {
            t = NULL; // 根节点指针变量直接置为 NULL
        } else {
            t = (BiTNode*)malloc(sizeof(BiTNode));
            t->data = ch;
            add(pHead, t->lchild);
            add(pHead, t->rchild);
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
    BiTree root;    // 根节点
    createBiTreeByPre(&root);
    PreOrderTraverse(root);
    printf("\n");
    InOrderTraverse(root);
    printf("\n");
    PostOrderTraverse(root);
    printf("\n");


    return 0;
}