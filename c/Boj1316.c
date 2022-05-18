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
    char checked[26];

    //printf("%d", strcmp('a', 'a'));
    for(int i=0; i<N; i++){
        scanf("%s", str);
        
        int len = strlen(str);
        int checkNum=0;

        for(int j=0; j<N; j++){
            
            for(int k=j+1; k<len; k++){
                if(str[j] - str[k] !=0){
                    //printf("%d", str[]);
                    if(check(checked, &str[j])>0){
                        printf("true");
                    }else{
                        checked[checkNum++] = str[j];
                        j = k;
                        break; 
                    }
                    
                }
                
                //printf("%d",str[j] - str[k]);
                //printf( "j : %d -> %d ,,, %d  %d\n", j, strcmp(&str[j], &str[k]), str[j], str[k] );  
            }

        }
        /*
        for(int j=0; j<len-1; j++){
            
            for(int k=j+1; k<len; k++){
                printf( "j : %d -> %d ,,, %d  %d\n", j, strcmp(&str[j], &str[k]), str[j], str[k] );  
            }

        }
        */
    }
    
    


    
    return 0;
}