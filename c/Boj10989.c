#include <stdio.h>
#include <stdlib.h>

void printInt(int *arr, int n) {
    int i;
    for (i = 0; i < n; i++) {

        printf("%d ", arr[i]);
    }
    printf("\n");
}

int size =23;
char buff[23];

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
    
    int arr[11] = {0,};
    
    for (int i = 0; i < N; i++)
    {
        int c = readInt();
        arr[i] = c;
        counting[c]++;
    }
    
    printInt(counting, 10);
    
    int sum = 0;
    for (int i = 1; i <= 10000; i++)
    {
        sum += counting[i];
        counting[i] = sum;
    }

    int sorted[12] = {0,};
    
    for (int i = 0; i <= 10; i++)
    {   
        int idx = counting[arr[i]];
        sorted[idx] = arr[i];
        counting[arr[i]]--;
    }

    printInt(sorted, 11);
    return 0;
}