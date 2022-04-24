#include <stdlib.h>
#include <stdio.h>

int main(){

    int N;

    char str[15];

    scanf("%d", &N);

    //fflush(stdin);
    getchar();
    // int x[10001];
    // int y[10001];

    int* x = malloc(4*N);//[10001];
    int* y = malloc(4*N);//[10001];

    for (int i = 0; i < N; i++)
    {
        
        fgets(str, 15, stdin);

        
            //x[i] = str[0];
        //y[i] = str[2];
    }

        for (int k = 0; k < 15; k++){

            if((int)str[k] ==32){
                break;
            }
            printf("%c", str[k]);
            
        }

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