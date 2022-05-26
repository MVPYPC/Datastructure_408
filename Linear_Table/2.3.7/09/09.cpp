#include "C:/Users/86072/Documents/Clanguage/Datastructure_408/Linear_Table/def.h"
void printNfreeList_asc(LinkList& L){
    if(L == NULL || L->next == NULL) return;//链表为空或只有头结点
    for(LNode* cur = L;cur->next->next != NULL; cur = cur->next){
        LNode* min = cur->next;
        LNode* before_min = cur;
        for(LNode* p = cur; p->next != NULL; p = p->next)
            if(p->next->data <= min->data){//这里小于等于是精髓！若用小于则有重复项时会只留下一项
                before_min = p;
                min = p->next;
            }
        LNode* tmp = min->next;
        min->next = cur->next;
        cur->next = min;
        before_min->next = tmp;
    }
    LNode* p = L->next;
    while (p != NULL){
        printf("%d",p->data);
        LNode* del = p;
        p = p->next;
        free(del);
        if(p != NULL)
            printf("->");
    }
}

int main(void){
    Elemtype test[5] = {5,4,1,2,3};
    LinkList L = InitList_withHead(test, sizeof(test) / sizeof(Elemtype));
    printNfreeList_asc(L);
    return 0;
}