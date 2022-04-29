#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

void printArray(int *arr, int n) {
    
    int i;
    for (i = 0; i < n; i++) {

        printf("%d ", arr[i]);
    }
    printf("\n");
}

int strToint(int start, int digit, char* str){

    int sum=0;

    int poww = (digit-start)-1;

    if((int)str[start] ==45){
        poww = poww-1;
        
        for (int j = start+1; j < digit; j++)
        {
        
            double n = (double)str[j] - (double)48;
            double powNum = pow((double)10,(double)(poww));

            sum += (int)(n*powNum);
            poww--;
        
        }
        sum = sum*-1;
                
    }else{

        for (int j = start; j < digit; j++)
        {
        
            double n = (double)str[j] - (double)48;
            double powNum = pow((double)10,(double)(poww));

            sum += (int)(n*powNum);
            poww--;
        
        }
    }

    return sum;
}


typedef struct string
{
    char character[51];
    char length;

} string;


int len(const char* ch){

    //int c = (int)ch;
    int length = 0;
    
    while(*ch){
        
        ch++;
        length++;
    }
    
    return length;

}


int main(){

    int N;
    scanf("%d", &N);

    string str[20000];
    
    for(int i=0; i<N; i++){
        
        scanf("%s", str[i].character);
        int len = strlen(str[i].character);

        printf("v : %d pointer : %p\n", len, len);
    }
    
    ;
    //if()
    

    /*
    
    

    for(int i=0; i<N; i++){
        
        printf("%d\n", strlen(str[i].character));
    }
    
    
    getchar();

    for (int j = 0; j < N; j++)
    {
        printf("%d %d\n", node[j].x, node[j].y);
    }
*/
    //free(sorted);
    //free(node);

    return 0;
}