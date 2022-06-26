#include <stdio.h>

#include <unistd.h>


void printArray(int *arr, int n) {
    int i;
    for (i = 0; i < n; i++) {

        printf("%d ", arr[i]);
    }
    printf("\n");
}


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


int sz = 10;
char str[10];
char *p = str;

char readChar()
{
    if(p == str+sz){
        fread(p = str, 1, sz, stdin);
    }
    //printf("p : %d, %d\n", p, *p);
    return *p++;
}

int readInt()
{
    int sum = 0;
    
    for (char c = readChar(); c & 16; c = readChar()){
        sum = sum * 10 + (c & 15);
        
    }
    //p++;
    return sum;
}

int main()
{
    fread(str, 1, sz, stdin);
    read();
    // printf("size : %d\n", );
    // printf("%d\n", str);

    int n = readInt();

    for (int i = 0; i < n; i++)
    {
        int a = readInt();
        printf("a : %d\n", a);
    }

    return 0;
}

