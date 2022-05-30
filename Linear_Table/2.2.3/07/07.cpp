#include "C:/Users/86072/Documents/Clanguage/Datastructure_408/Linear_Table/def.h"

SqList merge(SqList L1, SqList L2){
    SqList* result = (SqList*)malloc(sizeof(SqList) * (L1.length + L2.length));
    int pos1 = 0;
    int pos2 = 0;
    int pos = 0;
    while(pos1 < L1.length && pos2 < L2.length)
        result->data[pos++] = L1.data[pos1] <= L2.data[pos2] ? L1.data[pos1++] : L2.data[pos2++];
    while(pos1 < L1.length)
        result->data[pos++] = L1.data[pos1++];
    while(pos2 < L2.length)
        result->data[pos++] = L2.data[pos2++];
    result->length = L1.length + L2.length;
    return *result;
}

int main(void){
    Elemtype test1[] = {1,1,2,3,4,4,5,6,6,6};
    Elemtype test2[] = {1,1,2,3,4,4,5,6};
    SqList L1;
    initSqList(L1, test1, sizeof(test1) / sizeof(Elemtype));
    SqList L2;
    initSqList(L2, test2, sizeof(test2) / sizeof(Elemtype));
    SqList L = merge(L1,L2);
    printSqList(L);
    return 0;
}