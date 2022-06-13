#include "C:/Users/86072/Documents/Clanguage/Datastructure_408/def.h"

bool isMatch(char par[]){
    strStack stack = NULL;
    for(int i = 0; par[i] != '\0'; i++){
        if(par[i] == '(' || par[i] == '[' || par[i] == '{'){
            pushstrStack(stack, par[i]);
            continue;
        }
        switch (par[i])
        {
        case ')':
            if(stack->c == '(')
                popstrStack(stack);
            else
                return false;
            break;

        case ']':
            if(stack->c == '[')
                popstrStack(stack);
            else
                return false;
            break;
        
        case '}':
            if(stack->c == '{')
                popstrStack(stack);
            else
                return false;
            break;
        
        default:
            return false;
        }
    }
    return isstrEmpty(stack);
}

int main(void){
    char test[] = "((([{}]))";
    cout<<"String: "<<test<<" is ";
    if(isMatch(test))
        cout<<"LEGAL.";
    else
        cout<<"ILLEGAL.";
    return 0;
}