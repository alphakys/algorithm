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
   
    int* arr = malloc(sizeof(int)*N);

    for (int i = 0; i < N; i++){
        scanf("%d", &arr[i]);
    }


    for (int last = N; last > 0; last--)
    {

        for (int bubble = 0; bubble < N-1; bubble++)
        {
            int pointer = bubble+1;

            if(arr[bubble]>arr[pointer]){
                change(arr, &bubble, &pointer);
            }

        }
 
    }
    
    for (int i = 0; i < N; i++){
        printf("%d\n", arr[i]);
    }
free(arr);
    return 0;
}