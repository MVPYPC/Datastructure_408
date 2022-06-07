#include "C:/Users/86072/Documents/Clanguage/Datastructure_408/def.h"

void reverseQueue_byStack(SqQueue& q){
    Stack s = NULL;
    for(int i = q.front; i != q.rear; i = (i + 1) % MAX_SIZE)
        pushStack(s,q.data[i]);
    for(int i = q.front; i != q.rear; i = (i + 1) % MAX_SIZE)
        q.data[i] = popStack(s);
    return;
}

int main(void){
    Elemtype test[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14};
    SqQueue q;
    InitSqQueue(q);
    AssignQueue(q, test, sizeof(test) / sizeof(int));
    printQueue(q);
    reverseQueue_byStack(q);
    printQueue(q);
    return 0;
}