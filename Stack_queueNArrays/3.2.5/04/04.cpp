#include "C:/Users/86072/Documents/Clanguage/Datastructure_408/def.h"

typedef struct speQueue{
    LNode* front;
    LNode* rear;
}speQueue;

void Init_speQueue(speQueue& sq){
    sq.front = (LNode*)malloc(sizeof(LNode));
    sq.rear = sq.front;
    sq.rear->next = sq.front;
    sq.front->next =sq.rear;
}

bool EnspeQueue(speQueue& sq, Elemtype e){
    if(sq.rear->next == sq.front){
        cout<<"The queue is full, increase the space occupied by the queue to get "<<e<<" in."<<endl;
        LNode* ins = (LNode*)malloc(sizeof(LNode));
        ins->next = sq.front;
        sq.rear->next = ins;
    }
    sq.rear = sq.rear->next;
    sq.rear->data = e;
    return true;
}

bool DespeQueue(speQueue& sq, Elemtype& e){
    if(sq.rear == sq.front){
        cout<<"EMPTY QUEUE!"<<endl;
        return false;
    }
    e = sq.front->data;
    sq.front =sq.front->next;
    return true;
}

void print_speQueue(speQueue sq){
    cout<<"***************************************\n";
    cout<<"Queue: ";
    for(LNode* tmp = sq.front; tmp != sq.rear; tmp = tmp->next)
        cout<<tmp->next->data<<" ";
    cout<<endl;
    int num = 0;
    for(LNode* tmp = sq.rear; tmp->next != sq.front; tmp = tmp->next)
        num++;
    switch (num)
    {
    case 0:
        cout<<"There isn't any free space node."<<endl;
        break;
    
    case 1:
        cout<<"There is 1 free space node."<<endl;
        break;

    default:
        cout<<"There are "<<num<<" free space nodes."<<endl;
        break;
    }
    cout<<"***************************************\n";
    return;
}

int main(void){
    speQueue sq;
    Elemtype rec;
    Init_speQueue(sq);
    print_speQueue(sq);
    EnspeQueue(sq, 5);
    print_speQueue(sq);
    EnspeQueue(sq,3);
    print_speQueue(sq);
    DespeQueue(sq,rec);
    print_speQueue(sq);
    EnspeQueue(sq,3);
    EnspeQueue(sq,8);
    EnspeQueue(sq,1);
    EnspeQueue(sq,7);
    EnspeQueue(sq,10);
    print_speQueue(sq);
    DespeQueue(sq, rec);
    DespeQueue(sq,rec);
    DespeQueue(sq,rec);
    print_speQueue(sq);
    return 0;
}