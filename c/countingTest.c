#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10000

void change(int* arr, int* i, int* insert){

    int change = arr[*i];
    arr[*i] = arr[*insert];
    arr[*insert] = change;
}


int main(){
/*
    int N;
    scanf("%d", &N);
   
    int* arr = malloc(sizeof(int)*N);

    for (int i = 0; i < N; i++){
        scanf("%d", &arr[i]);
    }
*/



int N = 13;
int arr[13] = {5,5,3,4,5,1,4,1,3,2,4,2,3};

    int sort[MAX_SIZE] = {0};
    //int count[MAX_SIZE];

    for (int i = 0; i < N; i++){
        
        //sort[i] = 0;
        //count[i] = 1; 
    }


    int limit = 0;

    for (int i = 0; i < N; i++)
    {
        //i=2 j=0 j=1
        for (int j = 0; j < N; j++)
        {

            if (arr[i] == sort[j])
            {
                //count[j]++;
                sort[j] += arr[i];
                break;
            }
            else if(arr[i] != sort[j] && sort[j]<1)
            {
                
                sort[j] = arr[i];
                for (int insert = 1; insert <= limit; insert++)
                {

                    for (int k = insert-1; k >=0; k--)
                    {
                        if(sort[k]> sort[insert]){
                            
                            change(sort, &k, &insert);
                            //change(count, &k, &insert);
                            insert--;
                            
                        }
                    }
                    
                }
                
                limit++;
            
                break;
                
            }
        }

        
    }
    int z = 0;

    while (sort[z]>0)
    {
        /*
        for (int i = 0; i < count[z]; i++)
        {
            printf("%d\n", sort[z]);
        }
        */
       printf("%d\n  count %d", sort[z], sort[z]);
        z++;
    }
    
    //free(arr);
    return 0;
}
