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

#define MAX_SIZE 10//10000
int arr[MAX_SIZE];

int front=-1;
int front_idx=-1;

int rear= MAX_SIZE;
int rear_idx= MAX_SIZE;

int length = 0;

int isEmpty(){
    //int sz = (front - front_idx+1) + (rear - rear_idx+1);
    if(length==0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
   
}

void push_front(int val)
{
    arr[++front] = val;
    length++;
    if (front_idx == -1)
    {
        front_idx++;
    }
}

void push_back(int val)
{
    arr[--rear] = val;
    length++;
    
    if (rear_idx == MAX_SIZE){
        rear_idx--;
    }

}

void pop_front(){
    
    if(!isEmpty())
    {
        front_idx > front ? front=-1, front_idx=-1, printf("%d\n", arr[rear++]) : printf("%d\n", arr[front_idx++]);
    }else
    {
        printf("empty : %d\n", -1); 
    }

    if(length>0){
        length--;
    }
    

}

void pop_back(){
    
    if(!isEmpty())
    {
        rear_idx < rear ? rear=MAX_SIZE, rear_idx=MAX_SIZE, printf("%d\n", arr[front--]) : printf("%d\n", arr[rear_idx--]);
    }else
    {
        printf("empty : %d\n", -1); 
    }

    if(length>0){
        length--;
    }
}



int size_ =30;
char buff[30];

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
            if(command[6] == 'a'){ push_back(readInt());}
            else if(command[6] == 'r') { push_front(readInt()); };
            command[0] = '\0';
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
            if(!isEmpty())
            {
                front_idx > front ? printf("%d\n", arr[rear]) : printf("%d\n", arr[front_idx]);
            }
            else 
            {
                printf("%d\n", isEmpty());
            }
            continue;
        }
        else if (c[0] == 98)
        {
            //b
            if(!isEmpty())
            {
                rear_idx < rear ? printf("%d\n", arr[front]) : printf("%d\n", arr[rear_idx]);
            }else
            {
                printf("%d\n", -1); 
            }
            continue;

        }else if(c[0]==101)
        {
            //e
            printf("%d\n", isEmpty());
            continue;

        }else if(c[0]==115)
        {
            //s
            printf("size : %d\n", length);
            continue;

        }else if(c[0]==112)
        {   
            if( c[4]== 'f') { pop_front(); }
            else{ pop_back(); }
        }
        //printf("front_idx : %d, front : %d / rear_idx : %d, rear : %d\n", front_idx, front, rear_idx, rear);
        printInt(arr, 10);
    }

    return 0;
}
