#include <stdlib.h>
#include <stdio.h>
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
    int flag = 0;

    if(strlen(str1) > strlen(str2)){
        return --flag;
    }else if(strlen(str1) < strlen(str2)){
        return ++flag;
    }else{
        
        while (str1[i] || str2[i])
        {
            if (str1[i] > str2[i])
            {
                flag--;
                break;
            }else if(str1[i] == str2[i]){
                i++;
                
            }
            else
            {
                flag++;
                break;
            }
        }
        if(flag==0){
            str2[0] = '0';
        }
        return flag;
    }

    
}

void mergeSort(char** arr, int left, int right, char** sorted){

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
        
            int flag = strcompare(arr[leftPos], arr[midPos]);
        
            if (flag > 0)
            {   
                sorted[pointer++] = arr[leftPos++];
            }
            else
            {
                sorted[pointer++] = arr[midPos++];
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

    char str[51];

    char arr[20000][51];

    char** dest = (char **)malloc(sizeof(char*)*N);

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
    
    char** sorted = (char **)malloc(sizeof(char*)*N);

    mergeSort(dest, 0, N-1, sorted);

    //printf("----------------------------\n");

    for (int i = 0; i < N; i++)
    {
        char *p = dest[i];

        if(*p =='0'){
            continue;
        }
        while(*p){
            
            printf("%c", *p);
            p++;
        }
        printf("\n");
        
    }

    free(dest);
    free(sorted);
  
    return 0;
}