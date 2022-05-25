#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void main(){
    int N;
    int M;

    scanf("%d %d", &N, &M);
    char s;
    char str[N+1][M+1];

    int i = 0;

    for (int j = 0; j < N; j++)
    {
        while ( (s = getchar()) != '\n' )
        {
            str[j][i++] = s;
        }
        i = 0;

    }
    
     for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            
            printf("%c", str[i][j]);
        }
        printf("\n");
    }


    //printf("%s", str[0]);

    //s = getchar();
    
}