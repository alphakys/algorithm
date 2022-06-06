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

void charArray(char *arr, int n) {
    int i;
    for (i = 0; i < n; i++) {

        printf("%c ", arr[i]);
    }
    printf("\n");
}

int compare(const void *a, const void *b){

    //printf("str : %s %s ", a, b);
    char* s1 = (char *)a;
    char* s2 = (char *)b;

    if(strcmp(s1, s2)>0)
        return 1;
    else if (strcmp(s1, s2) < 0) 
        return -1;
    
}

int main()
{

    int N,M;
    
    scanf("%d %d", &N, &M);

    char strN[10000][501];

    for (int i = 0; i < N; i++)
    {   
        scanf("%s", strN[i]);
    }

    qsort(strN, N, sizeof(strN[0]), compare);
        
    for (int i = 0; i < N; i++)
    {
        printf("%s\n", strN[i]);
    }
    // charArray(strN, 5);
    // printf("%d", strcmp(s, z));

    return 0;
}
