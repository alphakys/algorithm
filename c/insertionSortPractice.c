#include <stdio.h>
#include <stdlib.h>

void printInt(int *arr, int n) {
    int i;
    for (i = 0; i < n; i++) {

        printf("%d ", arr[i]);
    }
    printf("\n");
}

int size =10;
char buff[10];

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

void swap(int* arr, int a, int b){
    int tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}

int main(){
    
    fread(buff, 1, size, stdin);

    int N = readInt();

    int arr[1000];
    for (int i = 0; i < N; i++)
    {
        arr[i] = readInt();
    }

    int len = N;
    
    for (int i = 1; i < N; i++)
    {
        int pivot = i;
        
        for (int j = pivot-1; j >=0 && arr[pivot] < arr[j]; j--)
        {
            swap(arr, pivot, j);

            pivot = j;
            
        }
    }

    for (int i = 0; i < N; i++)
    {
        printf("%d\n", arr[i]);
    }
    
    return 0;
}