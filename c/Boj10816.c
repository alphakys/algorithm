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


int positive[10000001];
int negative[10000001];

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

    int i = 0;
    char* ptr = strtok(str," ");

    
    while (str[i] != '\0')
    {
        if(str[i]==' '){
            atoi(str);
        }
    }

    strToint(str, positive, negative, 0);

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
    
    str1[str_i] = '\n';
              
    strToint(str1, positive, negative, 1);

    //printArray(positive, 10);
    //printArray(negative, 10);

    return 0;
}
