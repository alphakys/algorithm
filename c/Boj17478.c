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
    char s[4]= "헤";

    for(int i=0; i<4; i++){
        printf("%c", s[i]);
    }
    //printf();
    //printf("어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.");

    
    
    return 0;
}