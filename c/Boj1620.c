#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct linked{
    char* str;
    int original_index;
} linked;

int compare(const void *a, const void *b){

    linked* s1 = (linked *)a;
    linked* s2 = (linked *)b;

    //printf("1: %s  2: %s\n", s1->str, s2->str);
    if (strcmp(s1->str, s2->str) > 0){
        return 1;
    } 
    else if (strcmp(s1->str, s2->str) < 0){
        return -1;
    } 
        
}



int binarySearch(int N, linked* list, char *target){

    int start = 0;
    int end = N-1;

    while (start <= end)
    {
        int pivot = (start+end) / 2;
       
        int flag = strcmp(list[pivot].str, target);
        
        if (flag == 0)
        {
            return (list[pivot].original_index)+1;
        }
        else if(flag >0)
        {
            end = pivot-1;
        }else
        {
            start = pivot+1;
        }
        
    }

    return 0;
}

char strN[100000][21];
char strM[100000][21];

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

    linked linkedList[N];

    for (int i = 0; i < N; i++)
    {
        linkedList[i].original_index = i;
        linkedList[i].str = strN[i];
    }
    
    qsort(linkedList, N, sizeof(linkedList[0]), compare);


    for (int i = 0; i < M; i++)
    {
        if (strM[i][0] >= 49 && strM[i][0] <= 57)
        {
            int index = atoi(strM[i]);
            printf("%s\n",strN[index-1]);
        }else{
            
            printf("%d\n", binarySearch(N, linkedList, strM[i]));
        }
    }

    return 0;
}
