#include "C:/Users/86072/Documents/Clanguage/Datastructure_408/Linear_Table/def.h"

void NoDuplication_abs(LinkList& L, int n){
    bool* hash = (bool*)malloc(sizeof(bool) * n);
    for(int i = 0; i < n; i++)
        hash[i] = false;
    LNode* slow = L;
    for(LNode* fast = L->next; fast != NULL; fast = fast->next)
        if(!hash[abs(fast->data)]){
            slow->next = fast;
            slow = fast;
            hash[abs(fast->data)] = true;
        }
    slow->next = NULL;
}

int main(void){
    Elemtype test[] = {1,-1,2,3,4,5,0,-8,8,9,-5,-4};
    LinkList L = InitList_withHead(test, sizeof(test) / sizeof(Elemtype));
    printList_withHead(L);
    NoDuplication_abs(L, 10);
    printList_withHead(L);
    return 0;
}