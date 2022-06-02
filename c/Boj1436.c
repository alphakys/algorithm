#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void printArray(int *arr, int n) {
    int i;
    for (i = 0; i < n; i++) {

        printf("%d ", arr[i]);
    }
    printf("\n");
}


int main(){

    int N;
    
    scanf("%d", &N);

    char str[5] = "0666";

    int n = 0;
    while (n++<N)
    {
        
        for (int i = 0; i < N; i++)
        {
            str[0] = 48 + i;
            if((int)str[0]< 54)
            {
                
                printf("%s\n", str);

            }
            else
            {
                //str[0] = 54;
                str[3] = 48 + i;
            }


        }

    }
    
    

    return 0;
}


