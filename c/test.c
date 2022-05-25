#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void main(){
    int N;
    int M;

    scanf("%d %d", &N, &M);
    char s;
    char str[4];

    int i = 0;
    while ((s = getchar()) != '\n')
    {
        str[i++] = s;
    }
printf("%s", str);

    //s = getchar();
    
}