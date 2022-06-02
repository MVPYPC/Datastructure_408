#include "C:/Users/86072/Documents/Clanguage/Datastructure_408/Linear_Table/def.h"

void RepeDelMin(LinkList& L){
    while(L->next != L){
        LNode* minNode = L->next;
        LNode* pre_min = L;
        for(LNode* cur = pre_min; cur->next != L; cur = cur->next)
            if(cur->next->data < minNode->data){
                pre_min = cur;
                minNode = cur->next;
            }
        LNode* del = minNode;
        pre_min->next = minNode->next;
        free(del);
        printCycleList_withHead(L);
    }
    free(L);
}

int main(void){
    Elemtype test[] = {9,10,12,13,14,0,1,5,8};
    LinkList L = InitCycleList_withHead(test, sizeof(test) / sizeof(Elemtype));
    RepeDelMin(L);
    return 0;
}