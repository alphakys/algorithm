#include <stdio.h>
#include <stdlib.h>

void printArray(int *arr, int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void divide(int* arr, int left, int right, int* sorted){
    
    int mid = (right - left + 1) / 2;
    
    if (mid > 1)
    {
        mid = left + mid;
        //printf("left : %d, right : %d mid : %d\n", left, right, mid);
        //return 0;
        divide(arr, left, mid - 1, sorted); // 0,3 (0,1) (2,3)
        divide(arr, mid, right, sorted);   // 4,7 --> mid=2 ==> (4,1)(2,7)
        
    }
        //mergeArr(arr, sorted, left, right, mid);
    int pointer = left;

    int leftPos = left; 
    int rightPos = right; 
    int midPos = left + ((right - left + 1) / 2);

    int m = left + ((right - left + 1) / 2);
    

    printf("left : %d, midPos : %d, right : %d, mid : %d\n", leftPos, midPos, rightPos, mid);

    for(int i=0; i<right-left+1; i++)
    {
        printf("left : %d, midPos : %d, right : %d, m : %d\n", leftPos, midPos, rightPos, m);
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
        
        printf("sorted : ");printArray(sorted, 8);
    }
    
    for(int i=left; i<=right; i++){
        arr[i] = sorted[i];
    }
    printf("arr : ");printArray(arr, 8);
 
}

void mergeArr(int* arr, int* sorted, int left, int right, int mid){

    int pointer = 0;
   // int right = 0;
   // int left = 0;

    for(int i=0; i<=right; i++)
    {
        if(left>mid-1){
            
            sorted[pointer++] = arr[right++];
        }else if(right>mid){
            sorted[pointer++] = arr[left++];
        }else{
  
            if(arr[left] > arr[right]){
                sorted[pointer++] = arr[right++];
                
            }else{
                sorted[pointer++] = arr[left++];
            
            }

        }

        //printf("left : %d right : %d\n", left, j);
    }
}



int main(){

    //int N = 8;
    //int* sorted = malloc(sizeof(int)*(N));
/*
    int arr1[4] = {10, 12, 20, 21};
    int arr2[4] = {13, 15, 22, 25};    

    

    int pointer = 0;
    int right = 0;
    int left = 0;

    for(int i=0; i<8; i++)
    {
        if(left>3){
            printf("left : %d, right : %d, arr : %d\n", left, right, arr2[right]);
            sorted[pointer++] = arr2[right++];
        }else if(right>3){
            sorted[pointer++] = arr1[left++];
        }else{
  
            if(arr1[left] > arr2[right]){
                sorted[pointer++] = arr2[right++];
                
            }else{
                sorted[pointer++] = arr1[left++];
            
            }

        }

        //printf("left : %d right : %d\n", left, j);
    }
    


    for (int i = 0; i < N; i++){
        printf("%d\n", sorted[i]);
    }
    free(sorted);
    return 0;
*/


    /*scanf("%d", &N);

    int* arr = malloc(sizeof(int)*N);

    for (int i = 0; i < N; i++){
        scanf("%d", &arr[i]);
    }
*/
    int arr[8] = {21, 10, 12, 20, 25, 13, 15, 22};

    int* sorted = malloc(sizeof(int)*(8));

    divide(arr, 0, 7, sorted);
    
    for (int i = 0; i < 8; i++){
        printf("%d\n", sorted[i]);
    }

    free(sorted);
/*
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
*/
    return 0;
}