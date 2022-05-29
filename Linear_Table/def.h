//#include "C:/Users/86072/Documents/Clanguage/Datastructure_408/Linear_Table/def.h"
#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include <string.h>
#include <iostream>
using namespace std;


#define ERROR -1
#define INT_MAX 2147483647
#define BIG_NUM 100

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
    if(L == NULL){
        printf("Linklist is empty!\n");
        return;
    }
    LNode* p = L;
    while (p != NULL){
        printf("%d",p->data);
        p = p->next;
        if(p != NULL)
            printf("->");
    }
    printf("\n");
    return;
}

void printList_withHead(LinkList L){
    if(L == NULL || L->next == NULL){
        printf("Linklist is empty!\n");
        return;
    }
    LNode* p = L->next;
    while (p != NULL){
        printf("%d",p->data);
        p = p->next;
        if(p != NULL)
            printf("->");
    }
    printf("\n");
    return;
}

int ListLength_withHead(LinkList L){
    if(L == NULL) 
        return ERROR;
    int len = 0;
    for(LNode* cur = L->next; cur != NULL; cur = cur->next)
        len++;
    return len;
}

bool isNULL_withHead(LinkList L){
    return L == NULL || L->next == NULL ? true : false;
}

bool isNULL_withoutHead(LinkList L){
    return L == NULL ? true : false;
}

char* list2string_withHead(LinkList L, int len){
    if(isNULL_withHead(L))
        return NULL;
    char* str = (char*)malloc(sizeof(char) * len);
    LNode* p = L->next;
    for(int i = 0; p != NULL && i < len; p = p->next, i++){
        *(str + i) = p->data + '0';
        *(str + i + 1) = '\0';
    }
    return str;
}

char* list2string_withoutHead(LinkList L, int len){
    if(isNULL_withoutHead(L))
        return NULL;
    char* str = (char*)malloc(sizeof(char) * len);
    LNode* p = L;
    for(int i = 0; p != NULL && i < len; p = p->next, i++){
        *(str + i) = p->data + '0';
        *(str + i + 1) = '\0';
    }
    return str;
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