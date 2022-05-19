#include <stdio.h>

#include <stdlib.h>

int factorial(int* N){

    if(*N>0){
        factorial(*N-1);
    };
}

int main(){

    int N;
    scanf("%d", &N);

    factorial(&N);

    for (int i = 0; i < N; i++)
    {
        
    }
    
    
    printf("%d",);
    return 0;
}