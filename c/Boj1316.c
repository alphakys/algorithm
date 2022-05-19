#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void intArray(int *arr, int n) {
    int i;
    for (i = 0; i < n; i++) {

        printf("%d ", arr[i]);
    }
    printf("\n");
}

void charArray(char *arr, int n) {
    int i;
    for (i = 0; i < n; i++) {

        printf("%d ", arr[i]);
    }
    printf("\n");
}






int check(char* arr, char* val){

    for(int i=0; arr[i]!=0; i++){
        
        if(arr[i] == *val){
            return 1; 
        }
    }
    return 0;
}

int main(){

    int N;
    scanf("%d", &N);

    char str[101];

    int minus = 0;

    char *check = malloc(N);
    int checkNum = 0;
    for (int i = 0; i < N; i++)
    {
        scanf("%s", str);
        
        int len = strlen(str);

        for(int j=0; j<len; j++){
            //printf("out\n");
            for(int k=j+1; k<len; k++){
                //printf("j : %d k : %d  jval : %c  kval : %c\n", j,k, str[j], str[k]);
                if(str[j] - str[k] !=0){
                    
                    int flag = len - 1;
                    while (flag > k)
                    {
                        if(str[j] == str[flag--]){
                            //printf("true\n");
                            //minus++;
                            check[i]++;
                            break;
                        }
                    }
                    j = k;
                    
                }
            }
            
        }
    }
    
    //charArray(check, 5);
    int answer = N;
    for (int i = 0; i < N; i++)
    {   
        if(check[i]>0){
            answer--;
        }
    }
    printf("%d",answer);
    return 0;
}