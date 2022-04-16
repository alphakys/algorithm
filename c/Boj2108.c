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
    //int positiveCount[MAX_SIZE]= {0};
    //int negativeCount[MAX_SIZE]= {0};

    int positive[MAX_SIZE]= {0};
    int negative[MAX_SIZE]= {0};
    

    int sum = 0;
    int maxNum;

    for (int i = 0; i < N; i++)
    {
        //int num;
        scanf("%d", &arr[i]);
        
        if(arr[i]>=0){
            positive[arr[i]]++;
        }else{
            negative[abs(arr[i])]++;
        }
        
        sum+=arr[i];
    }

    //printArray(negative, 11);


    int negativeCount = 0;
    int positiveCount = 0;

    for (int i = 0; i < MAX_SIZE; i++)
    {  
        if(negative[i]>0){
                    
            negativeCount++; //printf("i  %d  count %d\n",i, count);
        }

        if(positive[i]>0){
            positiveCount++;
        }
    }

    printf("%d", ((positiveCount+negativeCount)/2)+1);
    
    
    
    free(arr);
    return 0;


    int maxPosition = 0;
    int maxPositiveCount = 1;
    int maxNegativeCount = 1;

    int maxArr[MAX_SIZE];
    memset(maxArr, -1, sizeof(int)*MAX_SIZE);

    //최빈값이 하나 이상 있을 때와 하나도 없을 때 두가지 경우의 수 생각해야함
    
    for (int i = 0; i < MAX_SIZE; i++)
    {

        if (maxPositiveCount == positive[i])
        {
            // maxCount = positive[i];
            maxArr[maxPosition++] = i;
        }
        else if (maxPositiveCount < positive[i])
        {

            memset(maxArr, -1, sizeof(int) * MAX_SIZE);

            maxPositiveCount = positive[i];
            maxPosition = 0;
            maxArr[maxPosition++] = i;
            
        }



        if (maxNegativeCount == negative[i])
        {
            // maxNegativeCount = negative[i];
            maxArr[maxPosition++] = i;
        }
        else if (maxNegativeCount < negative[i])
        {

            memset(maxArr, -1, sizeof(int) * MAX_SIZE);

            maxNegativeCount = negative[i];
            maxPosition = 0;
            maxArr[maxPosition++] = i;
            
        }



    }

    for(int i=0; i<20; i++){
        if(maxArr[i]==-1){
            printf("max : %d\n",maxArr[i-2]);
            break;
        }
    }


    printArray(maxArr, 10);
    
    
    
    
    
    
    
    
    
    int search = 0;

    for (int i = 0; i < MAX_SIZE; i++)
    {
        if(search<positive[i]){
            search = positive[i];
        }
    }

    search = 0;






    return 0;

    for (int i = 0; i < MAX_SIZE; i++)
    {

        if (maxCount == positive[i])
        {
            // maxCount = positive[i];
            maxArr[maxPosition++] = i;
        }
        else if (maxCount < positive[i])
        {

            if (memset(maxArr, -1, sizeof(int) * MAX_SIZE) == NULL)
            {
                exit(1);
            }
            else
            {

                maxCount = positive[i];
                maxPosition = 0;
                maxArr[maxPosition++] = i;
            }
        }
    }

    for(int i=0; i<20; i++){
        if(maxArr[i]==-1){
            printf("max : %d\n",maxArr[i-2]);
            break;
        }
    }


    printArray(maxArr, 10);












    /*

    for (int i = -4000; i < 4001; i++)
    {   
        if(i<0){
            
            if(negative[abs(i)]>0 && center>count){
                    
                count++; //printf("i  %d  count %d\n",i, count);
            }else if(negative[abs(i)]>0 && center==count){
                printf("minus -%d  center  %d  count %d",count, center, count);
                break;
            }

        }else{
            
            if(positive[i]>0 && center>count){
                    
                count++; //printf("i  %d  count %d\n",i, count);
            }else if(positive[i]>0 && center==count){
                printf("minus -%d  center  %d  count %d",count, center, count);
                break;
            }
        }
        
    }
*/
//count 값이 중앙값

    free(arr);
    //free(maxArr);
    return 0;
    /*
    int maxPosition = 0;
    int maxCount = 1;
    //int* maxArr[MAX_SIZE]= {-1};
    int maxArr[MAX_SIZE];
    memset(maxArr, -1, sizeof(int)*MAX_SIZE);

    //최빈값이 하나 이상 있을 때와 하나도 없을 때 두가지 경우의 수 생각해야함
    int search = 0;

    for (int i = 0; i < MAX_SIZE; i++)
    {
        if(search<positive[i]){
            search = positive[i];
        }
    }

    search = 0;






    return 0;

    for (int i = 0; i < MAX_SIZE; i++)
    {

        if (maxCount == positive[i])
        {
            // maxCount = positive[i];
            maxArr[maxPosition++] = i;
        }
        else if (maxCount < positive[i])
        {

            if (memset(maxArr, -1, sizeof(int) * MAX_SIZE) == NULL)
            {
                exit(1);
            }
            else
            {

                maxCount = positive[i];
                maxPosition = 0;
                maxArr[maxPosition++] = i;
            }
        }
    }

    for(int i=0; i<20; i++){
        if(maxArr[i]==-1){
            printf("max : %d\n",maxArr[i-2]);
            break;
        }
    }


    printArray(maxArr, 10);

    printf("avg : %d\n", (int)(round((double)round(sum/N))));

free(maxArr);
    return 0;


*/

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
        free(arr);

        return 0;*/
}