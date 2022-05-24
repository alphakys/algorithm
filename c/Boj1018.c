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
    int M;
    //scanf("%d %d", &N, &M);
    //getchar();

    char str[8][8];

    //printf("%d", sizeof(char**));

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            str[i][j] = 'w';
        }
    }

    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            
            printf("%c", str[i][j]);
        }
        printf("\n");
    }

    //char str[700];
    //fgets(str, 700, stdin);

   
/*
    int max = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            int k = N - 1;
            while (j<k)
            {
                int sum = arr[i] + arr[j] + arr[k];
                //printf("arr[%d] : %d, arr[%d] : %d, arr[%d] : %d, sum : %d\n", i, arr[i], j, arr[j], k, arr[k], sum);
                if (sum <= M)
                {
                    if(max<sum){
                        max = sum;
                    }
                }
                k--;
            }
            
        }
    }
    printf("%d", max);
    */
    return 0;
}