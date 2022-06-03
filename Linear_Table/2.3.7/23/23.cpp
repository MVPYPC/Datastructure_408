#include "C:/Users/86072/Documents/Clanguage/Datastructure_408/Linear_Table/def.h"
StrNode* mutual_StrNode(String s1, String s2){
    int gap = StringLength_withHead(s1) - StringLength_withHead(s2);
    StrNode* longer = gap >= 0 ? s1 : s2;
    StrNode* shorter = gap >= 0 ? s2 : s1;
    for(int i = 0; i < gap; i++)
        longer = longer->next;
    while(longer != shorter && longer != NULL){
        longer = longer->next;
        shorter = shorter->next;
    }
    return longer;
}

int main(){
    char test[] = "loading";
    String s1 = InitString(test, sizeof(test) / sizeof(char));
    String s2 = (String)malloc(sizeof(StrNode));
    s2->next = (StrNode*)malloc(sizeof(StrNode));
    s2->next->next = s1->next->next->next;
    StrNode* result = mutual_StrNode(s1,s2);
    printString_withoutHead(s1);
    printString_withoutHead(s2);
    printString_withoutHead(result);
    return 0;
}