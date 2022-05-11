#include <stdio.h>
#include <malloc.h>

typedef int Elemtype;
typedef struct LNode{
    Elemtype data;
    struct LNode *next;
}LNode,*LinkList;

void InitList(LinkList L, Elemtype Init[]){
    LNode *cur = L;
    for(int i = 0; i < sizeof(Init) / sizeof(Elemtype); i++){
        LNode *p = (LNode*)malloc(sizeof(LNode));
        p->data = Init[i];
        cur->next = p;
        cur = p;
    }
    cur = NULL;
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