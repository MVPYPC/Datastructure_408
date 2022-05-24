#include "C:/Users/86072/Documents/Clanguage/Datastructure_408/Linear_Table/def.h"
void printList_reverse(LinkList L){
    Stack S = NULL;
    for(LNode* cur = L->next; cur != NULL; cur = cur->next)
        pushStack(S, cur->data);
    Elemtype x = popStack(S);
    for(; !isEmpty(S); x = popStack(S)){
        printf("%d",x);
        if(!isEmpty(S)) 
            printf("->");
    }
    printf("%d",x);
}

int main(void){
    Elemtype test[5] = {1,2,3,4,5};
    LinkList L = InitList_withHead(test, sizeof(test) / sizeof(Elemtype));
    printList_reverse(L);
    return 0;
}