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

int black_flag = 0;
int white_flag = 0;


int main(){

    int N;
    int M;
    scanf("%d %d", &N, &M);
    getchar();
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
/*

    for (int j = 0; j < N; j++)
    {
        for (int i = 0; i < M; i++)
        {
            printf("%c", str[j][i]);
        }
        printf("\n");
    }
*/
    for (int i = 0; i < M - 7; i++)
    {
        for (int j = 0; j < N - 7; j++)
        {
            int iPoint = i;
            int jPoint = j;
            for (int l = 0; l < 8; l++)
            {
                char *sb = strBlack[l];
                char *sw = strWhite[l];
                for (int k = 0; k < 8; k++)
                {
                    //printf("%c, %c,,, %d, %d\n", str[iPoint][jPoint], sw[k], iPoint, jPoint);
                    if ((str[iPoint][jPoint] - sb[k]) != 0)
                    {
                        black_flag++;
                    }

                    if ((str[iPoint][jPoint] - sw[k]) != 0)
                    {
                        white_flag++;
                    }
                    jPoint++;
                }
                iPoint++;
                jPoint = j;
            }
            printf("%d %d\n", white_flag, black_flag);
            white_flag = 0;
            black_flag = 0;
        }
    }



        
        /*
            for (int i = 0; i < 8; i++)
            {
                char *s = strBlack[i];
                for (int j = 0; j < 8; j++)
                {

                    printf("%d ", s[j]);
                }
                printf("\n");
            }
        */

        /*
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
        */

        return 0;
}
