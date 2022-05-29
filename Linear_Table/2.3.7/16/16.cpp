#include "C:/Users/86072/Documents/Clanguage/Datastructure_408/Linear_Table/def.h"
bool isContinuous_subsequence(LinkList A, LinkList B){
    if(isNULL_withHead(B))
        return true;
    else if(isNULL_withHead(A))
        return false;
    LNode* pA = A->next;
    LNode* pB = B->next;
    char* strB = list2string_withHead(B, BIG_NUM);
    while(pA != NULL){
        if(pA->data == pB->data && strcmp(list2string_withoutHead(pA, strlen(strB)),strB) == 0)
            return true;
        else
            pA = pA->next;
    }
    return false;
}

int main(void){
    Elemtype testA[] = {1,2,3,8,10,15};
    Elemtype testB[] = {2,3};
    LinkList A = InitList_withHead(testA, sizeof(testA) / sizeof(Elemtype));
    LinkList B = InitList_withHead(testB, sizeof(testB) / sizeof(Elemtype));
    if(isContinuous_subsequence(A,B))
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
    return 0;
}