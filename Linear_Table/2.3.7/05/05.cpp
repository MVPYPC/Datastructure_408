#include "C:/Users/86072/Documents/Clanguage/Datastructure_408/Linear_Table/def.h"
void reverseList_withHead_locally(LinkList& L){
    LNode* cur = L->next;
    if(cur == NULL) return;//链表为空
    LNode* c_next = cur->next;
    if(c_next == NULL) return;//链表只有一个结点
    else cur->next = NULL;//处理第一个结点
    for(LNode* c_n_next = c_next->next; c_n_next != NULL; cur = c_next, 
                                                          c_next = c_n_next, 
                                                          c_n_next = c_n_next->next)
        c_next->next = cur;
    c_next->next = cur;
    L->next = c_next;
    return;
}

int main(void){
    Elemtype test[5] = {1,2,3,4,5};
    LinkList L = InitList_withHead(test, sizeof(test) / sizeof(Elemtype));
    reverseList_withHead_locally(L);
    printList_withHead(L);
    return 0;
}