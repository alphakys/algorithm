#include <stdio.h>
#include <stdlib.h>

void change(int* arr, int* i, int* insert){

    int change = arr[*i];
    arr[*i] = arr[*insert];
    arr[*insert] = change;
}


int main(){

    int N;
    scanf("%d", &N);
   
    int* arr = malloc(sizeof(int)*N);

    for (int i = 0; i < N; i++){
        scanf("%d", &arr[i]);
    }


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

    for (int i = 0; i < N; i++){
        printf("%d\n", arr[i]);
    }
    free(arr);
    return 0;
}