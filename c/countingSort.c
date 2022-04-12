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

int sort[16] = {-1,};
int count[16] = {1,};


for (int i = 0; i < N; i++)
{
    
    for (int j = 0; j < N; j++)
    {

        if (arr[i] == sort[j])
        {
            count[j]++;
            break;
        }
        else if(arr[i] != sort[j] && sort[j]<0)
        {
            sort[j] = arr[i];
            break;
            
        }
    }
}




    for (int i = 0; i < N; i++){
        printf("arr %d  sort  %d   count  %d\n", arr[i], sort[i], count[i]);
        //printf("i %d  sort  %d   count  %d\n", arr[i], sort[i], count[i]);
    }
    
    //free(sort);
    
    return 0;
}