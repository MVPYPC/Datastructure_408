#include "C:/Users/86072/Documents/Clanguage/Datastructure_408/Linear_Table/def.h"
void DelValue_x_norecursion(LinkList &L, Elemtype x){
    LNode* cur = L;
    while(cur->next != NULL){
        if(cur->next->data == x){
            LNode *del = cur->next;
            cur->next = cur->next->next;
            free(del);
        }else
            cur = cur->next;
    }
    return;
}

int main(){
    Elemtype test[5] = {1,2,3,4,5};
    LinkList L = InitList_withHead(test, sizeof(test) / sizeof(Elemtype));
    DelValue_x_norecursion(L, 3);
    printList_withHead(L);
    return 0;
}