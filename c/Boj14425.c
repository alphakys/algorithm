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


void strToint(char* str, int* arr, int* arr1, int method){

    int index = 0;
    int start = 0;
    int i = 0;
    int sum = 0;
    while (str[index] !=0)
    {

        if (str[index] == 32 || str[index] == 10)
        {
            int digit = index-start;
            int poww = digit- 1;
            
            if ((int)str[start] == 45)
            {
                poww = poww - 1;

                for (int j = start + 1; j < start+digit; j++)
                {

                    double n = (double)str[j] - (double)48;
                    double powNum = pow((double)10, (double)(poww));

                    sum += (int)(n * powNum);
                    poww--;
                }
                sum = sum * -1;
                   
                }
                else
                {

                    for (int j = start; j < start+digit; j++)
                    {
                    
                        double n = (double)str[j] - (double)48;
                        double powNum = pow((double)10,(double)(poww));

                        sum += (int)(n*powNum);
                        poww--;
                    
                    }

                }

                if(method==0){
                    if (sum >= 0)
                    {
                        arr[sum]++;
                    }
                    else
                    {
                        arr1[sum*-1]++;
                    }
                }else{

                    if (sum >= 0)
                    {
                        if(arr[sum]==1){
                            printf("1");
                        }
                        else
                        {
                            printf("0");
                        }
                    }
                    else
                    {
                        if(arr1[sum*-1]==1){
                            printf("1");
                        }
                        else
                        {
                            printf("0");
                        }
                    }
                    printf(" ");
                }

                sum = 0;

                start = index + 1;
                index++;
                
        }
        else
        {
            index++;
        }

    }
}

int positive[10000001];
int negative[10000001];

int main()
{

    int N,M;
    
    scanf("%d %d", &N, &M);
    //getchar();

    char s[501];

    for (int i = 0; i < N; i++)
    {
        scanf("%s", s);
    }






    while ((s = getchar()) != '\n')
    {
        str[str_i++] = s;
        
    }
    
    str[str_i] = '\n';
              
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
