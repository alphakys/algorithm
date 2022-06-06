#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
char rbuf[1 << 20];

int compare(const void *a, const void *b){

    if(strcmp(a,b)>0){
        return -1;
    }
    else
    {
        return 1;
    };
}

void main(){

    char s[11] = "Acbok";
    char s1[11] = "Ceedrill";
    char s2[11] = "Buslill";

    char *arr[3];
    arr[0] = s;
    arr[1] = s1;
    arr[2] = s2;

    qsort(arr, 3, sizeof(arr[0]), compare);
    
    for (int i = 0; i < 3; i++)
    {
        printf("%s\n", arr[i]);
    }
    
    
}