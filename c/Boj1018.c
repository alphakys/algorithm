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

    char** strWhite[8];
    char** strBlack[8];

    char w[9] = "WBWBWBWB";
    char b[9] = "BWBWBWBW";
    //strWhite[0] = w;
    //printf("%s",strWhite[0]);
    for (int i = 0; i < 8; i++)
    {
        char *p1 = w;
        char *p2 = b;
        if (i % 2 == 0)
        {
            strWhite[i] = p1;
            strBlack[i] = p2;
        }
        else if (i % 2 == 1)
        {
            strWhite[i] = p2;
            strBlack[i] = p1;
        }
    }

    //strcat(str[0], str1);
    //printf("%s", );

    for (int i = 0; i < 8; i++)
    {
        
       // printf("%s\n", strWhite[i]);
        
    }

    for (int i = 0; i < 8; i++)
    {
        char *s = strBlack[i];
        for (int j = 0; j < 8; j++)
        {
            
            printf("%d ", s[j]);
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