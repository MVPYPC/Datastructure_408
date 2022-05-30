#include "C:/Users/86072/Documents/Clanguage/Datastructure_408/Linear_Table/def.h"

void delValue_s2t(SqList& L, Elemtype s,Elemtype t){
    if(L.length == 0 || s > t)
        return;
    int slow = 0;
    for(int fast = 0; fast < L.length; fast++)
        if(!(L.data[fast] > s && L.data[fast] < t))
            L.data[slow++] = L.data[fast];
    L.length = slow;
    return;
}

int main(void){
    Elemtype test[] = {1,2,3,4,5,6};
    SqList L;
    initSqList(L, test, sizeof(test) / sizeof(Elemtype));
    printSqList(L);
    delValue_s2t(L,1,5);
    printSqList(L);
    return 0;
}