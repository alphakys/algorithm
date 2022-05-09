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
        return --fal;
    }else if(strlen(str1) < strlen(str2)){
        return ++fal;
    }else{
        
        while (str1[i] || str2[i])
        {
            if (str1[i] > str2[i])
            {
                fal--;
                break;
            }else if(str1[i] == str2[i]){
                i++;
                
            }
            else
            {
                fal++;
                break;
            }
        }

        return fal;
    }

    
}

void mergeSort(char* arr, int left, int right, char* sorted){
    
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

            int flag = strcompare(&arr[leftPos], &arr[midPos]);
        
            if (flag > 0)
            {
                sorted[pointer++] = arr[leftPos++];
                printf("up %p\n", arr[leftPos++] );
            }
            else{
                sorted[pointer++] = arr[midPos++];
                printf("down %p\n", arr[leftPos++] );
            }
        }
        
    }
    
    for(int i=left; i<=right; i++){
        arr[i] = sorted[i];
        
    }
    
}

int main(){

//alphabet 26

    int N;
    scanf("%d", &N);

    char str[51];

    char arr[20000][51];
    char* dest[20000];
    
    for (int i = 0; i < N; i++)
    {

        scanf("%s", str);
        int j = 0;
        char *ptr = str;

        while (*ptr)
        {   
            arr[i][j++] = *(ptr++);
        }
        dest[i] = &arr[i][0];
        
    }
    
    char* sorted = malloc(sizeof(char)*(N));

    mergeSort(*dest, 0, N-1, sorted);

    printf("----------------------------\n");

    for (int i = 0; i < N; i++)
    {

        for (int j = 0; dest[i][j] > 0; j++)
        {
            printf("%c", dest[i][j]);
        }
        printf("\n");
    }


/*
    int i = 0;
    while (i<N)
    {
        printf("order : %d  sorted : %d\n", order[i], sorted[i]);
        i++;
    }
*/
    free(sorted);


/* 스트링 출력



    //char *p = sortPtr;
    
    


    for (int i = 0; i < 5; i++){

        int fal = strcompare(&arr[i][0], &arr[i+1][0]);
        printf("asdfsfds%d", fal);
        break;
    }
    
    
*/
     
    return 0;
}