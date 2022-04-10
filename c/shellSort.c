#include <stdio.h>
#include <stdlib.h>

void change(int* arr, int* next, int* pointer){

    int change = arr[*next];
    arr[*next] = arr[*pointer];
    arr[*pointer] = change;
}


int main(){

    int N;
    scanf("%d", &N);
    //int arr[N] = {10, 8, 6, 20, 4, 3, 22, 1, 0, 15, 16};
    //             0  1  2   3  4  5  6   7  8  9   10
    
    int* arr = malloc(sizeof(int)*N);

    for (int i = 0; i < N; i++){
        scanf("%d", &arr[i]);
    }
    
    int gap = N / 2;

    while(gap>0){
        
        if(gap%2==0){
            gap += 1;
        }
        //printf("gap : %d\n", gap);

        if(gap==1)
        {

            for (int insert = 1; insert < N; insert++)
            {

                for (int i = insert-1; i >=0; i--)
                {
                    if(arr[i]> arr[insert]){
                        
                        change(arr, &i, &insert);
                        insert--;
                        
                    }
                }
                
            }
            break;
        }

        for (int j = 0; j < gap; j++)
        {

            for (int i = j; i + gap < N; i = i + gap)
            {
                int pointer = i + gap;
                if (arr[i] > arr[pointer])
                {
                    change(arr, &i, &pointer);
                }
            }
        }

        gap = gap / 2;

    }

    for (int i = 0; i < N; i++){
        printf("%d\n", arr[i]);
    }
free(arr);
    return 0;
}