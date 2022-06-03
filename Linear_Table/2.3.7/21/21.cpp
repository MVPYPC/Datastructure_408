#include "C:/Users/86072/Documents/Clanguage/Datastructure_408/Linear_Table/def.h"
bool isAnnulose(LinkList L){
    if(isNULL_withHead(L))
        return false;
    LNode* slow = L->next;
    LNode* fast = L->next->next;
    while(slow != fast){
        if(fast == NULL)
            return false;
        slow = slow->next;
        fast = fast->next->next;
    }
    return true;
}

int main(){
    Elemtype test[] = {1,2,3,4,5,9,8,6,7};
    LinkList L = InitList_withHead(test, sizeof(test) / sizeof(Elemtype));
    printBool(isAnnulose(L));
    L->next->next->next->next->next = L->next->next;
    printBool(isAnnulose(L));
    return 0;
}