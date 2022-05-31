#include "C:/Users/86072/Documents/Clanguage/Datastructure_408/Linear_Table/def.h"

void find_mainElement(int A[], int n){
    int* Hash = (int*)malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++)
        Hash[i] = 0;
    int m_ele = 0;
    for(int i = 0; i < n; i++)
        if(++Hash[A[i]] >= Hash[m_ele])
            m_ele = A[i];
    if(Hash[m_ele] > n / 2)
        cout<<"Main element exists! It's "<<m_ele<<endl;
    else
        cout<<"Not found!"<<endl;
    return;
}

int main(void){
    int test1[] = {0,5,5,3,5,7,5,5};
    find_mainElement(test1, sizeof(test1) / sizeof(int));
    int test2[] = {0,5,5,3,5,1,5,7};
    find_mainElement(test2, sizeof(test2) / sizeof(int));
}