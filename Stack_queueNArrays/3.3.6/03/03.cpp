#include "C:/Users/86072/Documents/Clanguage/Datastructure_408/def.h"

double Pn_recursion(double x, int n){
    switch (n)
    {
    case 0:
        return 1;
    
    case 1:
        return 2 * x;

    default:
        return 2 * x * Pn_recursion(x, n - 1) - 2 * (n - 1) * Pn_recursion(x, n - 2);
    }
}

typedef struct funcstack{
    int n;
    int fx;
}Funcstack;

double Pn_No_recursion(double x, int n){
    Funcstack fstack[MAX_SIZE];
    int top = -1;//栈顶指针
    double val1 = 1, val2 = 2 * x;//边界条件
    for(int i = n; i > 1; i--)
        fstack[++top].n = i;
    while(top >= 0){
        fstack[top].fx = 2 * x * val2 - 2 * (fstack[top].n - 1) * val1;
        val1 = val2;
        val2 = fstack[top--].fx;
    }
    if(n == 0)
        return val1;
    else
        return val2;

}

int main(void){
    int n = 10;
    int x = 3;
    int Pn_re = Pn_recursion(x,n);
    int Pn_nore = Pn_No_recursion(x,n);
    if(Pn_re == Pn_nore)
        cout<<"Success! The result of P"<<"n="<<n<<"(x="<<x<<") is "<< Pn_re<<endl;
    else{
        cout<<"ERROR! The result of Pn(x) by Pn_No_recursion is "<<Pn_nore<<endl;
        cout<<"             while "<< Pn_re<<"by Pn_recursion."<<endl;
    }
    return 0;
}