#include "C:/Users/86072/Documents/Clanguage/Datastructure_408/def.h"

//Init，EnQueue，DeQueue函数都写在def.h里了，方便后续使用
int main(void){
    SqQueue_tag q;
    Elemtype x;
    InitSqQueue_tag(q);
    EnQueue_tag(q,5);
    printQueue_tag(q);
    DeQueue_tag(q,x);
    DeQueue_tag(q,x);
    for(int i = 0; i < MAX_SIZE + 1; i++)
        EnQueue_tag(q,i);
    //DeQueue_tag(q,x);
    printQueue_tag(q);
    return 0;
}