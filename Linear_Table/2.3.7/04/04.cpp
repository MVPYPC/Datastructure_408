#include "C:/Users/86072/Documents/Clanguage/Datastructure_408/Linear_Table/def.h"
void del_min(LinkList& L){
    LNode *cur = L;
    LNode *del = NULL;
    Elemtype min = INT_MAX;//最大值保证能改变
    while (cur->next != NULL){
        if(cur->next->data < min){
            min = cur->next->data;
            del = cur;
        }else
            cur = cur->next;
    }
    if(del != NULL){
        LNode *f_del = del->next;
        del->next = del->next->next;
        free(f_del);
    }
    return;
}

int main(void){
    Elemtype test[5] = {1,2,3,4,5};
    LinkList L = InitList_withHead(test, sizeof(test) / sizeof(Elemtype));
    del_min(L);
    printList_withHead(L);
    return 0;
}