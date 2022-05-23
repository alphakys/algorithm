#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*
2 5 8

0*********
1* ** ** *
2*********
3***   ***
4* *   * *
5***   ***
6*********
7* ** ** *
8*********
*/


/*
2 5 8

*********
* ** ** *
*********
***   ***
* *   * *
***   ***
*********
* ** ** *
*********

*/

char* star(int N){

    char* str = malloc(N+1);

    for (int i = 0; i < N + 1; i++)
    {
        str[i] = malloc(N + 1);
    }

    char blank[2] = " ";
    char s[2] = "*";
    char enter[2] = "\n";

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++){
            
            if(i==(N/3) && j==(N/3)){
                strcat(str, blank);
                //printf(" ");
            }else{
                strcat(str, s);
                //printf("*");
            }
            
        }
        strcat(str, enter);
        //printf("\n");
           
    }

    return str;
}
/*

*********
* ** ** *
*********
***   ***
* *   * *
***   ***
*********
* ** ** *
*********

*/
void starRecurssion(int N){

    
    for (int i = 0; i < N/3; i++)
    {
        for (int j = 0; j < N/3; j++){
            
            if(i==(N/3) && j==(N/3)){
                printf(" ");
            }else{
                star(N/3);
            }
            
        }

    }
    
}
void main(){

    int N;
    scanf("%d", &N);

    char *str[100];
    printf("%s", strcat(str,star(N)));
    //starRecurssion(N);
    //starRecurssion(N);
}