#include "C:/Users/86072/Documents/Clanguage/Datastructure_408/Linear_Table/def.h"

int find_BackwardsKthNode(LinkList L, int k){
    LNode* slow = L->next;//慢指针
    LNode* fast = L->next;//快指针
    for(int i = 0; i < k; i++)
        if(fast->next != NULL)
            fast = fast->next;//fast先出发k个结点
        else
            return 0;//总长小于k，查找失败
    while(fast != NULL){
        slow = slow->next;
        fast = fast->next;
    }
    cout<<"Find it! It's "<<slow->data<<"."<<endl;//查找成功
    return 1;
}

int main(void){
    Elemtype test[] = {1,2,3,5,6,9,8,7,4,5,2,1,6};
    LinkList L = InitList_withHead(test, sizeof(test) / sizeof(Elemtype));
    if(find_BackwardsKthNode(L, 5) == 0)
        cout<<"Not found!"<<endl;
    return 0;
}