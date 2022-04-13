#include <stdio.h>
#include <stdlib.h>

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


int N = 16;
int arr[16] = {5,5,3,4,5,1,0,4,1,3,0,2,4,2,3,0};

int sort[16];
int count[16];

for (int i = 0; i < 16; i++){
    //printf("%d", sort[i]);
    sort[i] = -1;
    count[i] = 1; 
}


//sort[0] =5    arr[2] = 3 --> sort[1] = 3
//count[0] = 2  
int limit = 0;

for (int i = 0; i < N; i++)
{
    //i=2 j=0 j=1
    for (int j = 0; j < N; j++)
    {

        if (arr[i] == sort[j])
        {
            count[j]++;
            break;
        }
        else if(arr[i] != sort[j] && sort[j]<0)
        {
            
            for (int insert = 1; insert <= limit; insert++)
            {

                for (int i = insert-1; i >=0; i--)
                {
                    if(sort[i]> sort[insert]){
                        
                        change(sort, &i, &insert);
                        insert--;
                        
                    }
                }
                
            }
            
            sort[j] = arr[i];
            limit++;
            break;
            
        }
    }
}




    for (int i = 0; i < N; i++){
        printf("arr[%d] %d  sort[%d]  %d   count[%d]  %d\n", i, arr[i], i, sort[i], i, count[i]);
        //printf("i %d  sort  %d   count  %d\n", arr[i], sort[i], count[i]);
    }
    
    //free(sort);
    
    return 0;
}