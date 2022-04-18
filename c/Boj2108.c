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

    //printf("dd %f\n", round(divide));
    double a = 1.1;
    double b = 5.6;

    printf("%f", round(a+b));

    printf("%d\n", (int)(round((double)round(sum / N))));

    printf("%d\n", arr[(count / 2)]);

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
    
    
    //printArray(arr,10);
    //printArray(maxArr,10);
    
    return 0;


}