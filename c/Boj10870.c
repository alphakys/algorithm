#include <stdio.h>

#include <stdlib.h>

int fibonacci(int N){
    
    if(N>1){
       return fibonacci(N-1) + fibonacci(N-2);
    }else if(N==1){
        return 1;
    }else{
        return 0;
    }
        
}

int main(){

    int N;
    scanf("%d", &N);

    printf("%d",fibonacci(N)); 
    
    return 0;
}