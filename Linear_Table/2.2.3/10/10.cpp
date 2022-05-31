#include "C:/Users/86072/Documents/Clanguage/Datastructure_408/Linear_Table/def.h"

void reverse_s2t(int A[], int s, int t){
    while(s < t){
        int tmp = A[s];
        A[s++] = A[t];
        A[t--] = tmp;
    }
}

void move_p(int A[], int n, int p){
    reverse_s2t(A, 0, n - 1);
    reverse_s2t(A, 0, n - p - 1);
    reverse_s2t(A, n - p, n - 1);
}

int main(void){
    int test[] = {1,2,3,4,5,6,7,8,9};
    int m = 5;
    move_p(test, sizeof(test) / sizeof(int), m);
    for(int i = 0; i < sizeof(test) / sizeof(int); i++)
        cout<<test[i]<<" ";
    cout<<endl;
}