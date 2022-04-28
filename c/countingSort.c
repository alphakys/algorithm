#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10001

void change(int* arr, int* next, int* pointer){

    int change = arr[*next];
    arr[*next] = arr[*pointer];
    arr[*pointer] = change;
}

int main(){

    int N;
    scanf("%d", &N);

    int arr[] = {3,1,1,2,3,3};

    int* sort = malloc(sizeof(int)*MAX_SIZE);
    int* count= malloc(sizeof(int)*MAX_SIZE);

    for (int i = 0; i < N; i++){
        
        sort[i] = 0;
        count[i] = 1; 
    }


    short limit = 0;

    for (int i = 0; i < N; i++)
    {
        
        for (int j = 0; j < N; j++)
        {

            if (arr[i] == sort[j])
            {
                count[j]++;
                sort[j] = arr[i];
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
                            change(count, &k, &insert);
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
        
        for (int i = 0; i < count[z]; i++)
        {
            printf("%d\n", sort[z]);
        }
        
        z++;
    }
    
    //free(arr);
    free(sort);
    free(count);
    return 0;
}
