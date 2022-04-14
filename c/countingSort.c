#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10001

int main(){

    int N;
    scanf("%d", &N);


    short* sort = malloc(sizeof(short)*MAX_SIZE);
    short* count= malloc(sizeof(short)*MAX_SIZE);

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
    
    free(arr);
    free(sort);
    free(count);
    return 0;
}
