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
   
    // int arr[N];
    //int* arr = malloc(sizeof(int)*N);
    int arr[10] = {12, 33, 30, 446, 8, 9, 878, 90, 435425, 1};
/*
    for (int i = 0; i < N; i++){
        scanf("%d", &arr[i]);
    }
*/

    for (int insert = 0; insert < N; insert++)
    {
//i=3 < insert 4
        //int* min = &arr[selection];
        for (int i = insert-1; i >=0; i--)
        {
            if(arr[i]> arr[insert]){
                printf("%d %d\n", i, insert);
                change(arr, &i, &insert);
                insert--;
                
            }
        }
        
        

    }

    for (int i = 0; i < N; i++){
        printf("%d\n", arr[i]);
    }

        return 0;
}