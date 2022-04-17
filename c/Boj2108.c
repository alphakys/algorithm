#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

#define MAX_SIZE 4001


void change(int* arr, int* i, int* insert){

    int change = arr[*i];
    arr[*i] = arr[*insert];
    arr[*insert] = change;
}

void printArray(int *arr, int n) {
    int i;
    for (i = 0; i < n; i++) {

        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){

    int N;
    scanf("%d", &N);
   
    int positive[MAX_SIZE]= {0};
    int negative[MAX_SIZE]= {0};
    
    int sum = 0;

    for (int i = 0; i < N; i++)
    {
        int num;
        scanf("%d", &num);
        
        if(num>=0){
            positive[num]++;
        }else{
            negative[abs(num)]++;
        }
        
        sum+=num;
    }


//////////////////////////////////////////////

    int count = 0;
    int arrPointer = 0;
    int arr[8001] = {-0};

    printArray(arr, 10);
    return 0;
    ///////////////////////////////////////////

    int maxPosition = 0;
    int maxPositiveCount = 1;
    int maxNegativeCount = 1;

    int maxArr[8001];
    //memset(maxArr, -1, sizeof(int)*MAX_SIZE);
    int maxCount = 0;

    for (int i = -5; i < 6; i++)
    {   
        if(i<0){
            
            if(negative[abs(i)]>0){
                count++;
                arr[arrPointer++] = i;
                
                if(maxCount < negative[abs(i)]){
                    
                    memset(maxArr, -1, sizeof(int) * MAX_SIZE);

                    maxPosition = 0;
                    maxArr[maxPosition++] = i;

                }else if(maxCount == negative[abs(i)]){
                    maxArr[maxPosition++] = i;
                }
            }   
        }else{
            if(positive[i]>0){
                count++;
                arr[arrPointer++] = i;
            }
        }

    }




for(int i=0; i<20; i++){
        if(maxArr[i]==-1){
            printf("max : %d\n",maxArr[i-2]);
            break;
        }
    }

    printArray(arr, 10);

    printf("%d\n", (int)(round((double)round(sum/N))));
    printf("%d\n", arr[(count / 2)]);


    printf("%d\n", arr[count-1] - arr[0]);
   

    
    return 0;


}