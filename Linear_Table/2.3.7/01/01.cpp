#include "C:/Users/86072/Documents/Clanguage/Datastructure_408/Linear_Table/def.h"

void DelValue_x(LinkList& L, Elemtype x){
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
    Elemtype test[5] = {1,2,3,4,5};
    LinkList L = InitList_withoutHead(test, sizeof(test) / sizeof(Elemtype));
    DelValue_x(L, 3);
    printList_withoutHead(L);
    return 0;
}
