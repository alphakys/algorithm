#include <stdio.h>

void printArray(char *arr, int n) {
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


int sz = 1<<16;
char str[1<<16];
char *p = str;

char readChar()
{
    
    if (p == str+sz)
    {
        fread(p=str, 1, sz, stdin);
    }

    return *p++;
}

int readInt()
{
    int sum = 0;
    
    for (char c = readChar(); c & 16; c = readChar()){
        
        sum = sum * 10 + (c & 15);
    }
    
    return sum;
}




int main()
{
    
    int n;
    scanf("%d", &n);

    printf("%d", n);

    //printf("%d", 45 & 44);
    return 0;
}
