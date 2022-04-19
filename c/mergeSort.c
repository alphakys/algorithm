#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 1000000

void printArray(int *arr, int n) {
    int i;
    for (i = 0; i < n; i++) {

        printf("%d ", arr[i]);
    }
    printf("\n");
}

void mergeSort(int* arr, int left, int right, int* sorted){
    
    int mid = (right - left + 1) / 2;
    
    if (mid >= 1)
    {
        mid = left + mid;
       
        mergeSort(arr, left, mid - 1, sorted);
        mergeSort(arr, mid, right, sorted);  
        
    }
        
    int pointer = left;

    int leftPos = left; 
    int rightPos = right; 
    int midPos = left + ((right - left + 1) / 2);

    int m = left + ((right - left + 1) / 2);
    

    

    for(int i=0; i<right-left+1; i++)
    {
       
        if(leftPos>=m){
            sorted[pointer++] = arr[midPos++];
        }else if(midPos>rightPos){
            sorted[pointer++] = arr[leftPos++];
        }else{
  
            if(arr[leftPos] > arr[midPos]){
                sorted[pointer++] = arr[midPos++];
                
            }else{
                sorted[pointer++] = arr[leftPos++];
            
            }

        }
        
    }
    
    for(int i=left; i<=right; i++){
        arr[i] = sorted[i];
    }

}


int main(){

    int N;
    scanf("%d", &N);

    int* arr = malloc(sizeof(int)*N);

    for (int i = 0; i < N; i++){
        scanf("%d", &arr[i]);
    }

    int* sorted = malloc(sizeof(int)*(N));

    mergeSort(arr, 0, N-1, sorted);
    
    for (int i = 0; i < N; i++){
        printf("%d\n", arr[i]);
    }

    free(sorted);
    free(arr);

    return 0;
}

