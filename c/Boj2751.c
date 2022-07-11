#include <stdio.h>
#include <stdlib.h>
void printInt(int *arr, int n) {
    int i;
    for (i = 0; i < n; i++) {

        printf("%d ", arr[i]);
    }
    printf("\n");
}

int size =1<<10;
char buff[1<<10];

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


int sorted[10];

void conquer(int* arr, int left, int right){

    if(arr[left]> arr[right])
    {
        sorted[left] = arr[right];
        sorted[right] = arr[left];
    }
    else
    {
        sorted[right] = arr[right];
        sorted[left] = arr[left];
    }
}

void divide(int* arr, int left, int right){

    int mid = (left+right)/2;

    if(mid==right)
    {
        conquer(arr, left, right);
        printf("left : %d, right : %d\n", left, right);
        printInt(sorted, 10);
    }
    else
    {
        divide(arr, left, mid);
        divide(arr, mid + 1, right);
    }

    
}

void mergetSort(){
    
}


int main(){
    
    /* fread(buff, 1, size, stdin);

    int N = readInt();

    int arr[1000];
    for (int i = 0; i < N; i++)
    {
        arr[i] = readInt();
    } */

    int arr[8] = {21, 10, 12, 20, 25, 13, 15, 22};

    divide(arr, 0, 7);

    printf("===========\n");
    
    printInt(sorted, 10);
    return 0;
}