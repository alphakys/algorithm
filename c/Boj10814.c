#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int strToint(int start, char* str){

    int digit=0;
    
    while(!(*str ==32)){
        
        str++;
        digit++;
    }
   
    //printf("digit %d\n", digit);
    
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
    printf("%d", sum);
    return sum;
}



int compare(char* str1, char* str2){

}


int main(){

    int N;
    scanf("%d", &N);

    char str[105];

    char** list = (char **)malloc(sizeof(char*)*100000);

    for(int i=0; i<100000; i++){
        list[i] = (char *)malloc(105);
    }

    for(int i=0; i<N; i++){
        scanf("%s", str);

        char* ch = str;

        int k=0;
        while((*ch)){
            list[i][k] = *ch;
            //printf("%c", list[i][k]);
            k++;
            ch++;
        }
    }

    //qsort(list[][105],N, sizeof(list[0]),compare);

char s[9] = "1 qw";
//int z = 10 + strToint(0, s);
  printf("%d\n", strToint(0, s));



 /*
 for(int i=0; i<10; i++){
        
       
}
*/
//printf("%d", z);
/*
    for(int i=0; i<10; i++){
        for(int j=0; j<10; j++){
            printf("%c", list[i][j]);
        }
        printf("\n");
    }
*/


    //char** sorted = (char **)malloc(sizeof(char*)*N);

    //mergeSort(dest, 0, N-1, sorted);

    //printf("----------------------------\n");


  
    return 0;
}