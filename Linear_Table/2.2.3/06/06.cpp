#include "C:/Users/86072/Documents/Clanguage/Datastructure_408/Linear_Table/def.h"

void delValue_same(SqList& L){
    int slow = 0;
    for(int fast = 0; fast < L.length; fast++){
        if(!(L.data[fast] == L.data[fast + 1]))
            L.data[slow++] = L.data[fast];
    }
    L.length = slow;
    return;
}

int main(void){
    Elemtype test[] = {1,1,2,3,4,4,5,6,6,6};
    SqList L;
    initSqList(L, test, sizeof(test) / sizeof(Elemtype));
    printSqList(L);
    delValue_same(L);
    printSqList(L);
    return 0;
}