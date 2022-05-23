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

void strToint(char* str, int* arr){

    int index = 0;
    int start = 0;
    int i = 0;
    int sum = 0;

    int len = strlen(str);

    while (index <= len)
    {

        if (str[index] == 32 || str[index] == 0)
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

                arr[i++] = sum;

                sum = 0;

                start = index + 1;
                index++;
                //printf(" start : %d  index  %d\n", start, index);
        }
        else
        {
            index++;
        }

        
    }


}

int main(){

    int N;
    int M;
    scanf("%d %d", &N, &M);
    getchar();

    char str[(N*2) +2];
    fgets(str, N*2, stdin);

    int arr[N];
    strToint(str, arr);

    int max = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            int k = N - 1;
            while (j<k)
            {
                int sum = arr[i] + arr[j] + arr[k];
                if (sum <= M)
                {
                    if(max<sum){
                        max = sum;
                    }
                }
                k--;
            }
            
        }
    }
    printf("%d", max);
    return 0;
}