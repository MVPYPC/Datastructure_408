#include "def.h"

void DelValue_x(LinkList L, Elemtype x){
    if(L == NULL) return;
    else if(L->data == x){
        LNode *p = L;
        L = L->next;
        free(p);
        DelValue_x(L,x);
    }else
        DelValue_x(L->next, x);
    return;
}

void main(){
    LinkList L = (LinkList)malloc(sizeof(LNode));
    Elemtype test[5] = {1};
    InitList(L, test);
    DelValue_x(L, 3);
    printList(L);
    return;
}
