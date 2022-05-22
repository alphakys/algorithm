#include <stdio.h>

int main(){

    int N;
    scanf("%d", &N);

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

    return 0;
}
