#include <stdio.h>
#include <stdlib.h>

void printInt(int *arr, int n) {
    int i;
    for (i = 0; i < n; i++) {

        printf("%d ", arr[i]);
    }
    printf("\n");
}

int size =1<<18;
char buff[1<<18];

char *p = buff;

char readChar(){
    
    if(p==buff+size){
        fread(p=buff, 1, size, stdin);
    }

    return *p++;
}

int readInt(){
    
    int sum = 0;
    char c = readChar();

    int minus = 1;
    if (c == 45)
    {
        minus = -1;
        c = readChar();
    }

    for (; c & 16; c = readChar())
    {
        sum = (sum * 10) + (c & 15);
    }
   
    return sum * minus;
}

int main()
{

    fread(buff, 1, size, stdin);

    int N = readInt();

    int counting[10001] = {0,};

    for (int i = 0; i < N; i++)
    {
        int c = readInt();
        counting[c]++;
    }

    for (int i = 1; i <= 10000; i++)
    {
        if(counting[i]>0)
        {
            for (int j = 0; j < counting[i]; j++)
            {
                printf("%d\n", i);
            }
        }
    }

    return 0;
}