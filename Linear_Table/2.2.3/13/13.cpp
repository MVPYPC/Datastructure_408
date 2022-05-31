#include "C:/Users/86072/Documents/Clanguage/Datastructure_408/Linear_Table/def.h"

int find_minPosInt(int A[], int n){
    int* Hash = (int*)malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++)
        Hash[i] = 0;
    for(int i = 0; i < n; i++)
        if(A[i] <= n && A[i] > 0)
            Hash[A[i] - 1]++;
    for(int i = 0; i < n; i++)
        if(Hash[i] == 0)
            return i + 1;
    return n + 1;
}

int main(void){
    int test[] = {-5,3,2,3};
    int result = find_minPosInt(test, sizeof(test) / sizeof(int));
    cout<<"Find it! It's "<<result<<endl;
    return 0;
}