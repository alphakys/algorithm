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

    int search = 264;

    int arr[11] = {1, 4, 87, 111, 264, 324, 478, 494, 2300, 11000, 11001};
                 //0  1   2   3    4    5    6    7     8     9       10
    
    while(start<=end)
    {
        int pivot = (start+end) / 2;
        printf("root pivot : %d\n", arr[pivot]);
        
        if(arr[pivot]==search){
            printf("find : %d\n", arr[pivot]);
            break;
        }
        else if(arr[pivot] >search)
        {
            end = pivot-1;
        }else
        {
            start = pivot+1;
        }
        printf("start : %d , pivot : %d , end : %d\n", start, pivot, end);

    }


}