#include "C:/Users/86072/Documents/Clanguage/Datastructure_408/Linear_Table/def.h"
void divideList_into2List(LinkList L, LinkList& A, LinkList& B){
    if(L == NULL || L->next == NULL){
        printf("EMPTY LIST!\n");
        return;
    }
    LNode* p = L->next;
    A = (LinkList)malloc(sizeof(LinkList));//头结点
    LNode* pA = A;
    B = (LinkList)malloc(sizeof(LinkList));//头结点
    LNode* pB = B;
    int i = 0;
    for(; p != NULL; p = p->next,i++)
        switch (i % 2)
        {
        case 0:
            pA->next = p;
            pA = pA->next;
            break;
        
        case 1:
            pB->next = p;
            pB = pB->next;
            break;

        default:
            printf("% calculation ERROR!\n");
            return;
        }
    pA->next = NULL;
    pB->next = NULL;
    return;
}

int main(void){
    Elemtype test[5] = {5,4,1,2,3};
    LinkList L = InitList_withHead(test, sizeof(test) / sizeof(Elemtype));
    LinkList A;
    LinkList B;
    divideList_into2List(L, A, B);
    printList_withHead(A);
    printList_withHead(B);
    return 0;
}