#include "C:/Users/86072/Documents/Clanguage/Datastructure_408/Linear_Table/def.h"

void Link_2cycleList(LinkList& L1, LinkList& L2){
    LNode* last1 = L1;
    LNode* last2 = L2->next;
    while(last1->next != L1)
        last1 = last1->next;
    last1->next = last2;
    while (last2->next != L2)
        last2 = last2->next;
    last2->next = L1;
    return;
}

int main(void){
    Elemtype testA[] = {1,2,3,8,10,15};
    Elemtype testB[] = {0,1,5,8,9,10,12,13,14};
    LinkList A = InitCycleList_withHead(testA, sizeof(testA) / sizeof(Elemtype));
    LinkList B = InitCycleList_withHead(testB, sizeof(testB) / sizeof(Elemtype));
    Link_2cycleList(A,B);
    printCycleList_withHead(A);
    return 0;
}