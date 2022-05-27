#include "C:/Users/86072/Documents/Clanguage/Datastructure_408/Linear_Table/def.h"
void divideList_into2List_Brev(LinkList L, LinkList& A, LinkList& B){
    if(L == NULL || L->next == NULL){
        printf("EMPTY LIST!\n");
        return;
    }
    LNode* p = L->next;
    A = (LinkList)malloc(sizeof(LinkList));//头结点
    LNode* pA = A;
    B = (LinkList)malloc(sizeof(LinkList));//头结点
    LNode* pB = NULL;
    LNode* save = NULL;
    for(int i = 0; p != NULL; i++)
        switch (i % 2)
        {
        case 0:
            pA->next = p;
            pA = pA->next;
            p = p->next;
            break;
        
        case 1:
            save = p->next;
            p->next = pB;
            pB = p;
            p = save;
            break;

        default:
            printf("% calculation ERROR!\n");
            return;
        }
    pA->next = NULL;
    B->next = pB;
    return;
}

int main(void){
    Elemtype test[10] = {5,4,1,2,3,0,10,9,8,7};
    LinkList L = InitList_withHead(test, sizeof(test) / sizeof(Elemtype));
    LinkList A;
    LinkList B;
    divideList_into2List_Brev(L, A, B);
    printList_withHead(A);
    printList_withHead(B);
    return 0;
}