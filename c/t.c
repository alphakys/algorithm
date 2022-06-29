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


int compare(const void *a, const void *b){

    int num1 = *(int *)a;
    int num2 = *(int *)b;

    if (num1 >= num2)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}


void binarySearch(int* arr, int size, int search){
    //printf("s : %d\n", search);
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
    
     
    for (int i = 0; i < N; i++)
    {
        desc[i] = no[i];
    } 

    qsort(desc,N,sizeof(int),compare);

    for (int i = 0; i < N; i++)
    {
        binarySearch(desc, N, no[i]);
        //printf("%d\n", no[i]);
    }

    return 0;
}
