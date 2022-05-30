#include "C:/Users/86072/Documents/Clanguage/Datastructure_408/Linear_Table/def.h"

void reverseSqList(SqList& L){
    for(int i = 0; i < (L.length >> 1); i++){//左移乘右移除
        Elemtype tmp = L.data[i];
        L.data[i] = L.data[L.length - i - 1];
        L.data[L.length - i - 1] = tmp;
    }
    return;
}

int main(void){
    Elemtype test[] = {1,2,3,4,5,6};
    SqList L;
    initSqList(L, test, sizeof(test) / sizeof(Elemtype));
    printSqList(L);
    reverseSqList(L);
    printSqList(L);
    return 0;
}