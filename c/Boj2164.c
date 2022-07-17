#include <stdio.h>

#define MAX_SIZE 3000001

void printInt(int *arr, int n) {
    int i;
    for (i = 0; i < n; i++) {

        printf("%d ", arr[i]);
    }
    printf("\n");
}

int arr[MAX_SIZE];
int rear  = 0;
int front  =0;
int length = 0;

void enqueue(int val)
{
    arr[rear++] = val;
    
} 

void dequeue(){

    arr[front++] = 0;
    length--;
    
}


int main(){
    
    int N;
    scanf("%d", &N);

    if(N==1){
        printf("%d", 1);
        return 0;
    }
    for (int i = 1; i <= N; i++)
    {
        enqueue(i);
    }
    length = N;

    //printInt(arr, 10);

    for (int i = 1; ; i++)
    {
        dequeue();
        
        enqueue(arr[front++]);
        
        if(length==1){
            printf("%d", arr[rear-1]);
            break;
        }
    }

    return 0;
}
