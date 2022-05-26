#include "C:/Users/86072/Documents/Clanguage/Datastructure_408/Linear_Table/def.h"
LNode* mutual_LNode(LinkList L1, LinkList L2){
    int gap = ListLength_withHead(L1) - ListLength_withHead(L2);
    LNode* longer = gap >= 0 ? L1 : L2;
    LNode* shorter = gap >= 0 ? L2 : L1;
    for(int i = 0; i < gap; i++)
        longer = longer->next;
    while(longer != shorter && longer != NULL){
        longer = longer->next;
        shorter = shorter->next;
    }
    return longer;
}

int main(){
    Elemtype test1[5] = {1,2,3,4,5};
    LinkList L1 = InitList_withHead(test1, sizeof(test1) / sizeof(Elemtype));
    LinkList L2 = (LinkList)malloc(sizeof(LNode));
    L2->next = (LNode*)malloc(sizeof(LNode));
    L2->next->next = L1->next->next->next;
    LNode* result = mutual_LNode(L1,L2);
    printList_withoutHead(result);
    return 0;
}