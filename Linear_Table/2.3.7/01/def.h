#include <stdio.h>
#include <malloc.h>

typedef int Elemtype;
typedef struct LNode{
    Elemtype data;
    struct LNode *next;
}LNode,*LinkList;

void InitList_withHead(LinkList L, Elemtype Init[],int len){
    LNode *cur = L;
    for(int i = 0; i < len; i++){
        LNode *p = (LNode*)malloc(sizeof(LNode));
        p->data = Init[i];
        cur->next = p;
        cur = p;
    }
    cur = NULL;
    return;
}

void InitList_withoutHead(LinkList L, Elemtype Init[],int len){
    L = (LNode*)malloc(sizeof(LNode));
    LNode *save = L;
    for(int i = 0; i < len; i++){
        L->data = Init[i];
        L->next = (LNode*)malloc(sizeof(LNode));
        L = L->next;
    }
    L = NULL;
    L = save;
    return;
}

void printList(LinkList L){
    LNode* p = L->next;
    while (p != NULL){
        printf("%d",p->data);
        p = p->next;
        if(p != NULL)
            printf("->");
    }
    return;
}