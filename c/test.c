#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
char rbuf[1 << 20];


int strToint(char* str){
    int start = 0;

    int sum = 0;

    for (int i = 0; str[i] != '\0'; ++i)
    {
        printf("%c", str[i]);
        //sum = (str[i]-48)*(10);
    }

    //printf("%d", sum);
    return sum;
}


void main(){

    int N = 11;
    int start = 0;
    int end = N-1;

    int search = 11001;

    int arr[11] = {1, 4, 87, 111, 264, 324, 478, 494, 2300, 11000, 11001};
                 //0  1   2   3    4    5    6    7     8     9       10
    int pivot = N / 2;

    for (int i = 0; i < N; i++)
    {
        printf("root pivot : %d\n", arr[pivot]);
        
        if(arr[pivot]==search){
            printf("find : %d i : %d\n", arr[pivot], i);
            break;
        }
        else if(arr[pivot] >search)
        {
            end = pivot;
            pivot = (start + pivot) / 2;
        }else
        {
            start = pivot;
            pivot = start+ (end-start+1)/2;
        }
        printf("start : %d , pivot : %d , end : %d\n", start, pivot, end);

    }


}