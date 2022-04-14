#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10001

int main(){

    int N;
    scanf("%d", &N);

    int arr[MAX_SIZE] = {0};

    //short *arr = malloc(sizeof(short) * N);

    for (int i = 0; i < N; i++){
        int num;
        scanf("%d", &num);

        arr[num]++;
    }

    for(int i = 1; i < 10001; i++){
        
        if(arr[i]>0){
            for (int j = 0; j < arr[i]; j++)
            {
                printf("%d\n", i);
            }
        }
        
        
    }


    return 0;
}

