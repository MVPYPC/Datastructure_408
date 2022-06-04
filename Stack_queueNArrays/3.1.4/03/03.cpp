#include "C:/Users/86072/Documents/Clanguage/Datastructure_408/def.h"

bool isLegal(char test[]){
    strStack S = NULL;
    for(int i = 0; test[i] != '\0'; i++)
        switch (test[i])
        {
        case 'I':
            pushstrStack(S,'I');
            break;
        
        case 'O':
            if(isstrEmpty(S))
                return false;
            else
                popstrStack(S);
            break;
        
        default:
            cout<<"ERROR CHARACTER!"<<endl;
            return false;
        }
    
    if(isstrEmpty(S))
        return true;
    else 
        return false;
}

int main(void){
    char test[4][9] = {{"IOIIOIOO"},{"IOOIOIIO"},{"IIIOIOIO"},{"IIIOOIOO"}};
    for(int i = 0; i < 4; i++){
        if(isLegal(test[i]))
            cout<<"test["<<i<<"] = "<<test[i]<<" is legal."<<endl;
        else
            cout<<"test["<<i<<"] = "<<test[i]<<" is illegal."<<endl;
    }

}