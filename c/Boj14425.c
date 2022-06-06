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

    char* s1 = (char *)a;
    char* s2 = (char *)b;

    if(strcmp(s1, s2)>0)
        return 1;
    else if (strcmp(s1, s2) < 0) 
        return -1;
    
}

char strN[10000][501];
char strM[10000][501];
int cnt = 0;

void binarySearch(int N, char strN[][501], char *target){

    int start = 0;
    int end = N-1;

    while (start <= end)
    {
        int pivot = (start+end) / 2;
        //printf("root pivot : %d\n", strN[pivot]);
        int flag = strcmp(strN[pivot], target);
        if (flag==0)
        {
            //printf("find : %d\n", strN[pivot]);
            cnt++;
            break;
        }
        else if(flag >0)
        {
            end = pivot-1;
        }else
        {
            start = pivot+1;
        }
        //printf("start : %d , pivot : %d , end : %d\n", start, pivot, end);

    }

}


int main()
{

    int N,M;
    
    scanf("%d %d", &N, &M);
    
    for (int i = 0; i < N; i++)
    {   
        scanf("%s", strN[i]);
    }

    for (int i = 0; i < M; i++)
    {   
        scanf("%s", strM[i]);
    }

    qsort(strN, N, sizeof(strN[0]), compare);

    for (int i = 0; i < M; i++)
    {
        //printf("sorted : %s\n", strN[i]);
        //printf("%d\n", strcmp(strN[i], strM[i]));
        binarySearch(N, strN, strM[i]);
    }

    printf("%d", cnt);
    return 0;
}
