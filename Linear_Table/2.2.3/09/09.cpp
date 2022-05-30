#include "C:/Users/86072/Documents/Clanguage/Datastructure_408/Linear_Table/def.h"

void findX(SqList& A, Elemtype x){
    int low = 0; 
    int high = A.length - 1;
    int mid = (low + high) / 2;
    bool sign = false;
    while(low <= high){
        if(A.data[mid] == x){
            sign = true;
            break;
        }else if (A.data[mid] > x)
            high = mid -1;
        else
            low = mid + 1;
        mid = (high + low) / 2;
    }
    if(sign){
        cout<<"Got it!"<<endl;
        Elemtype tmp = A.data[mid];
        A.data[mid] = A.data[mid + 1];
        A.data[mid + 1] = tmp;
    }else{
        cout<<"Not found!"<<endl;
        for(int i = A.length - 1; i > high; i--)
            A.data[i + 1] = A.data[i];
        A.data[high <= A.length - 1 ? high + 1 : high] = x;
        A.length++;
    }
    return;
}

int main(void){
    Elemtype test[] = {1,1,2,4,4,5,6,6,6};
    SqList L;
    initSqList(L, test, sizeof(test) / sizeof(Elemtype));
    printSqList(L);
    findX(L, 3);
    printSqList(L);
    return 0;
}