#include "C:/Users/86072/Documents/Clanguage/Datastructure_408/Linear_Table/def.h"
void merge_2ascList_1descList(LinkList& L, LinkList& A, LinkList& B){
    LNode* pA = A->next;
    LNode* pB = B->next;
    LNode* save = NULL;
    LNode* less = NULL;
    while(pA != NULL && pB != NULL){
        if(pA->data <= pB->data){
            less = pA;
            pA = pA->next;
        }else{
            less = pB;
            pB = pB->next;
        }
        less->next = save;
        save = less;
    }
    for(LNode* rest = pA == NULL ? pB : pA; rest != NULL;){
        LNode* tmp = rest->next;
        rest->next = save;
        save = rest;
        rest = tmp;
    }
    L = (LinkList)malloc(sizeof(LinkList));
    L->next = save;
}

int main(void){
    Elemtype testA[] = {1,2,3,10,15};
    Elemtype testB[] = {0,1,5,8,9,12,13,14};
    LinkList L;
    LinkList A = InitList_withHead(testA, sizeof(testA) / sizeof(Elemtype));
    LinkList B = InitList_withHead(testB, sizeof(testB) / sizeof(Elemtype));
    merge_2ascList_1descList(L, A, B);
    printList_withHead(L);
    return 0;
}