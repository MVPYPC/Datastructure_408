#include "C:/Users/86072/Documents/Clanguage/Datastructure_408/Linear_Table/def.h"
void delList_x2y(LinkList& L, Elemtype x, Elemtype y){
    if(x > y){
        printf("parameter ERROR!\n");
        return;
    }
    LNode* cur = L;
    while(cur->next != NULL){
        if(cur->next->data > x && cur->next->data < y){
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
    delList_x2y(L, 0, 3);
    printList_withHead(L);
    return 0;
}