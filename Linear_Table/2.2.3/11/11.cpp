#include "C:/Users/86072/Documents/Clanguage/Datastructure_408/Linear_Table/def.h"

//法1
bool findMid_1(SqList A, SqList B, Elemtype* res){
    int cur_A = 0;
    int cur_B = 0;
    enum WHICH {
        a = 1,b
    }which;
    for(int i = 0; i < (A.length + B.length) / 2; i++){
        if(A.data[cur_A] <= B.data[cur_B]){
            cur_A++;
            which = a;
        }
        else{
            cur_B++;
            which = b;
        }
    }
    switch (which){
    case a:
        *res = A.data[cur_A - 1];
        break;

    case b:
        *res = B.data[cur_B - 1];
        break;
    
    default:
        return false;
    }
    return true;
}


//法2
void Merge(int sourceArr[],int tempArr[], int startIndex, int midIndex, int endIndex)
{
    int i = startIndex, j=midIndex+1, k = startIndex;
    while(i!=midIndex+1 && j!=endIndex+1)
    {
        if(sourceArr[i] > sourceArr[j])
            tempArr[k++] = sourceArr[j++];
        else
            tempArr[k++] = sourceArr[i++];
    }
    while(i != midIndex+1)
        tempArr[k++] = sourceArr[i++];
    while(j != endIndex+1)
        tempArr[k++] = sourceArr[j++];
    for(i=startIndex; i<=endIndex; i++)
        sourceArr[i] = tempArr[i];
}
 
//内部使用递归
void MergeSort(int sourceArr[], int tempArr[], int startIndex, int endIndex)
{
    int midIndex;
    if(startIndex < endIndex)
    {
        midIndex = startIndex + (endIndex-startIndex) / 2;//避免溢出int
        MergeSort(sourceArr, tempArr, startIndex, midIndex);
        MergeSort(sourceArr, tempArr, midIndex+1, endIndex);
        Merge(sourceArr, tempArr, startIndex, midIndex, endIndex);
    }
}

bool findMid_2(SqList A, SqList B, Elemtype* res){
    for(int i = A.length; i < A.length + B.length; i++)
        A.data[i] = B.data[i - A.length];
    Elemtype tmp[MAX_SIZE];
    MergeSort(A.data, tmp, 0, A.length + B.length);
    *res = A.data[(A.length + B.length) / 2 - 1];
    return true;
}

//法3
bool findMid_3(SqList A, SqList B, Elemtype* res){
    if(A.length != B.length)
        return false;
    if(A.length == 1){
        *res = A.data[0] <= B.data[0] ? A.data[0] : B.data[0];
        return true;
    }
    int Alow = 0;
    int Ahigh = A.length;
    int Amid = (Alow + Ahigh) / 2;
    int Blow = 0;
    int Bhigh = B.length;
    int Bmid = (Blow + Bhigh) / 2;
    while(Alow != Ahigh){
        if(A.data[Amid] >= B.data[Bmid]){
            Ahigh = Amid;
            Blow = Bmid;
        }else{
            Alow = Amid;
            Bhigh = Bmid;
        }
        Amid = (Ahigh + Alow) / 2;
        Bhigh = (Blow + Bhigh) / 2;
    }
    *res = A.data[Amid] >= B.data[Bmid] ? A.data[Amid] : B.data[Bmid];
    return true;
}
 

int main(void){
    Elemtype test1[] = {11,13,15,17,19};
    Elemtype test2[] = {2,4,6,8,20};
    SqList L1;
    initSqList(L1, test1, sizeof(test1) / sizeof(Elemtype));
    SqList L2;
    initSqList(L2, test2, sizeof(test2) / sizeof(Elemtype));
    Elemtype res;
    if(findMid_1(L1, L2, &res))
        cout<<"res1 = "<<res<<endl;
    if(findMid_2(L1, L2, &res))
        cout<<"res2 = "<<res<<endl;
    if(findMid_3(L1, L2, &res))
        cout<<"res3 = "<<res<<endl;
    return 0;
}