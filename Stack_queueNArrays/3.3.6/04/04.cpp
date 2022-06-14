#include "C:/Users/86072/Documents/Clanguage/Datastructure_408/def.h"

void manage(Queue& boat, Queue& car, Queue& truck){
    int num_car = 0;
    int tmp;
    for(int num_boat = 0; num_boat < 10; num_boat++)//渡船容量
        if(!isEmpty(car) || !isEmpty(truck))
            if(isEmpty(car)){//等待客车为空,货车上船
                DeQueue(truck,tmp);
                EnQueue(boat, tmp);
            }else if(isEmpty(truck)){//等待货车为空，客车上船
                DeQueue(car,tmp);
                EnQueue(boat, tmp);
            }else{
                if(num_car == 4){//已上4辆客车，货车上船
                    DeQueue(truck,tmp);
                    EnQueue(boat, tmp);
                    num_car = 0;
                }else{//未上满4辆客车，客车上船
                    DeQueue(car,tmp);
                    EnQueue(boat, tmp);
                    num_car++;
                }
            }
    return;
}

int main(void){
    Queue boat;
    Queue car;
    Queue truck;
    Init_Queue(boat);
    Init_Queue(car);
    Init_Queue(truck);
    for(int i = 0; i < 5; i++)
        EnQueue(car,i);
    for(int i = 10; i < 20; i++)
        EnQueue(truck, i);
    manage(boat, car, truck);
    cout<<"***************************************\n";
    cout<<"Queue: ";
    for(LNode* tmp = boat.front; tmp != boat.rear; tmp = tmp->next)
        if(tmp->data < 10)
            cout<<" @car@ ";
        else
            cout<<" @truck@ ";
    cout<<endl<<"***************************************\n";
    return 0;
}