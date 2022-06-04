#include "C:/Users/86072/Documents/Clanguage/Datastructure_408/def.h"

bool isCentralSymmetry(String s){
    if(s == NULL || s->next == NULL)
        return false;
    strStack stack = NULL;
    StrNode* slow = s->next;
    StrNode* fast = s->next;
    bool odd = true;
    while(fast->next != NULL){
        pushstrStack(stack, slow->c);
        slow = slow->next;
        fast = fast->next;
        if(fast->next != NULL)
            fast = fast->next;
        else{
            odd = false;
            break;
        }
    }
    StrNode* cur = odd ? slow->next : slow;
    while(!isstrEmpty(stack) && cur != NULL)
        if(cur->c == stack->c){
            popstrStack(stack);
            cur = cur->next;
        }
        else
            return false;
    return isstrEmpty(stack) && cur == NULL ? true : false;
}

int main(void){
    char test[] = "xyyx";
    String s = InitString(test, sizeof(test) / sizeof(char));
    if(isCentralSymmetry(s))
        cout<<"String: "<<test<<" is central symmetry."<<endl;
    else
        cout<<"String: "<<test<<" isn't central symmetry."<<endl;
    return 0;
}