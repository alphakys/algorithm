#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void printArray(int *arr, int n) {
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

void countNumber(char* str, int* positive, int* negative, char delim){
    
    int index = 0;
    int s_flag = 0;
    char s[10];

    while (str[index] != '\0')
    {
        if ( str[index] == delim )
        {
            if(atoi(s)>=0){
                positive[atoi(s)]++;
            }else{
                negative[atoi(s)*-1]++;
            }
            
            s_flag = 0;
            
            memset(s,0,10);
            index++;
        }
        
        s[s_flag++] = str[index++];
        
    }
    if(atoi(s)>=0){
        positive[atoi(s)]++;
    }else{
        negative[atoi(s)*-1]++;
    }
    
}


void printNumber(char* str, int* positive, int* negative, char delim){
    
    int index = 0;
    int s_flag = 0;
    char s[10];

    while (str[index] != '\0')
    {
        if ( str[index] == delim )
        {
            if(atoi(s)>=0){
                printf("%d ", positive[atoi(s)]);
                
            }else{
                printf("%d ", negative[atoi(s)*-1]);
            }
            
            s_flag = 0;
            
            memset(s,0,10);
            index++;
        }
        
        s[s_flag++] = str[index++];
        
    }

    if(atoi(s)>=0){
        printf("%d", positive[atoi(s)]);
        
    }else{
        printf("%d", negative[atoi(s)*-1]);
    }
    
}

int positive[10000001] ;
int negative[10000001] ;

int main()
{

    int N;
    
    scanf("%d", &N);
    getchar();

    char s;
    char str[N*9+(N+1)];
    int str_i = 0;
    while ((s = getchar()) != '\n')
    {
        str[str_i++] = s;
    }
    
    str[str_i] = '\0';

    countNumber(str, positive, negative, ' ');
    
    //printArray(positive, 10);
    //printArray(negative, 11);

    int M;

    scanf("%d", &M);
    getchar();

    char s1;
    char str1[M*9+(M+1)];
    str_i = 0;
    
    while ((s1 = getchar()) != '\n')
    {
        str1[str_i++] = s1;
        
    }
    
    str1[str_i] = '\0';
    
    printNumber(str1, positive, negative, ' ');

    return 0;
}
