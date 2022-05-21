#include <stdio.h>
#include <string.h>


void print(char* str){

    int len = strlen(str);
    for (int i = 0; i < len; i++)
    {
        printf("%c", str[i]);
    }
}


void recur2(int N, int dest){
    char s0[5] = "____";
    //char s1[30] = "\"재귀함수가 뭔가요?\"\n";
    //char s5[62] = "\"재귀함수는 자기 자신을 호출하는 함수라네\"\n";
    char s6[25] = "라고 답변하였지.\n";

    if (N <= dest-1)
     {
         recur2(N + 1, dest);
     }
    
    for (int j = 0; j < N; j++)
    {
        printf("%s",s0);
    }
    printf("%s", s6);
}


void recur(int N){
     char s0[5] = "____";
     
     char s1[30] = "\"재귀함수가 뭔가요?\"\n";
     char s2[112] = "\"잘 들어보게. 옛날옛날 한 산 꼭대기에 이세상 모든 지식을 통달한 선인이 있었어.\n";
     char s3[114] = "마을 사람들은 모두 그 선인에게 수많은 질문을 했고, 모두 지혜롭게 대답해 주었지.\n";
     char s4[124] = "그의 답은 대부분 옳았다고 하네. 그런데 어느 날, 그 선인에게 한 선비가 찾아와서 물었어.\"\n";

     //printf("%d", strlen(s6));
     if (N > 1)
     {
         recur(N - 1);
         
     }

    for (int j = 0; j < N-1; j++)
    {
        printf("%s",s0);
    }
    printf("%s", s1);

    for (int j = 0; j < N-1; j++)
    {
        printf("%s",s0);
    }
    printf("%s", s2);

    for (int j = 0; j < N-1; j++)
    {
        printf("%s",s0);
    }
    printf("%s", s3);

    for (int j = 0; j < N-1; j++)
    {
        printf("%s",s0);
    }
    printf("%s", s4);

}

int main(){

    int N;
    scanf("%d", &N);
    
    printf("어느 한 컴퓨터공학과 학생이 유명한 교수님을 찾아가 물었다.\n");
    
    char s0[5] = "____";
     
    char s1[30] = "\"재귀함수가 뭔가요?\"\n";
    char s5[62] = "\"재귀함수는 자기 자신을 호출하는 함수라네\"\n";

    recur(N);

    for (int j = 0; j < N; j++)
    {
        printf("%s",s0);
    }
    printf("%s", s1);

    for (int j = 0; j < N; j++)
    {
        printf("%s",s0);
    }
    printf("%s", s5);

    recur2(0, N);
     
    return 0;
}