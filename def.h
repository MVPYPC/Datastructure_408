//#include "C:/Users/86072/Documents/Clanguage/Datastructure_408/def.h"
#include <stdio.h>
#include <malloc.h>
#include <math.h>
#include <string.h>
#include <iostream>
#include <Windows.h>
using namespace std;


#define OK 1
#define ERROR 0
#define SUCCESS 1
#define UNSUCCESS -1
#define MAX_SIZE 50
#define INT_MAX 2147483647
#define BIG_NUM 100

typedef int Elemtype;
typedef int Status;


/***********************************
 * 顺序表结构定义及常用函数
 * *************************************/
typedef struct SqList{
    Elemtype data[MAX_SIZE];
    int length;
}SqList;

//Initializing the SqList L with the array init.
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
typedef struct Sqstack{
    Elemtype data[MAX_SIZE];
    int top;
}SqStack;//顺序栈

typedef struct SqDstack{
    Elemtype data[2 * MAX_SIZE];
    int top[2];
}SqDstack;//双向栈

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
    return S == NULL;
}

bool isOverflow(Stack S){
    if(isEmpty(S))
        return false;
    bool res = false;
    for(int i = 0; i < MAX_SIZE; i++)
        if(S->next != NULL)
            S = S->next;
        else{
            if(i == MAX_SIZE)
                res = true;
            break;
        }
    return res;
}


void printStack(Stack s){
    cout<<endl<<"*****STACK 1*****"<<endl;
    while(!isEmpty(s))
        cout<<"*       "<<popStack(s)<<"       *"<<endl;
    cout<<"****BOTTOM 1*****"<<endl;
    return;
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

void InitSqDstack(SqDstack& Dstack){
    Dstack.top[0] = -1;
    Dstack.top[1] = 2 * MAX_SIZE;
    return;
}

bool pushSqDstack(SqDstack& Dstack, int num, Elemtype x){
    if(Dstack.top[0] + 1 == Dstack.top[1]){
        cout<<"STACK OVERFLOW!!!"<<endl;
        return false;
    }
    switch (num)
    {
    case 0:
        Dstack.data[++Dstack.top[0]] = x;
        break;

    case 1:
        Dstack.data[--Dstack.top[1]] = x;
        break;
    
    default:
        cout<<"ERROR STACK NUMBER"<<endl;
        return false;
    }
    return true;
}

Elemtype popDstack(SqDstack& Dstack, int num){
    switch (num)
    {
    case 0:
        if(Dstack.top[0] == -1){
            cout<<"STACK1 IS EMPTY!"<<endl;
            return ERROR;
        }
        else
            return Dstack.data[Dstack.top[0]--];
        
    case 1:
        if(Dstack.top[1] == 2*MAX_SIZE){
            cout<<"STACK2 IS EMPTY!"<<endl;
            return ERROR;
        }
        else
            return Dstack.data[Dstack.top[1]++];


    default:
        cout<<"ERROR STACK NUMBER"<<endl;
        return ERROR;
    }
}

void printDstack(SqDstack Dstack){
    cout<<endl;
    cout<<"*****STACK 1*****"<<endl;
    if(Dstack.top[0] == -1)
        cout<<"******EMPTY******"<<endl;
    else
        for(int i = Dstack.top[0]; i > -1; i--)
            cout<<"*       "<<Dstack.data[i]<<"       *"<<endl;
    cout<<"*****BOTTOM1*****"<<endl;
    cout<<endl;
    cout<<"*****STACK 2*****"<<endl;
    if(Dstack.top[1] == 2 * MAX_SIZE)
        cout<<"******EMPTY******"<<endl;
    else
        for(int i = Dstack.top[1]; i < 2 * MAX_SIZE; i++)
            cout<<"*       "<<Dstack.data[i]<<"       *"<<endl;
    cout<<"*****BOTTOM2*****"<<endl;
}

typedef struct {
    Elemtype data[MAX_SIZE];
    int front,rear;
    bool tag;//用于3.2.5/01 tag值为 false (0) 时, (front == rear) ==> 空
             //             tag值为 true (1) 时, (front == rear) ==> 满
}SqQueue_tag;

void InitSqQueue_tag(SqQueue_tag& Q){
    Q.front = 0;
    Q.rear = 0;
    Q.tag = false;
}

bool EnQueue_tag(SqQueue_tag& Q, Elemtype x){
    if(Q.tag && Q.front == Q.rear){
        cout<<"FULL QUEUE!"<<endl;
        return false;
    }
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MAX_SIZE;
    Q.tag = true;
    return true;
}

bool DeQueue_tag(SqQueue_tag& Q, Elemtype& x){
    if(((Q.front == Q.rear) && (!Q.tag))){
        cout<<"EMPTY QUEUE!"<<endl;
        return false;
    }
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MAX_SIZE;
    Q.tag = false;
    cout<<"DeQueue_tag success! And "<<x<<" is out of Queue"<<endl;
    return true;
}

void printQueue_tag(SqQueue_tag q){
    cout<<"FRONT-> ";
    if(q.front == q.rear && q.tag)
        cout<<q.data[q.front]<<" ";
    for(int i = q.front + 1; i != q.rear; i = (i + 1) % MAX_SIZE)
        cout<<q.data[i]<<" ";
    cout<<"<-REAR"<<endl;
}


typedef struct {
    Elemtype data[MAX_SIZE];
    int front,rear;
}SqQueue;//顺序队列

void InitSqQueue(SqQueue& Q){
    Q.front = 0;
    Q.rear = 0;
}

void AssignQueue(SqQueue& q, Elemtype assign[], int len){
    if(len > MAX_SIZE){
        cout<<"The array for assign is too~~ long!"<<endl;
        return;
    }
    for(; q.rear < len; q.rear++)
        q.data[q.rear] =  assign[q.rear];
    return;
}

bool EnQueue(SqQueue& Q, Elemtype x){
    if(Q.front == (Q.rear + 1) % MAX_SIZE){
        cout<<"FULL QUEUE!"<<endl;
        return false;
    }
    Q.data[Q.rear] = x;
    Q.rear = (Q.rear + 1) % MAX_SIZE;
    return true;
}

bool DeQueue(SqQueue& Q, Elemtype& x){
    if(Q.front == Q.rear){
        cout<<"EMPTY QUEUE!"<<endl;
        return false;
    }
    x = Q.data[Q.front];
    Q.front = (Q.front + 1) % MAX_SIZE;
    cout<<"DeQueue success! And "<<x<<" is out of Queue"<<endl;
    return true;
}

void printQueue(SqQueue q){
    cout<<"FRONT-> ";
    for(int i = q.front; i != q.rear; i = (i + 1) % MAX_SIZE)
        cout<<q.data[i]<<" ";
    cout<<"<-REAR"<<endl;
}

typedef struct Queue{
    LNode* front;
    LNode* rear;
}Queue;//链队列

void Init_Queue(Queue& q){
    q.front = (LNode*)malloc(sizeof(LNode));
    q.rear = q.front;
    q.rear->next = q.front;
    q.front->next =q.rear;
}

bool EnQueue(Queue& q, Elemtype e){
    if(q.rear->next == q.front){
        LNode* ins = (LNode*)malloc(sizeof(LNode));
        ins->next = q.front;
        q.rear->next = ins;
    }
    q.rear->data = e;
    q.rear = q.rear->next;
    return true;
}

bool DeQueue(Queue& q, Elemtype& e){
    if(q.rear == q.front){
        cout<<"EMPTY QUEUE!"<<endl;
        return false;
    }
    e = q.front->data;
    q.front =q.front->next;
    return true;
}

bool isEmpty(Queue q){
    return q.front == q.rear;
}

void print_Queue(Queue q){
    cout<<"***************************************\n";
    cout<<"Queue: ";
    for(LNode* tmp = q.front; tmp != q.rear; tmp = tmp->next)
        cout<<tmp->next->data<<" ";
    cout<<endl<<"***************************************\n";
    return;
}

typedef struct {
    char* ch;
    int length;
}HString;

void StrAssign(HString& T, char* Init, int len){
    int i = 0;
    T.ch = (char*)malloc(sizeof(char) * (len - 1));//不要'\0'
    while(Init[i] != '\0')
        *(T.ch + i) = Init[i++];
    T.length = i;
    return;
}

void StrCopy(HString& T, HString S){
    T.ch = (char*)malloc(sizeof(char) * S.length);
    for(int i = 0; i < S.length; i++)
        *(T.ch + i) = *(S.ch + i);
    T.length = S.length;
    return;
}

bool StrEmpty(HString T){
    return T.length == 0 || T.ch == NULL;
}

int StrCompare(HString S, HString T){
    for(int i = 0; i < min(S.length, T.length); i++){
        int result = *(S.ch++) - *(T.ch++);
        if(result != 0)
            return result;
    }
    return 0;
}

int StrLength(HString T){
    return T.length;
}

void SubString(HString& sub, HString T, int pos, int len){
    if(pos + len >= T.length){
        cout<<"ERROR PARAMETERS: pos + len ≥ T.length"<<endl;
        return;
    }
    sub.ch = (char*)malloc(sizeof(char) * len);
    sub.length = len;
    for(int i = 0; i < len; i++)
        *(sub.ch + i) = *(T.ch + pos + i);
    return;
}

void Concat(HString& T, HString S1, HString S2){
    T.ch = (char*)malloc((S1.length + S2.length) * sizeof(char));
    T.length = S1.length + S2.length;
    int t = 0;
    for(int i = 0; i < S1.length; i++,t++)
        *(T.ch + t) = *(S1.ch + i);
    for(int i = 0; i < S2.length; i++,t++)
        *(T.ch + t) = *(S2.ch + i);
    return;
}

int Index(HString T, HString S){
    int pos = 1;
    for(; pos <= T.length - S.length; pos++){
        int i = 1;
        for(; i <= S.length; i++){
            if(*(T.ch + pos + i) != *(S.ch + i))
                break;
        }
        if(i == S.length + 1)
            return pos + 1;
    }
    return 0;
}

void ClearString(HString& T){
    T.ch = NULL;
    T.length = 0;
    return;
}

void DestroyString(HString& T){
    free(T.ch);
    T.length = -1;
    return;
}

typedef struct {
    Elemtype data[MAX_SIZE];
}SqTree;/*顺序存储二叉树，其中从数组下标1开始存储树中的结点，这样可以满足
          性质：P131性质4
          data[0]可用于存储树中有效结点个数*/

void InitSqTree(SqTree &st, Elemtype init[], int len){
    if(len > MAX_SIZE)
        return;
    st.data[0] = 0;
    for(int i = 1; i <= len; i++){
        st.data[i] = init[i - 1];
        if(st.data[i] != 0)
            st.data[0]++;
    }
    st.data[0]--;
    return;
}

typedef struct BiTNode{
    Elemtype data;
    struct BiTNode *left, *right;
}BiTNode, *BiTree;

typedef struct Treestack{
    BiTNode* node;
    struct Treestack* next;
}Tree_stacknode, *Tree_stack;

BiTNode* pop_treeStack(Tree_stack& S){
    if(S == NULL)
        return NULL;
    BiTNode* top = S->node;
    S = S->next;
    return top;
}

void push_treeStack(Tree_stack& S, BiTNode* x){
    Tree_stacknode* in = (Tree_stacknode*)malloc(sizeof(Tree_stacknode));
    in->node = x;
    in->next = S;
    S = in;
}

BiTNode* get_treeStack(Tree_stack S){
    return S->node;
}


bool isEmpty(Tree_stack S){
    if(S == NULL)
        return true;
    else
        return false;
}

void visit(BiTNode* bnode){
    cout<<bnode->data<<" ";
    return;
}

void visit(Elemtype data){
    cout<<data;
    return;
}

/* void gotoxy(int x, int y)
{
	// 更新光标位置
	COORD pos;
	HANDLE hOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	pos.X = x;
	pos.Y = y;
	SetConsoleCursorPosition(hOutput, pos);
}

int BiTreeDepth(BiTree T) {
	if (T == NULL) return 0;

	int depthLeft, depthRight;
	depthLeft = BiTreeDepth(T->left);
	depthRight = BiTreeDepth(T->right);

	return 1 + (depthLeft > depthRight ? depthLeft : depthRight);
}

Elemtype BreakBiTree(BiTree& T, BiTree& L, BiTree& R) {
	if (T == NULL) return ERROR;
	L = T->left;
	R = T->right;
	return OK;
}
/*
* 递归打印打印出树形
* T		正在打印的树
* depth	目前在打印树的第几层
* right	该子树是否为右子树
* tap	目前子树需要的相对偏移数量
*/
/* Elemtype Traverse_R(BiTree T, int depth, int right, int tap) {
	if (T == NULL) return OK;

	// 获取一次树的初始高度，用于计算相对偏移数量
	static int treeDepth = BiTreeDepth(T);
	// 记录当前光标位置，用于在递归中记录当前递归时树的位置
	int x, y;
	// 拆分树，将树的左右子树拆分开来
	BiTree L, R;
	BreakBiTree(T, L, R);

	// 计算父树的偏移量
	int tap1 = tap * pow(2, treeDepth - depth);
	// 计算子树的偏移量
	int tap2 = right * (pow(2, treeDepth - depth));
	// 计算半偏移量
	int tap3 = pow(2, treeDepth - depth - 1);

	// 获取根的坐标
	// x 计算方法为：父偏移量 + 子偏移量 + 半偏移量 - 1
	// y 计算方法为：目前打印的层数 * 2
	x = tap1 + tap2 + tap3 - 1;
	y = depth * 2;

	// 打印根的位置
	gotoxy(x * 2, y);
	printf("%d", T->data);

	// 在打印子树时，当前层数+1
	depth++;
	// 计算子树的父偏移量
	tap = tap * 2 + (right == 1 ? 2 : 0);
	if (L == NULL && R == NULL) return OK;
	else if (R == NULL) {
		// 打印左子树的位置
		gotoxy(x * 2 - tap3, y + 1);
		printf("┏");
		for (int i = 0; i < tap3-1; i++) printf("━");
		printf("┛");
		Traverse_R(L, depth, 0, tap);
	}
	else if (L == NULL) {
		// 打印右子树的位置
		gotoxy(x * 2, y + 1);
		printf("┗");
		for (int i = 0; i < tap3-1; i++) printf("━");
		printf("┓");
		Traverse_R(R, depth, 1, tap);
	}
	else {
		// 打印左右子树的位置
		gotoxy(x * 2 - tap3, y + 1);
		printf("┏");
		for (int i = 0; i < tap3 - 1; i++) printf("━");
		printf("┻");
		for (int i = 0; i < tap3 - 1; i++) printf("━");
		printf("┓");
		Traverse_R(L, depth, 0, tap);
		Traverse_R(R, depth, 1, tap);
	}
    return OK;
}

Elemtype PrinTree(BiTree T) {
	Traverse_R(T, 0, 0, 0);
	return OK;
} */

BiTree CreateBiTree(Elemtype* a, int len,int* pi){
	if (a[*pi] == '#'|| *pi>= len){//'#'是空结点标志
		(*pi)++;
		return NULL;
	}
	BiTNode* root = (BiTNode *) malloc(sizeof(BiTNode));
	if (root == NULL){
		printf("申请失败\n");
		exit(-1);
	}
	root->data = a[(*pi)++];
	root->left = CreateBiTree(a, len, pi);
	root->right= CreateBiTree(a, len, pi);
	return root;
}

void PreOrder_recursion(BiTree T){
    if(T != NULL){
        visit(T);
        PreOrder_recursion(T->left);
        PreOrder_recursion(T->right);
    }
    return;
}

void InOrder_recursion(BiTree T){
    if(T != NULL){
        InOrder_recursion(T->left);
        visit(T);
        InOrder_recursion(T->right);
    }
    return;
}

void PostOrder_recursion(BiTree T){
    if(T != NULL){
        PostOrder_recursion(T->left);
        PostOrder_recursion(T->right);
        visit(T);
    }
    return;
}

void PreOrder(BiTree T){
    Tree_stack S = NULL;
    BiTree cur = T;
    while(cur || !isEmpty(S)){
        if(cur){
            visit(cur);
            push_treeStack(S, cur);
            cur = cur->left;
        }else{
            cur = pop_treeStack(S);
            if(cur == NULL)
                continue;
            else
                cur = cur->right;
        }
    }
    return;
}

void InOrder(BiTree T){
    Tree_stack S = NULL;
    BiTree cur = T;
    while(cur || !isEmpty(S)){
        if(cur){
            push_treeStack(S, cur);
            cur = cur->left;
        }else{
            cur = pop_treeStack(S);
            visit(cur);
            cur = cur->right;
        }
    }
    return;
}

void PostOrder(BiTree T){
    Tree_stack S = NULL;
    BiTree cur = T;
    BiTree last = NULL;
    while(cur || !isEmpty(S)){
        if(cur){
            push_treeStack(S, cur);
            cur = cur->left;
        }else{
            cur = get_treeStack(S);
            if(cur->right == NULL || cur->right == last){
                visit(cur);
                last = cur;
                pop_treeStack(S);
                cur = NULL;
            }else 
                cur = cur->right;
        }
    }
    return;
}