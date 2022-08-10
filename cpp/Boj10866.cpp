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

int answer[100];
int flag = 0;

#define MAX_SIZE 10//10000
int arr[MAX_SIZE];

int front=-1;
int front_idx=0;

int rear= MAX_SIZE-1;
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
    
}

void push_back(int val)
{
    arr[rear--] = val;
    length++;
    
    if (rear_idx == MAX_SIZE){
        rear_idx--;
    }

}

void pop_front(){
    
    if(!isEmpty())
    {
        front_idx > front ? front=-1, front_idx=0, answer[flag++] =arr[rear++] : answer[flag++] =arr[front_idx++];
    }else
    {
        answer[flag++] = -1;
        //printf("%d\n", -1); 
    }

    if(length>0){
        length--;
    }
    

}

void pop_back(){
    
    if(!isEmpty())
    {
        printf("front_idx : %d, front : %d / rear_idx : %d, rear : %d\n", front_idx, front, rear_idx, rear);
        rear_idx > rear ? rear=MAX_SIZE-1, rear_idx=MAX_SIZE, answer[flag++] =arr[front--] : answer[flag++] = arr[rear_idx--];
    }else
    {
        answer[flag++] =-1;
        //printf("-1\n"); 
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
            if(command[6] == 'a'){ push_back(readInt()); }
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
                front_idx > front ? answer[flag++] =arr[rear] : answer[flag++] = arr[front_idx];
            }
            else 
            {
                answer[flag++] =-1;//printf("-1\n");
            }
            continue;
        }
        else if (c[0] == 98)
        {
            //b
            if(!isEmpty())
            {
                rear_idx < rear ? answer[flag++] = arr[front] : answer[flag++] =arr[rear_idx];
            }else
            {
                answer[flag++] =-1;
                //printf("-1\n"); 
            }
            continue;

        }else if(c[0]==101)
        {
            //e
            answer[flag++] =isEmpty();
            continue;

        }else if(c[0]==115)
        {
            //s
            answer[flag++] =length;
            continue;

        }else if(c[0]==112)
        {   
            if( c[4]== 'f') { pop_front(); }
            else{ pop_back(); }
        }
        //printf("front_idx : %d, front : %d / rear_idx : %d, rear : %d\n", front_idx, front, rear_idx, rear);
        //printInt(arr, 10);
    }

    for(int i=0; i< flag; i++){
        printf("%d\n", answer[i]);
    }
    return 0;
}
