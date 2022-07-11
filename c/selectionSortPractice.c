#include <stdio.h>
#include <stdlib.h>

void printInt(int *arr, int n) {
    int i;
    for (i = 0; i < n; i++) {

        printf("%d ", arr[i]);
    }
    printf("\n");
}

int size =7;
char buff[7];

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
    
    for (int i = 0; i < N-1; i++)
    {
        int min = arr[i];
        int min_pos = i;

        for (int j = i + 1; j < N; j++)
        {
            if(min>arr[j]){
                min = arr[j];
                min_pos = j;
            }
               
        }
        //printf("i : %d min_pos : %d\n", i, min_pos);
        swap(arr, i, min_pos);
    }

    for (int i = 0; i < N; i++)
    {
        printf("%d\n", arr[i]);
    }
    
    return 0;
}

