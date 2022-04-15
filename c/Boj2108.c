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
   
    int* arr = malloc(sizeof(int)*N);
    int positive[MAX_SIZE]= {0};
    int negative[MAX_SIZE]= {0};

    int sum = 0;

    for (int i = 0; i < N; i++){
        //int num;
        scanf("%d", &arr[i]);
        
        if(arr[i]>=0){
            positive[arr[i]]++;
        }else{
            negative[arr[i]]++;
        }
        
        sum+=arr[i];
    }

    int maxPosition = 0;
    int maxCount = 1;
    //int* maxArr[MAX_SIZE]= {-1};
    int maxArr[MAX_SIZE]; 
    memset(maxArr, -1, sizeof(int)*MAX_SIZE);

//최빈값이 하나 이상 있을 때와 하나도 없을 때 두가지 경우의 수 생각해야함

    for(int i=0; i<MAX_SIZE; i++){
        
        if(maxCount==positive[i]){
            //maxCount = positive[i];
            maxArr[maxPosition++] = i;

        }else if(maxCount<positive[i]){
           
            if(memset(maxArr, -1, sizeof(int)*MAX_SIZE) ==NULL){
                exit(1);
            }else{
                maxCount = positive[i];
                maxPosition = 0;
                maxArr[maxPosition++] = i;
                

            }
            
        }
    }

    for(int i=0; i<20; i++){
        if(maxArr[i]==-1){
            printf("max값은 : %d\n",maxArr[i-2]);
            break;
        }
    }


    printArray(maxArr, 10);

    printf("answer : %d\n", (int)(round((double)sum/N)));
    





    //printf("avg : %d", round(sum));


    return 0;




















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