#include <stdio.h>
#include <stdlib.h>
#include <string.h>


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

    //int N[100000000];
    int arr[11] = {-1};
    char b[11];

    scanf("%s", &b);
    //printf("%d",strlen(b));

    for (int i = 0; i < strlen(b); i++){
        
        arr[i] = (int)b[i];
    }

    int* sorted = malloc(sizeof(int)*(strlen(b)));

    mergeSort(arr, 0, strlen(b)-1, sorted);

    for (int i = strlen(b)-1; i >= 0; i--){
        printf("%c", arr[i]);
    }

    free(sorted);
        
    return 0;
}