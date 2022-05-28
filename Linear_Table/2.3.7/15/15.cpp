#include "C:/Users/86072/Documents/Clanguage/Datastructure_408/Linear_Table/def.h"
void merge_2ascList_2A(LinkList& A, LinkList B){
    LNode* pA;
    LNode* pB;
    LNode* save = A;
    if(isNULL_withHead(A))
        return;
    else
        pA = A->next;
    if(isNULL_withHead(B))
        return;
    else
        pB = B->next;
    while(pA != NULL && pB != NULL)
        if(pA->data == pB->data){
            save->next = pA;
            save = pA;
            pA = pA->next;
            pB = pB->next;
        }else if(pA->data > pB->data)
            pB = pB->next;
        else
            pA = pA->next;
    save->next = NULL;
}

int main(void){
    Elemtype testA[] = {1,2,3,8,10,15};
    Elemtype testB[] = {0,1,5,8,9,10,12,13,14};
    LinkList A = InitList_withHead(testA, sizeof(testA) / sizeof(Elemtype));
    LinkList B = InitList_withHead(testB, sizeof(testB) / sizeof(Elemtype));
    merge_2ascList_2A(A, B);
    printList_withHead(A);
    printList_withHead(B);
    return 0;
}