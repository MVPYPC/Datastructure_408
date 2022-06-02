#include "C:/Users/86072/Documents/Clanguage/Datastructure_408/Linear_Table/def.h"

int findMinDistance(int A[], int a, int B[], int b, int C[], int c, int result[]){
    int dstc = INT_MAX;
    int iA = 0;
    int iB = 0;
    int iC = 0;
    while(iA < a && iB < b && iC < c){
        if(dstc > abs(A[iA] - B[iB]) + abs(A[iA] - C[iC]) + abs(C[iC] - B[iB])){
            dstc = abs(A[iA] - B[iB]) + abs(A[iA] - C[iC]) + abs(C[iC] - B[iB]);
            result[0] = A[iA];
            result[1] = B[iB];
            result[2] = C[iC];
        }
        if(A[iA] < B[iB] && A[iA] < C[iC]) 
            iA++;
        else if(B[iB] < A[iA]  && B[iB] < C[iC])
            iB++;
        else
            iC++;
    }
    return dstc;
}

int main(void){
    int testA[] = {-1,0,9};
    int testB[] = {-25,-10,10,11};
    int testC[] = {2,9,17,30,41};
    int res[3];
    cout<<"The minimum distance of ABC is "<<findMinDistance(testA, sizeof(testA)/sizeof(int),
                                                            testB, sizeof(testB)/sizeof(int),
                                                            testC, sizeof(testC)/sizeof(int),
                                                            res)<<endl<<"and it's ";
    for(int i = 0; i < 3; i++){
        cout<<res[i];
        if(i < 2)
            cout<<",";
        else
            cout<<endl;
    }
    
}