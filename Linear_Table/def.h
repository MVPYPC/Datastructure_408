//#include "C:/Users/86072/Documents/Clanguage/Datastructure_408/Linear_Table/def.h"
#include <stdio.h>
#include <malloc.h>
using namespace std;
#define ERROR -1
#define INT_MAX 2147483647

typedef int Elemtype;
typedef struct LNode{
    Elemtype data;
    struct LNode *next;
}LNode,*LinkList;

LinkList InitList_withHead(Elemtype Init[],int len){
    LNode *head = (LNode*)malloc(sizeof(LNode));
    LNode *cur = head;
    for(int i = 0; i < len; i++){
        LNode *p = (LNode*)malloc(sizeof(LNode));
        p->data = Init[i];
        cur->next = p;
        cur = p;
    }
    cur->next = NULL;
    return head;
}

LinkList InitList_withoutHead(Elemtype Init[],int len){
    LinkList L = (LNode*)malloc(sizeof(LNode));
    LNode *save = L;
    for(int i = 0; i < len; i++){
        L->data = Init[i];
        if(i == len - 1)
            L->next = NULL;
        else{
            L->next = (LNode*)malloc(sizeof(LNode));
            L = L->next;
        }
    }
    return save;
}

void printList_withoutHead(LinkList L){
    LNode* p = L;
    while (p != NULL){
        printf("%d",p->data);
        p = p->next;
        if(p != NULL)
            printf("->");
    }
    return;
}

void printList_withHead(LinkList L){
    LNode* p = L->next;
    while (p != NULL){
        printf("%d",p->data);
        p = p->next;
        if(p != NULL)
            printf("->");
    }
    return;
}

typedef struct stack{
    Elemtype data;
    struct stack* next;
}StackNode,*Stack;

Elemtype popStack(Stack& S){
    if(S == NULL)
        return ERROR;
    Elemtype top = S->data;
    S = S->next;
    return top;
}

void pushStack(Stack& S,Elemtype x){
    StackNode* in = (StackNode*)malloc(sizeof(StackNode));
    in->data = x;
    in->next = S;
    S = in;
}

bool isEmpty(Stack S){
    if(S == NULL)
        return true;
    else return false;
}