#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

#define buff_size 5

/*
char buff[buff_size];
char *p = buff;

char* readChar(char ch){

    if(p == buff+buff_size){
        read(0, p=buff, buff_size);
        return *p++;
    }
}
*/

void bitToint(char* str){

    int sum = 0;

    //char bit[9] = "00001111";
    int len = 7;

    for (int i = 0; i < 8; i++)
    {
        int n = (str[i]-48) << len--;
        sum += n;
    }

    printf("%d\n", sum);
}


void intTobit(int a){

    //자신의 index만큼 >> 시프트 연산을 하면 첫번째 자리에서 자신의 숫자를 구할 수 있다.
    char bit[9];

    for (int i = 7, j=0; i >= 0; i--, j++)
    {
        bit[j] = (a >> i) & 1;
    }
    
    for (int i = 0; i <8; i++)
    {
       printf("%d", bit[i]);
       if(i==3){
           printf(" ");
       }
    }
}

int readInt(){

    return 0;
}

//unsigned int a = 1 << 12; 11개 숫자 들어가면 됨

void main()
{
    
    // intTobit(20);
    10 << 1;

    //printf("\ntest : %d\n", 5 << 1);

    for (int i = 0; i < 11; i++)
    {
        printf("i : %d ", i);intTobit(i);
        printf("\n");
    }

    char sum[6] = "91235";

    int res = 0;
    for (int i = 0; sum[i] != '\0'; ++i)
    {
        res = res *
        printf("%d", sum[i] & 15);
    }   
    
    
    //printf("%d", 50 & 15);
    
    
}