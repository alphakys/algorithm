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

void star(int N){
    int length = (N+1)*(N+1);

    char* str = malloc(length);

    char blank = "";
    char star = "*";
    char enter = "\n";

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++){
            
            if(i==(N/3) && j==(N/3)){
                strconcat(str, blank);
                //printf(" ");
            }else{
                strconcat(str, star);
                //printf("*");
            }
            
        }
        strconcat(str, enter);
        //printf("\n");
           
    }
    
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
    star(N);
    //starRecurssion(N);
    //starRecurssion(N);
}