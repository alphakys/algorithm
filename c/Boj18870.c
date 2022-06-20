#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

#define MAX_SIZE 11

void strToint(char* str, int* arr){

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
            //printf("index : %d  start : %d  digit : %d  poww : %d\n", index, start, digit, poww);

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
                //printf("sum : %d", sum);
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

    //return sum;
}

#define null 1000000001;
/*
int compare(const void *a, const void *b){
    int n1 = *(int *)a;
    int n2 = *(int *)b;
    //printf("%d %d", n1, n2);
    if (n1 > n2)
    {
        return 1;
    }
    else if (n1 < n2)
    {
        return -1;
    }else{
        *(int *)b = 1000000001;
        return -1;
    }
}
*/

int compare(const void *a, const void *b){
    int n1 = *(int *)a;
    int n2 = *(int *)b;
    //printf("%d %d", n1, n2);
    if (n1 >= n2)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

typedef struct link {
    int val;
    int original_index;

}link;


int arr[1000000];
int dest[1000000];
char str[12000001];

int main()
{

    int N;
    scanf("%d", &N);

    getchar();

    int size =(N * MAX_SIZE)+N;
    
    memset(str, 0, 12000001);

    fgets(str, size, stdin);

    strToint(str, arr);
    memcpy(dest, arr, 1000000);

    qsort(dest, N, sizeof(dest[0]), compare);
    
    for (int i = 0; i < N; i++)
    {
        //printf("%d\n", dest[i]);
        
        for (int j = 0; j < N; j++){

            if(dest[j] == 1000000001){
                break;
            }
            if( arr[i] == dest[j] ){
                printf("%d", j);
            }
        }
        if(i!=N-1){
            printf(" ");
        }
        
    }
    //free(str);
    return 0;
}