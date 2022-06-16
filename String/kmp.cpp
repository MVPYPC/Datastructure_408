#include "C:/Users/86072/Documents/Clanguage/Datastructure_408/def.h"

void get_next(HString T, int next[]){
    int j = 1, i = 0;
    next[1] = 0;
    while(j < T.length)
        if(i == 0 || T.ch[j] == T.ch[i])
            next[++j] = ++i;
        else
            i = next[i];
}

int Index_KMP(HString S, HString T, int next[]){
    int pos = 1;
    int i = 1;
    while(i <= S.length && pos <= T.length)
        if(pos == 0 || S.ch[i] == T.ch[pos]){
            i++;
            pos++;
        }
        else
            pos = next[pos];
    if(pos > T.length)
        return i - T.length;
    else return 0;
}

int main(void){
    HString T;
    char test[] = "abaabcaba";
    StrAssign(T, test, sizeof(test) / sizeof(char));
    int next[sizeof(test) / sizeof(char)];
    get_next(T, next);
    cout<<"j:     ";
    for(int i = 1; i < sizeof(test) / sizeof(char); i++)
        cout<<i<<" ";
    cout<<endl<<"mode:  ";
    for(int i = 0; i < sizeof(test) / sizeof(char); i++)
        cout<<test[i]<<" ";
    cout<<endl<<"next:  ";
    for(int i = 1; i < sizeof(next) / sizeof(int); i++)
        cout<<next[i]<<" ";
    cout<<endl;
    char mode[] = "bcab";
    HString S;
    StrAssign(S, mode, sizeof(test) / sizeof(char));
    cout<<"Index(T, S): "<<Index(T, S)<<endl;
    cout<<"Index_KMP(T, S): "<<Index_KMP(T, S, next)<<endl;
    return 0;
}