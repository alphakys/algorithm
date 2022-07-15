#include <stdio.h>

#define MAX_SIZE 100

void printInt(int *arr, int n) {
    int i;
    for (i = 0; i < n; i++) {

        printf("%d ", arr[i]);
    }
    printf("\n");
}

int arr[MAX_SIZE];
int rear=-1;
int front=-1;

void enqueue(int val){
    arr[rear++] = val;
    
    if(front==-1){
        front++;
    }    
}

int dequeue(){
   
    if(front==-1){
        printf("queue is empty");
    }else{
        int ret = arr[front];
        arr[front++] = 0;
        
        return ret;
        
    }
    
}

int isEmpty(){
   
    if(front==-1){
        return 1;
    }else{
        return 0;
    }
   
}

int main(){

    printf("%d\n",isEmpty());
    enqueue(3);
    enqueue(4);
    enqueue(5);
    printf("%d\n", dequeue());
    printf("%d\n", dequeue());
    
    

    printf("---------------\n");
    printf("front : %d\n", front);
    printInt(arr, 10);

    return 0;
}