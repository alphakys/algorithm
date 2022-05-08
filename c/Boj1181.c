#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

int len(const char* ch){

    //int c = (int)ch;
    int length = 0;
    
    while(*ch){
        
        ch++;
        length++;
    }
    
    return length;

}

int strcompare(char* str1, char* str2){

    int i = 0;
    int fal = 0;

    if(strlen(str1) > strlen(str2)){
        return ++fal;
    }else if(strlen(str1) < strlen(str2)){
        return --fal;
    }else{
        
        while (str1[i] || str2[i])
        {
            if (str1[i] > str2[i])
            {
                fal++;
                break;
            }else if(str1[i] == str2[i]){
                i++;
                
            }
            else
            {
                fal--;
                break;
            }
        }

        return fal;
    }

    
}

void mergeSort(char arr[][51], int left, int right, char* sorted){
    
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
            sorted[pointer++] = arr[midPos++][0];
        }else if(midPos>rightPos){
            sorted[pointer++] = arr[leftPos++][0];
        }else{

            int flag = strcompare(&arr[leftPos][0], &arr[midPos][0]);
            printf("%c, %c, %d\n", arr[leftPos][0], arr[midPos][0], flag);
            if (flag > 0)
            {
                sorted[pointer++] = arr[leftPos++][0];
            }
            else{
                sorted[pointer++] = arr[midPos++][0];
            }
        }
        
    }
    
    for(int i=left; i<=right; i++){
        arr[i][0] = sorted[i];
    }

}

int main(){

//alphabet 26

    int N;
    scanf("%d", &N);

    char str[51];

    char arr[20000][51];

    for (int i = 0; i < N; i++)
    {

        scanf("%s", str);
        int j = 0;
        char *ptr = str;
        while (*ptr)
        {
            arr[i][j++] = *(ptr++);
        }

    }
    
    char* sorted = malloc(sizeof(char)*(N));

    mergeSort(arr, 0, N-1, sorted);

    printf("----------------------------\n");

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < 50; j++)
        {
            printf("%c", arr[i][j]);
        }
        printf("\n");
    }


for (int i = 0; i < 5; i++){

        int fal = strcompare(&arr[i][0], &arr[i+1][0]);
        printf("asdfsfds%d", fal);
        break;
    }
/* 스트링 출력


    
    
*/
     
    return 0;
}