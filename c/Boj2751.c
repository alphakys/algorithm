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

void conquer(int* arr, int start, int mid, int end)
{
    int left = start;
    int right = mid + 1;
    
    while (start <= end)
    {
        if(left==mid)
        {
            //printf("1\n");
            //printf("st : %d right : %d\n", start, right);
            sorted[start++] = arr[right++];
        }
        else if(right==end)
        {
            //printf("2\n");
            sorted[start++] = arr[left++];
        }
        else
        {
            //printf("3\n");
            if(arr[left]> arr[right])
            {
                sorted[start++] = arr[right++];
                
            }
            else
            {
                sorted[start++] = arr[left++];
                
            }
        }
        

    }

    for (int i = 0; i <= end; i++)
    {
        arr[i] = sorted[i];
    }
}

void divide(int* arr, int left, int right){

    int mid = (left+right)/2;

    if(mid!=right)
    {
        divide(arr, left, mid);
        divide(arr, mid + 1, right);
    }
    
    printf("left : %d, mid : %d, right : %d\n", left, mid, right);
    conquer(arr, left, mid, right);
    
    
    printInt(sorted, 10);

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