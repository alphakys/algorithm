#include <stdio.h>
#include <iostream>
using namespace std;

void printInt(int *arr, int n) {
    int i;
    for (i = 0; i < n; i++) {

        printf("%d ", arr[i]);
    }
    printf("\n");
}

#define MAX_SIZE 10000
int arr[MAX_SIZE];

int rear= -1;
int front=-1;
int length = 0;

void push_front(int val)
{
    arr[++rear] = val;
    length++;
    if (front == -1)
    {
        front++;
    }
}

void push_front(int val)
{
    arr[++rear] = val;
    length++;
    if (front == -1)
    {
        front++;
    }
}

int dequeue(){
    
    if(front==-1)
    {
        return -1;
    }
    else
    {   
        
        int ret = arr[front];
        
        if(front<rear)
        {
            arr[front++] = 0;
            length--;
        }else
        {
            arr[front] = 0;
            front = -1;
            rear = -1;
            length = 0;
        }

        return ret;
    }
}

int isEmpty(){
   
    if(length==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
   
}


int size_ =40;
char buff[40];

char *p = buff;

char readChar(){
    
    if(p>=buff+size_){
        
        fread(p=buff, 1, size_, stdin);
    }

    return *p++;
}

int readInt(){
    
    int sum = 0;
    char c = readChar();

    for (; c & 16; c = readChar())
    {
        sum = (sum * 10) + (c & 15);
    }
    
    return sum;
} 

char command[6];

char* readString(){

    int idx = 0;
    for (char c = readChar(); c!= 10; c = readChar())
    {   
        if(c==32)
        {   
            printf("p : %d\n", command[6]);
            //push_front( readInt() );
            break;
        }else
        {
            command[idx++] = c;
        }
        
    }
    command[idx] = '\0';
    return command;
}

int main(){
    
    int N;
    fread(buff, 1, size_, stdin);

    N= readInt();

    for (int i = 0; i < N; i++)
    {
        
        char* c = readString();

        if (c[0] == 102)
        {
            //f
            if(length==0){
                printf("%d\n", -1);
                continue;
            }
            printf("%d\n", arr[front]);
            continue;
        }
        else if (c[0] == 98)
        {
            //b
            
            if(length==0){
                printf("%d\n", -1);
                
                continue;
            }
            printf("%d\n", arr[rear]);
            
            continue;

        }else if(c[0]==101)
        {
            //e
            printf("%d\n", isEmpty());
            continue;

        }else if(c[0]==115)
        {
            //s
            printf("%d\n", length);
            continue;

        }else if(c[0]==112)
        {
            
            
        }
    
    }

    return 0;
}
