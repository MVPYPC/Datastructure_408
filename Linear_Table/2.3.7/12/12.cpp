#include "C:/Users/86072/Documents/Clanguage/Datastructure_408/Linear_Table/def.h"
void duplication_elminate_sortedList_withHead(LinkList& L){
    LNode* cur = L->next;
    while(cur->next != NULL && cur != NULL)
        if(cur->data == cur->next->data)
            cur->next = cur->next->next;
        else
            cur = cur->next;
    return;
}

int main(void){
    Elemtype test[] = {1,1,1,2,3,5,7,7,7,7,10,10};
    LinkList L = InitList_withHead(test, sizeof(test) / sizeof(Elemtype));
    duplication_elminate_sortedList_withHead(L);
    printList_withHead(L);
}