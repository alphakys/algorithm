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

void star(int N){


    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++){
            
            if((i%3)==1)
            {
                if( ( i >= (N/3) && i < ((N*2)/3) ) && ( j >= (N/3) && j < ((N*2)/3) ) ){
                    printf(" ");
                }else{
                    
                    if(j%3 ==1){
                        printf(" ");
                    }else{
                        printf("*");
                    }
                    
                }

            }else{
                if(( i >= (N/3) && i < ((N*2)/3) ) && ( j >= (N/3) && j < ((N*2)/3) ) ){
                    printf(" ");
                }else{
                    printf("*");
                }
            }
            
        }

        printf("\n");
           
    }
}
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


void starRecurssion(int N){

    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++){
            
            if(i==(N/3) && j==(N/3)){
                printf(" ");
            }else{
                printf("*");
            }
            
        }

        printf("\n");
           
    }
    
}
void main(){

    int N;
    scanf("%d", &N);
    //star(N);
    starRecurssion(N);
}