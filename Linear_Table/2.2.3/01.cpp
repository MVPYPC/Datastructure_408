#include "C:/Users/86072/Documents/Clanguage/Datastructure_408/Linear_Table/def.h"
Elemtype DelMin(SqList &L){
    if(L.length == 0){
        cout<<"ERROR: length = 0"<<endl;
        return ERROR;
    }
    Elemtype minVal = L.data[0];
    Elemtype minPos = 0;
    for(int i = 0; i < L.length; i++)
        if(minVal > L.data[i]){
            minVal = L.data[i];
            minPos = i;
        }
    L.data[minPos] = L.data[L.length - 1];
    L.length--;
    return minVal;
}

int main(void){
    Elemtype test[] = {1,2,3,4,5,6};
    SqList L;
    initSqList(L, test, sizeof(test) / sizeof(Elemtype));
    printSqList(L);
    DelMin(L);
    printSqList(L);
    return 0;
}