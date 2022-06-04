//#include "C:/Users/86072/Documents/Clanguage/Datastructure_408/def.h"
#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include <string.h>
#include <iostream>
using namespace std;


#define ERROR -1
#define MAX_SIZE 50
#define INT_MAX 2147483647
#define BIG_NUM 100

typedef int Elemtype;


/***********************************
 * 顺序表结构定义及常用函数
 * *************************************/
typedef struct {
    Elemtype data[MAX_SIZE];
    int length;
}SqList;

void initSqList(SqList& L, Elemtype init[], int len){
    for(int i = 0; i < len; i++)
        L.data[i] = init[i];
    L.length = len;
    return;
}

void printSqList(SqList L){
    cout<<"**************"<<endl;
    for(int i = 0; i < L.length; i++)
        cout<<"data: "<<L.data[i]<<endl;
    cout<<"length:"<<L.length<<endl;
    cout<<"**************"<<endl;
}

void printBool(bool i){
    if(i)
        cout<<"true"<<endl;
    else 
        cout<<"false"<<endl;
    return;
}

/**********************************
 * 单链表结构定义及常用相关函数
 **********************************/
typedef struct LNode{
    Elemtype data;
    struct LNode *next;
}LNode,*LinkList;

typedef struct StrNode{
    char c;
    struct StrNode *next;
}StrNode, *String;

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

LinkList InitCycleList_withHead(Elemtype Init[], int len){
    LNode *head = (LNode*)malloc(sizeof(LNode));
    LNode *cur = head;
    for(int i = 0; i < len; i++){
        LNode *p = (LNode*)malloc(sizeof(LNode));
        p->data = Init[i];
        cur->next = p;
        cur = p;
    }
    cur->next = head;
    return head;
}

String InitString(char Init[], int len){
    len--;
    StrNode *head = (StrNode*)malloc(sizeof(StrNode));
    StrNode *cur = head;
    for(int i = 0; i < len; i++){
        StrNode *p = (StrNode*)malloc(sizeof(StrNode));
        p->c = Init[i];
        cur->next = p;
        cur = p;
    }
    cur->next = NULL;
    return head;
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

void printString_withoutHead(String s){
    if(s == NULL || s->next == NULL){
        printf("Linklist is empty!\n");
        return;
    }
    StrNode* p = s;
    while (p != NULL){
        printf("%c",p->c);
        p = p->next;
    }
    printf("\n");
    return;
}

void printCycleList_withHead(LinkList L){
    if(L == NULL || L->next == NULL){
        printf("Linklist is empty!\n");
        return;
    }
    LNode* p = L->next;
    while (p != L){
        printf("%d",p->data);
        p = p->next;
        if(p != L)
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

int StringLength_withHead(String s){
    if(s == NULL) 
        return ERROR;
    int len = 0;
    for(StrNode* cur = s->next; cur != NULL; cur = cur->next)
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

/*****************************************
 * 双链表及相关函数
 * **************************/
typedef struct DNode{
    Elemtype data;
    struct DNode* prior,*next;
}DNode,*DLinkList;

typedef struct speXDnode{
    struct speXDnode* pred;
    Elemtype data;
    int freq;
    struct speXDnode* next;
}speXDnode, *speXDLinkList;

DLinkList InitDList_withHead_circulation(Elemtype Init[],int len){
    DNode *head = (DNode*)malloc(sizeof(DNode));
    DNode *cur = head;
    for(int i = 0; i < len; i++){
        DNode *p = (DNode*)malloc(sizeof(DNode));
        p->data = Init[i];
        cur->next = p;
        p->prior = cur;
        cur = p;
    }
    cur->next = head;
    head->prior = cur;
    return head;
}

void printDList_withHead(DLinkList L){
    if(L == NULL || L->next == NULL){
        printf("DLinklist is empty!\n");
        return;
    }
    DNode* p = L->next;
    while (p != L){
        printf("%d",p->data);
        p = p->next;
        if(p != L)
            printf(" <-> ");
    }
    printf("\n");
    return;
}

bool isEmpty_withHead(DLinkList DL){
    return DL == NULL || DL->next == DL || DL->prior == DL;
}

speXDLinkList InitSpeXList_withHead(Elemtype Init[], int len){
    speXDnode *head = (speXDnode*)malloc(sizeof(speXDnode));
    speXDnode *cur = head;
    for(int i = 0; i < len; i++){
        speXDnode *p = (speXDnode*)malloc(sizeof(speXDnode));
        p->data = Init[i];
        cur->next = p;
        p->pred = cur;
        cur = p;
        cur->freq = 0;
    }
    cur->next = NULL;
    return head;
}

void printSpeXList_withHead(speXDLinkList sL){
    if(sL == NULL || sL->next == NULL){
        cout<<"EMPTY LIST!"<<endl;
        return;
    }
    for(speXDnode* cur = sL->next; cur != NULL; cur = cur->next){
        cout<<cur->data<<"("<<cur->freq<<")";
        if(cur->next != NULL)
            cout<<"<->";
        else
            cout<<endl;
    }
    return;
}


/***********************************
 * 栈定义及常用函数
 * ***********************************/
typedef struct stack{
    Elemtype data;
    struct stack* next;
}StackNode,*Stack;//链式栈(int)

typedef struct strstack{
    char c;
    struct strstack* next;
}strStackNode,*strStack;//链式栈(char)

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

char popstrStack(strStack& S){
    if(S == NULL)
        return ERROR;
    char top = S->c;
    S = S->next;
    return top;
}

void pushstrStack(strStack& S,char c){
    strStackNode* in = (strStackNode*)malloc(sizeof(strStackNode));
    in->c= c;
    in->next = S;
    S = in;
}

bool isstrEmpty(strStack S){
    if(S == NULL)
        return true;
    else return false;
}