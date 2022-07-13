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

    int arr[7] = {31, 4, 159, 2, 653, 58, 979};
    int sortArr[9] = {0,};

    for (int i = 0; i < 7; i++)
    {
        int remainder = arr[i] % 10;
        sortArr[remainder] = arr[i];
    }

    printInt(sortArr, 9);
    return 0;
}