#include <stdio.h>
//#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int sz = 15;
char str[15];
char *p = str;

char readChar()
{
    /*
    if (p == str+sz)
    {
        fread(p=str, 1, sz, stdin);
    }
    */
    return *p++;
}

int readInt()
{
    int sum = 0;
    char c = readChar();

    int minus = 1;

    if (c == 45)
    {
        minus = -1;
        c = *p++;
    }

    for (; c & 16; c = readChar())
    {
        sum = sum * 10 + (c & 15);
    }

    return sum * minus;
}

typedef struct node{
    int val;
    int idx;
} node;

int compare(const void *a, const void *b){

    node *A = (node *)a;
    node *B = (node *)b;

    int x = A->val;
    int y = B->val;

    if(x>=y){
        return 1;
    }else{
        return -1;
    }
}


void binarySearch(int* arr, int size, int search){
    
    int start = 0;
    int end = size-1;
    int pivot;// = size / 2;
    
    while(start<=end){
        
        pivot = (start + end) / 2;

        if(arr[pivot] <search){
            
            start = pivot+1;
        
        }else if(arr[pivot] ==search){
            printf("%d ", pivot);
            break;    

        }else{
            
            end = pivot-1;
        }
    }
}

int no[1000000];
int desc[1000000];

int main()
{
    
    fread(str, 1, sz, stdin);
    
    int N = readInt();
   
    for (int i = 0; i < N; i++)
    {
        
        no[i] = readInt();
        
    }
    memcpy(desc, no, N);

    qsort(desc,N,sizeof(int),compare);

    for (int i = 0; i < N; i++)
    {
        binarySearch(desc, N, no[i]);
        //printf("%d\n", desc[i]);
    }

    return 0;
}
