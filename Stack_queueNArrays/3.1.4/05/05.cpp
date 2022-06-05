#include "C:/Users/86072/Documents/Clanguage/Datastructure_408/def.h"

//Init，push，pop函数都写在def.h里了，方便后续使用
int main(void){
    SqDstack Dstack;
    InitSqDstack(Dstack);
    pushSqDstack(Dstack, 0, 5);
    pushSqDstack(Dstack, 0, 3);
    printDstack(Dstack);
    popDstack(Dstack,0);
    printDstack(Dstack);
    popDstack(Dstack,1);
    pushSqDstack(Dstack,1,10);
    printDstack(Dstack);
    return 0;
}

