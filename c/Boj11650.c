#include <stdlib.h>
#include <stdio.h>
#include <math.h>
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


void printArray(int *arr, int n) {
    
    int i;
    for (i = 0; i < n; i++) {

        printf("%d ", arr[i]);
    }
    printf("\n");
}

int strToint(int start, int digit, char* str){

    int sum=0;

    int poww = (digit-start)-1;

    if((int)str[start] ==45){
        poww = poww-1;
        
        for (int j = start+1; j < digit; j++)
        {
        
            double n = (double)str[j] - (double)48;
            double powNum = pow((double)10,(double)(poww));

            sum += (int)(n*powNum);
            poww--;
        
        }
        sum = sum*-1;
                
    }else{

        for (int j = start; j < digit; j++)
        {
        
            double n = (double)str[j] - (double)48;
            double powNum = pow((double)10,(double)(poww));

            sum += (int)(n*powNum);
            poww--;
        
        }
    }

    

    return sum;
    //printf("sum : %d\n", sum);
}


int main(){

    int N;

    char str[16];

    scanf("%d", &N);

    //fflush(stdin);
    getchar();

    int* x = malloc(4*N);//[10001];
    int* y = malloc(4*N);//[10001];

    int positive[100001]= {0};
    int negative[100001]= {0};

    for (int i = 0; i < N; i++)
    {
        
        fgets(str, 16, stdin);
        int start = 0;
        
        for (int k = 0; k < 15; k++){
               
            if((int)str[k] ==32){
                x[i] = strToint(start, k, str);
                
                if(strToint(start, k, str)>=0){
                    positive[strToint(start, k, str)]++;
                }else{
                    negative[strToint(start, k, str)*-1]++;
                }

                start = k+1;
            }else if((int)str[k] ==10){
                y[i] = strToint(start, k, str);
                
                break;
            }

        }


    }
    
    int* sorted = malloc(sizeof(int)*(N));
    //printArray(negative, 10);
    //printArray(positive, 10);

    mergeSort(x, 0, N, sorted);





    memset(sorted, 0, sizeof(int)*(N));
    mergeSort(y, 0, N, sorted);
    
    for (int j = 0; j < N; j++)
    {
        printf("%d %d\n", x[j], y[j]);
    }
    
    free(sorted);
    free(x);
    free(y);
    
    return 0;
}