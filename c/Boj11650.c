#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main(){

    int N;

    char str[15];

    scanf("%d", &N);

    //fflush(stdin);
    getchar();

    int* x = malloc(4*N);//[10001];
    int* y = malloc(4*N);//[10001];

    for (int i = 0; i < N; i++)
    {
        
        fgets(str, 15, stdin);

    }

        int digit = 0;
        int num = 0;

        for (int k = 0; k < 15; k++){

            if((int)str[k] ==32){
                break;
            }

            digit++;
        }

        double n = (double)str[0]-(double)48;
        double powNum = pow((double)10,(double)(digit-1));
        
        //printf( "%lf  %lf  %d ", n, powNum, (int)(n*powNum));

        int sum=0;

        //digit = digit-1;
        int poww = digit-1;

        for (int j = 0; j < digit; j++)
        {
            double n = (double)str[j] - (double)48;
            double powNum = pow((double)10,(double)(poww));

            sum += (int)(n*powNum);
            poww--;
            printf("%lf  %lf  %d  %d\n", n, powNum, sum, j, poww);
            //break;
        }

        printf("sum : %d\n", sum);

        //printf("%d", digit);
        free(x);
        free(y);
        return 0;

        for (int j = 0; j < N; j++)
        {
            printf("x: %s y: %s", x[j], y[j]);
    }

    /*
    int* sorted = malloc(sizeof(int)*(strlen(b)));

    mergeSort(arr, 0, strlen(b)-1, sorted);

    for (int i = strlen(b)-1; i >= 0; i--){
        printf("%c", arr[i]);
    }

    free(sorted);
    */    
    return 0;
}