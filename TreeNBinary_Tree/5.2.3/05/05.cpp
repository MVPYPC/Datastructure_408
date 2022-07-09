#include "C:/Users/86072/Documents/Clanguage/Datastructure_408/def.h"

Elemtype find_Ancestor(SqTree st, int i, int j){
    if(i > MAX_SIZE || j > MAX_SIZE)
        return ERROR;
    while (st.data[i] != 0 && st.data[j] != 0)
        if(i == j)
            break;
        else if(i < j)
            j = j / 2;
        else
            i = i / 2;
    return st.data[i];
}

int main(void){
    Elemtype test[] = {1,2,3,4,5,6,7,0,0,0,0,0,0,14,15};
    SqTree T;
    InitSqTree(T, test, sizeof(test) / sizeof(Elemtype));
    int i = 5;
    int j = 2;
    cout<<"The nearest common Ancestor of i = "<<i<<", j = "<<j<<" is "<<find_Ancestor(T, i, j)<<endl;
    return 0;
}