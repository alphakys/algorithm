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

        printf("%d ", arr[i]);
    }
    printf("\n");
}


int main()
{

    int N;

    scanf("%d", &N);

    int n;

    int heapArr[10] = {0,};
    int index = 1;
    
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &n);
        if(n==0){
            printf("%d\n", heapArr[1]);
        }
        else
        {
            /*
            if(heapArr[0] == 0){
                heapArr[0] = n;
                index++;
            }
            */
            heapArr[index] = n;
            int tmp_index = index;

            while (heapArr[index / 2] <= n && index > 0)
            {
                int tmp = heapArr[index / 2];
                heapArr[index / 2]= heapArr[index];
                heapArr[index] = tmp;
                index = index / 2;
            }
            index = ++tmp_index;
        }
        //printf("%d %d\n", index, heapArr[index-1]);
    }

    printArray(heapArr, 10);
    return 0;
}

