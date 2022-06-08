#include "C:/Users/86072/Documents/Clanguage/Datastructure_408/def.h"

void Enqueue(Stack& s1, Stack& s2, Elemtype x){
    if(isOverflow(s1))
        cout<<"STACK&QUEUE OVERFLOW!!!\n";
    else if(isEmpty(s2))
        pushStack(s1, x);
        else{
            while(!isEmpty(s2)){
                Elemtype tmp = popStack(s2);
                pushStack(s1,tmp);
            }
            pushStack(s1, x);
        }
    return;
}

void  DeQueue(Stack& s1, Stack& s2, Elemtype& x){
    if(!isEmpty(s2))
        x = popStack(s2);
    else if(isEmpty(s1))
        cout<<"EMPTY QUEUE!\n";
        else{
            while(!isEmpty(s1))
                pushStack(s2, popStack(s1));
            x = popStack(s2);
        }
    return;
}

bool StackQueueEmpty(Stack s1, Stack s2){
    return isEmpty(s1) && isEmpty(s2);
}

void printStackQueue(Stack s1, Stack s2){
    if(!isEmpty(s1))
        while(!isEmpty(s1))
            pushStack(s2, popStack(s1));
    printStack(s2);
    return;
}

int main(void){
    Stack s1 = NULL;
    Stack s2 = NULL;
    Elemtype x;
    Enqueue(s1, s2, 5);
    printStackQueue(s1,s2);
    DeQueue(s1, s2, x);
    printStackQueue(s1,s2);
    Enqueue(s1, s2, 6);
    Enqueue(s1, s2, 7);
    Enqueue(s1, s2, 1);
    printStackQueue(s1, s2);
    DeQueue(s1, s2, x);
    printStackQueue(s1,s2);
    return 0;
}