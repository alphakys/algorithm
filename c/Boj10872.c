#include <stdio.h>

#include <stdlib.h>

int factorial(int N){

    if(N>1){
       return  N * factorial(N-1);
    }else{
        return 1;
    }
        
}

int main(){

    int N;
    scanf("%d", &N);

    printf("%d",factorial(N)); 
    

    return 0;
}