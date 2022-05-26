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



    /*
     for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            
            printf("%c", str[i][j]);
        }
        printf("\n");
    }
*/
int black_flag = 0;
int white_flag = 0;

int main(){

    int N;
    int M;
    //scanf("%d %d", &N, &M);
    char s;
    char str[N+1][M+1];

    int n = 0;

    for (int j = 0; j < N; j++)
    {
        while ( (s = getchar()) != '\n' )
        {
            str[j][n++] = s;
        }
        n = 0;
    }
    

    char** strWhite[8];
    char** strBlack[8];

    char w[9] = "WBWBWBWB";
    char b[9] = "BWBWBWBW";

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

    for (int i = 0; i < 8; i++)
    {
        char *s = strBlack[i];
        for (int j = 0; j < 8; j++)
        {
            
            printf("%d ", s[j]);
        }
        printf("\n");
    }

 

    int itr = 0;
    for (int i = 0; i < M - 7; i++)
    {
        for (int j = 0; j < N - 7; j++)
        {
            while(){
                char *s = strBlack[i];
                if( (str[i][j] - s[j] ) != 0){
                    black_flag++;
                }
            }
        }
    }




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

void check(char** strBlack, char** strWhite, char* str[]){

        for (int i = 0; i < 8; i++)
        {
            char *sb = strBlack[i];
            char *sw = strWhite[i];
            for (int j = 0; j < 8; j++)
            {
                if( (str[i][j] - sb[j] ) != 0){
                    black_flag++;
                }

                if((str[i][j] - sw[j] ) != 0){
                    white_flag++;
                }
            }
            
            
        }

    }