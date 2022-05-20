#include <stdio.h>

#include <string.h>
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
    //scanf("%d", &N);
    char s0[84]= "어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.";
    char s1[29] = "\"재귀함수가 뭔가요?\"";
    char s2[111] = "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.";
    char s3[112] = "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.";
    char s4[123] = "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"";

    int len = strlen(s4);
    printf("%d", len);
    for (int i = 0; i < len; i++)
    {
        printf("%c", s1[i]);
    }

    //printf();
    //printf("어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.");

    
    

    return 0;
}