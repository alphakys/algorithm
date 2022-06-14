#include <stdio.h>
#include <stdlib.h>


void printArray(int *arr, int n) {
    int i;
    for (i = 0; i < n; i++) {

        printf("%d ", arr[i]);
    }
    printf("\n");
}


unsigned int heapArr[100001] = {0,};
int main()
{

    int N;

    scanf("%d", &N);

    unsigned int n;

    
    int index = 1;
    
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &n);
        if(n==0){

            printf("answer : %d\n", heapArr[1]);
            //index = index - 1;
            heapArr[1] = heapArr[index];

            int del_idx = 1;
            
            while (heapArr[del_idx * 2] >= heapArr[del_idx] || heapArr[(del_idx*2) +1] >= heapArr[del_idx])
            {
                printf("del idx : %d", del_idx);
                if (heapArr[del_idx * 2] >= heapArr[(del_idx * 2) + 1])
                {
                    int tmp = heapArr[del_idx];
                    heapArr[del_idx]= heapArr[del_idx * 2];
                    heapArr[del_idx * 2] = tmp;
                    del_idx = del_idx * 2;
                }
                else
                {
                    int tmp = heapArr[del_idx];
                    heapArr[del_idx]= heapArr[(del_idx * 2) +1];
                    heapArr[(del_idx * 2) +1] = tmp;
                    del_idx = (del_idx * 2)+1;
                }
                
            }

        }
        else
        {

            heapArr[index] = n;
            int tmp_index = index;

            while (heapArr[index / 2] <= n && (index / 2) > 0)
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

