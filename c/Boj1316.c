#include <stdio.h>
#include <string.h>

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
// printf("%d", strcmp('a', 'a'));
    
    for (int i = 0; i < N; i++)
    {
        two:scanf("%s", str);
        
        int len = strlen(str);

         for(int j=0; j<len; j++){
            //printf("j : %d \n", j);
            for(int k=j+1; k<len; k++){
                
                if(str[j] - str[k] !=0){
                    
                    int flag = len - 1;
                    while (flag > k)
                    {
                        if(str[j] == str[flag--]){
                            //printf("true\n");
                            minus++;
                            break;
                        }
                    }
                    j = k;
                    goto two;
                }
            }
            
        }
    }
    
    //charArray(checked, 5);
    printf("%d", N-minus);

    return 0;
}