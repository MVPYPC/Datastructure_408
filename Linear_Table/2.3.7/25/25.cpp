#include "C:/Users/86072/Documents/Clanguage/Datastructure_408/Linear_Table/def.h"

void crossover_List(LinkList& L){
    LNode* slow = L->next;
    LNode* fast = L->next;
    while(fast->next != NULL){
        slow = slow->next;
        fast = fast->next;
        if(fast->next != NULL)
            fast = fast->next;
    }
    LNode* cur = slow->next;
    LNode* nxt = cur->next;
    cur->next = NULL;
    while(nxt != NULL){
        LNode* save = nxt->next;
        nxt->next = cur;
        cur = nxt;
        nxt = save;
    }
    slow->next = cur;//转置后半段
    cur = L->next;
    LNode* latter = slow->next;
    slow->next = NULL;
    while(latter != NULL){
        LNode* save = latter->next;
        latter->next = cur->next;
        cur->next = latter;
        cur = latter->next;
        latter = save;
    }
}

int main(void){
    Elemtype test[] = {1,2,3,4,5,6,7,8,9};
    LinkList L = InitList_withHead(test, sizeof(test) / sizeof(Elemtype));
    crossover_List(L);
    printList_withHead(L);
    return 0;
}