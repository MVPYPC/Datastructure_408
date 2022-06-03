#include "C:/Users/86072/Documents/Clanguage/Datastructure_408/Linear_Table/def.h"

speXDnode* Locate(speXDLinkList& speXL, Elemtype x){
    speXDnode* cur = speXL->next;
    for(; cur != NULL; cur = cur->next)
        if(cur->data == x){
            cur->pred->next = cur->next;
            if(cur->next != NULL)
                cur->next->pred = cur->pred;
            cur->freq++;
            speXDnode* pre = cur->pred;
            while(pre->freq <= cur->freq && pre != speXL)
                pre = pre->pred;
            cur->next = pre->next;
            pre->next->pred = cur;
            pre->next = cur;
            cur->pred = pre;
            break;
        }
    return cur;
}

int main(void){
    Elemtype test[] = {0,1,5,9,8,6,3,7,10,13};
    Elemtype toFind[] = {1,1,2,8,6,9,3,8,7,5,5,5,5,5,13};
    speXDLinkList sL = InitSpeXList_withHead(test, sizeof(test) / sizeof(Elemtype));
    printSpeXList_withHead(sL);
    for(int i = 0; i < sizeof(toFind) / sizeof(int); i++){
        speXDnode* find = Locate(sL, toFind[i]);
        for(int j = 0; j < sizeof(test) / sizeof(Elemtype)*4 + (sizeof(test) / sizeof(Elemtype) - 1)*3 + 5; j++)
            cout<<"*";
        cout<<endl;
        if(find == NULL)
            cout<<toFind[i]<<" NOT FOUND!"<<endl;
        else
            cout<<toFind[i]<<" FOUND!"<<endl;
        printSpeXList_withHead(sL);
        
    }
    for(int j = 0; j < (sizeof(test) / sizeof(Elemtype)*4 + (sizeof(test) / sizeof(Elemtype) - 1)*3 + 5) / 2 - 3; j++)
        cout<<"*";
    cout<<"FINISH";
    for(int j = 0; j < (sizeof(test) / sizeof(Elemtype)*4 + (sizeof(test) / sizeof(Elemtype) - 1)*3 + 5) / 2 - 3; j++)
        cout<<"*";
    cout<<endl;
    return 0;
    
}