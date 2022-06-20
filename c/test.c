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
    printf("\n");
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


int sz = 1 << 14;

char* readChar(){

}

int main()
{

    char str[10];

    //scanf("%s", str);
    for (int i = 0; str[i] & 16; i++)
    {
        printf("v : %c\n", str[i]);
        //intTobit(45 + i);
        //printf("\n");
    }

    //printf("%d", 16 & 32);

    intTobit(16);
    intTobit(32);
    if (16 & 32)
    {
        printf("true");
    }
    else
    {
        printf("false");
    }

/*
    printf("%d", 48 & 16);
    intTobit(16);
    printf("\n");
    intTobit(10);
    printf("\n");
    intTobit(32);
*/
    /*
    char r[sz], *p = r; read(0, r, sz);

    for (char c = readChar(); c & 16;)
        if (p == r + s)
            read(0, p = r, s);

    printf("%s", r);
    // printf("%d %d\n", p, r);

    for (; *++p;)
        ;

    // printf("%d %d ", *p, p);


    // printf("\n%d %d\n", p, r);
    write(1, r, p - r); //_exit(0);
*/
    return 0;
}

