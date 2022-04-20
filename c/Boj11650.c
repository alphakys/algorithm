#include <stdlib.h>
#include <readline/readline.h>

int main(){

    int N;
    char *str;

    scanf("%d", &N);

    for (int i = 0; i < N; i++){
        str = readLine();
    }

    if(str){
        printf("%s", str);
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