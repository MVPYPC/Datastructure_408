#include "C:/Users/86072/Documents/Clanguage/Datastructure_408/Linear_Table/def.h"

void reverseArray_s2t(int A[],int s,int t){
    while(s < t){
        int tmp =A[s];
        A[s] = A[t];
        A[t] = tmp;
        s++;t--;
    }
}

void reverseArray(int A[], int m, int n){
    reverseArray_s2t(A, 0, m - 1);
    reverseArray_s2t(A, m, m + n - 1);
    reverseArray_s2t(A, 0, m + n - 1);
    return;
}

int main(void){
    int test[] = {1,2,3,4,5,6,7,8,9};
    int m = 3;
    int n = sizeof(test) / sizeof(int) - m;
    reverseArray(test, m, n);
    for(int i = 0; i < sizeof(test) / sizeof(int); i++)
        cout<<test[i]<<" ";
    cout<<endl;
}