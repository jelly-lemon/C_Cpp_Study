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
    BiTree *tree_node;
    struct link_list_Node *next;
}List_Node;

/**
 * 初始化链表
 *
 * @return 链表头节点地址
 */
List_Node* init_list() {
    List_Node *pHead = (List_Node*)malloc(sizeof(List_Node));
    pHead->next = NULL;
    return pHead;
}

/**
 * 向链表中添加节点
 *
 * @param pHead 头节点地址
 * @param new_node 新节点地址
 */
void add(List_Node *pHead, List_Node *new_node) {
    if (pHead == NULL || new_node == NULL)
        return;

    List_Node *p = pHead->next;
    // 有可能只有头节点，所以 p 可能为 NULL
    if (p == NULL) {
        pHead->next = new_node;
    } else {
        while (p->next != NULL) {
            p = p->next;
        }
        p->next = new_node;
    }
    // 确保最后一个节点 next 指针域为 NULL
    new_node->next = NULL;
}

/**
 * 删除链表中第一个节点
 *
 * @param pHead 头节点地址
 * @return 被删除节点地址
 */
List_Node *pop(List_Node *pHead) {
    if (pHead == NULL || pHead->next == NULL)
        return NULL;

    List_Node *p = pHead->next;
    pHead->next = p->next;

    return p;
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
    char ch;
    BiTNode *t;
    List_Node *p;
    int count = 0;


    List_Node *pHead = init_list();

    if (pHead == NULL || T == NULL)
        return;

    ch = getchar();
    // 空树用指针变量值为空表示（不用创建一个新的节点存 # ）
    if (ch == '#') {
        *T = NULL;
        return;
    } else {
        // 创建根节点
        t = (BiTNode*)malloc(sizeof(BiTNode));
        t->data = ch;
        (*T) = t;

        // 节点两个指针变量放入队列
        p = (List_Node*)malloc(sizeof(List_Node));
        p->tree_node = &t->lchild;
        add(pHead, p);

        p = (List_Node*)malloc(sizeof(List_Node));
        p->tree_node = &t->rchild;
        add(pHead, p);
    }

    while ((p = pop(pHead)) != NULL) {
        if ((ch = getchar()) == '#') {
            *(p->tree_node) = NULL;
        } else {
            // 创建二叉树节点
            t = (BiTNode*)malloc(sizeof(BiTNode));
            t->data = ch;
            *(p->tree_node) = t;    // 父亲节点的孩子指针变量指向该新节点

            // 节点两个孩子指针变量队列
            p = (List_Node*)malloc(sizeof(List_Node));
            p->tree_node = &t->lchild;
            add(pHead, p);

            p = (List_Node*)malloc(sizeof(List_Node));
            p->tree_node = &t->rchild;
            add(pHead, p);
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
    BiTree root;    // 指向二叉树根节点的指针变量

    // 输入二叉树
//    createBiTreeByPre(&root);    // 先序输入二叉树
    createBiTreeByLevel(&root);



    // 递归方式遍历二叉树
    PreOrderTraverse(root);
    printf("\n");
    InOrderTraverse(root);
    printf("\n");
    PostOrderTraverse(root);
    printf("\n");


    return 0;
}