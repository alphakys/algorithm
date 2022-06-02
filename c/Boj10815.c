#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void printArray(char *arr, int n) {
    int i;
    for (i = 0; i < n; i++) {

        printf("%d ", arr[i]);
    }
    printf("\n");
}


int main(){

    int N;
    
    scanf("%d", &N);
    getchar();

    char s;
    char str[N + 1];
    int str_i = 0;
    while ((s = getchar()) != '\n')
    {
        if(s!=' '){
            str[str_i++] = s;
        }
    }

    int M;
    
    scanf("%d", &M);
    getchar();

    char s1;
    char str1[M + 1];
    str_i = 0;
    while ((s = getchar()) != '\n')
    {
        if(s!=' '){
            str1[str_i++] = s;
        }
    }

/*
    printf("%s", str);
    printf("\n");
    printf("%s", str1);
*/

    return 0;
}


