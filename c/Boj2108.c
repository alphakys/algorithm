#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_SIZE 4001


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
   
    int positive[MAX_SIZE]= {0};
    int negative[MAX_SIZE]= {0};
    
    int sum = 0;

    int array[500000];

    for (int i = 0; i < N; i++)
    {
        int num;
        scanf("%d", &num);
        array[i] = num;

        if (num >= 0)
        {
            positive[num]++;
        }
        else
        {
            negative[abs(num)]++;
        }

        sum+=num;
    }

    int* sorted = malloc(sizeof(int)*(N));

    mergeSort(array, 0, N-1, sorted);

    //printf("%d   %d", array[(N/2)], (N/2));

    //////////////////////////////////////////////

    int count = 0;
    int arr[8001];
    memset(arr, 0, sizeof(int)*8001);
 
///////////////////////////////////////////

    int maxPosition = 0;
    int maxArr[8001];
    //memset(maxArr, -1, sizeof(int)*MAX_SIZE);
    int maxCount = 0;

    for (int i = -4000; i < 4001; i++)
    {   
        if(i<0){
            
            if(negative[abs(i)]>0){
                
                arr[count++] = i;
                
                if(maxCount < negative[abs(i)]){
                    
                    for(int k=0; k<8002; k++){
                        maxArr[k] = 4001;
                    }
                    maxCount = negative[abs(i)];
                    maxPosition = 0;
                    maxArr[maxPosition++] = i;

                }else if(maxCount == negative[abs(i)]){
                    maxArr[maxPosition++] = i;
                }
            }   
        }else{
            if(positive[i]>0){

                arr[count++] = i;

                if(maxCount < positive[i]){
                    
                    for(int k=0; k<8002; k++){
                        maxArr[k] = 4001;
                    }

                    maxCount = positive[i];
                    maxPosition = 0;
                    maxArr[maxPosition++] = i;

                }else if(maxCount == positive[i]){
                    maxArr[maxPosition++] = i;
                }

            }
        }

    }

    double divide = (double)sum / (double)N;
    int r = round(divide);

    printf("%d\n", (int)floor(r));  
    
    printf("%d\n", array[(N/2)]);
    
    //printf("%d\n", arr[(count / 2)]);

     for(int i=0; i<8002; i++){

        if(maxArr[i]==4001){

            if(i<2){
                printf("%d\n", maxArr[i-1]);
                    break;
            }else{
                printf("%d\n",maxArr[1]);
                    break;
            }

            
        }

    }
    
    printf("%d\n", arr[count-1] - arr[0]);
    

    return 0;
}