#include "C:/Users/86072/Documents/Clanguage/Datastructure_408/def.h"

void LevelOrder_reverse(BiTree T){
    tree_Queue q;
    Tree_stack S = NULL;
    Init_Queue(q);
    BiTree cur = T;
    EnQueue(q, cur);
    while(!(isEmpty(q))){
        DeQueue(q, cur);
        push_treeStack(S, cur);
        if(cur->left)
            EnQueue(q, cur->left);
        if(cur->right)
            EnQueue(q, cur->right);
    }
    for(cur = pop_treeStack(S); S != NULL; cur = pop_treeStack(S))
        visit(cur);
    visit(cur);
    return;
}

int main(void){
    int init[] = {1,2,4,'#','#',5,'#','#',3,6,'#','#',7,14,'#'};
    int a = 0;
    int *pi = &a;
    BiTree T = CreateBiTree(init, sizeof(init) / sizeof(int), pi);
    //PrinTree(T);
    cout<<"LevelOrder:";
    LevelOrder(T);
    cout<<endl<<"reverse:";
    LevelOrder_reverse(T);
    cout<<endl;
    return 0;
}

