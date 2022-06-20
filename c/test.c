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
char sum[6] = "91235";

    //printf("%d", sum[0] - '0');


    int res = 0;
    
    printf("%d", res);
    return 0;
}

//unsigned int a = 1 << 12; 11개 숫자 들어가면 됨

void printArray(int *arr, int n) {
    int i;
    for (i = 0; i < n; i++) {

        printf("%d ", arr[i]);
    }
    printf("\n");
}




int main()
{
    
    
/*
    char c[5] = "111";
    
    char *cp = c;
    //printf("%d\n", p);
    for (; *++cp;){
        printf("%d %d ", *cp, cp);

    }
*/

    char r[1 << 16], *p = r; read(0, r, 1 << 16);
    
    //printf("%d %d\n", p, r);
    
    for (; *++p;);
        //printf("%d %d ", *p, p);

    

    //printf("\n%d %d\n", p, r);
    write(1, r, p - r);_exit(0);

    return 0;
}

