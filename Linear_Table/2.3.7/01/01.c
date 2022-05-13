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

int main(){
    LinkList L = (LinkList)malloc(sizeof(LNode));
    Elemtype test[5] = {1,2,3,4,5};
    InitList_withoutHead(L, test, sizeof(test) / sizeof(Elemtype));
    DelValue_x(L, 3);
    printList(L);
    return 0;
}
