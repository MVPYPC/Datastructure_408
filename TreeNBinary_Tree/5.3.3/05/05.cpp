#include "C:/Users/86072/Documents/Clanguage/Datastructure_408/def.h"

int main(void){
    int init[] = {1,2,4,'#','#',5,'#','#',3,6,'#','#',7,14,'#'};
    int a = 0;
    int *pi = &a;
    BiTree T = CreateBiTree(init, sizeof(init) / sizeof(int), pi);
    cout<<"The Depth of the tree is: "<<DepthTree(T)<<"."<<endl;
    return 0;
}