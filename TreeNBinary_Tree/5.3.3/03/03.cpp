#include "C:/Users/86072/Documents/Clanguage/Datastructure_408/def.h"

int main(void){
    int init[] = {1,2,3,4,5,6,7,'#','#','#','#','#','#',14,15};
    int a = 0;
    int *pi = &a;
    BiTree T = CreateBiTree(init, sizeof(init) / sizeof(int), pi);
    //PrinTree(T);
    PreOrder(T);
    cout<<endl;
    PreOrder_recursion(T);
    return 0;
}