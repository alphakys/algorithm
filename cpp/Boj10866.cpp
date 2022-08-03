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
    
    if (rear_idx == MAX_SIZE){rear_idx--;}
    else { rear_idx++;}
}

int pop_front(){
    
    //front_idx ==-1 ? -1 : arr[front_idx];
    int ret = front_idx == -1 ? -1 : arr[front_idx++];
    arr[front_idx++] = 0;
    return ret;
}

int pop_back(){
    
    int ret = rear_idx == MAX_SIZE ? -1 : arr[--rear_idx];
    arr[rear_idx] = 0;
    //cout << "ans : " << ret << endl;
    return ret;
}
//    1       1  
//0 1 2 3 4 5 6 7 

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
            else if(command[6] == 'r') push_front(readInt());
            
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
            if(length==0){ printf("%d\n", -1);continue; }
            printf("%d\n", arr[front_idx]);
            continue;
        }
        else if (c[0] == 98)
        {
            //b
            if(length==0){printf("%d\n", -1);continue;} 
            printf("%d\n", arr[rear_idx]);
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
        {   if( c[4]== 'f') { pop_front(); }
            else{ pop_back(); }
        }
        printf("front_idx : %d, front : %d / rear_idx : %d, rear : %d\n", front_idx, front, rear_idx, rear);
        printInt(arr, 10);
    }

    return 0;
}
