#include "C:/Users/86072/Documents/Clanguage/Datastructure_408/Linear_Table/def.h"

bool isSymetry(DLinkList DL){
    if(isEmpty_withHead(DL))
        return true;
    DNode* head = DL->next;
    DNode* tail = DL->prior;
    while(head != tail && head->next != tail)
        if(head->data != tail->data)
            return false;
        else{
            head = head->next;
            tail = tail->prior;
        }
    return true;

}

int main(void){
    Elemtype test[] = {5,4,1,4,5,0};
    DLinkList DL = InitDList_withHead_circulation(test, sizeof(test) / sizeof(Elemtype));
    printDList_withHead(DL);
    if(isSymetry(DL))
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;
    return 0;
}