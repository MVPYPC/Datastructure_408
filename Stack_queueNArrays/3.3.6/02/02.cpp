#include "C:/Users/86072/Documents/Clanguage/Datastructure_408/def.h"

enum Type{
    Hard,
    Soft
};

typedef struct train{
    Type type;
    struct train* next;
}trainNode, *Train;

void dispatchTrain(Train& line){
    Stack buf = NULL;
    trainNode* record = line;
    for(trainNode* dispatcher = line->next; dispatcher != NULL; dispatcher = dispatcher->next)
        switch (dispatcher->type)
        {
        case Hard:
            pushStack(buf,Hard);
            break;

        case Soft:
            record->next = dispatcher;
            record = dispatcher;
            break;
        
        default:
            break;
        }
    while(!isEmpty(buf)){
        trainNode* add = (trainNode*)malloc(sizeof(trainNode));
        add->type = popStack(buf) == Hard ? Hard : Soft;
        record->next = add;
        record = add;
    }
    record->next = NULL;
    return;
}

void Initrain(Train& line, Type type[], int len){
    line = (Train)malloc(sizeof(Train));
    trainNode* pas = line;
    for(int i = 0; i < len; i++){
        trainNode* tmp = (trainNode*)malloc(sizeof(trainNode));
        tmp->type = type[i];
        pas->next = tmp;
        pas = tmp;
    }
    pas->next = NULL;
    return;
}

void printrain(Train line){
    trainNode* cur = line->next;
    while(cur != NULL){
        cout<<" *";
        if(cur->type == Hard)
            cout<<"H";
        else
            cout<<"S";
        cur = cur->next;
        cout<<"* ";
    }
    cout<<endl;
    return;
}

int main(void){
    Train line;
    Type type[] = {Soft,Hard,Hard,Soft,Soft};
    Initrain(line, type, sizeof(type) / sizeof(Type));
    printrain(line);
    dispatchTrain(line);
    printrain(line);
    return 0;
}
