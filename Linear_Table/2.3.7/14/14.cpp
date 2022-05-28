#include "C:/Users/86072/Documents/Clanguage/Datastructure_408/Linear_Table/def.h"
void merge_2ascList_common1List(LinkList& L, LinkList A, LinkList B){
    L = (LinkList)malloc(sizeof(LinkList));
    LNode* p = L;
    LNode* pA;
    LNode* pB;
    LNode* stop;
    if(isNULL_withHead(A)){
        L = NULL;
        return;
    }else
        pA = A->next;
    if(isNULL_withHead(B)){
        L = NULL;
        return;
    }else
        pB = B->next;
    while(pA != NULL && pB != NULL){
        if(pA->data == pB->data){
            p->next = (LinkList)malloc(sizeof(LinkList));
            p = p->next;
            p->data = pA->data;
            pA = pA->next;
            pB = pB->next;
        }else if (pA->data < pB->data)
            pA = pA->next;
        else
            pB = pB->next;
    }
    p->next = NULL;
}

int main(void){
    Elemtype testA[] = {1,2,3,8,10,15};
    Elemtype testB[] = {0,1,5,8,9,10,12,13,14};
    LinkList L;
    LinkList A = InitList_withHead(testA, sizeof(testA) / sizeof(Elemtype));
    LinkList B = InitList_withHead(testB, sizeof(testB) / sizeof(Elemtype));
    merge_2ascList_common1List(L, A, B);
    printList_withHead(L);
    printList_withHead(A);
    printList_withHead(B);
    return 0;
}