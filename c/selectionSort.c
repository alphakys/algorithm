#include <stdio.h>
#include <stdlib.h>

void change(int* arr, int* selection, int* min){

    int change = arr[*selection];
    arr[*selection] = *min;
    *min = change;
}


int main(){

    int N;
    scanf("%d", &N);
   
    // int arr[N];
    int* arr = malloc(sizeof(int)*N);
    

    for (int i = 0; i < N; i++){
        scanf("%d", &arr[i]);
    }


    for (int selection = 0; selection < N; selection++)
    {

        int* min = &arr[selection];

        for (int i = selection; i < N; i++)
        {
            if(*min> arr[i]){
                min = &arr[i];
            }
        }
        
        change(arr, &selection, min);

    }

    for (int i = 0; i < N; i++){
        printf("%d\n", arr[i]);
    }
free(arr);
        return 0;
}