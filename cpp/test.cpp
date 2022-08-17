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

typedef struct Node {
    Node* head;
    Node* tail;
    int value;
} Node;

int answer[10000];
int flag = 0;

Node list[10000];
Node* front_pivot=&list[0];
Node* rear_pivot= &list[0];

int _index = 0;
int length = 0;

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
//포인터이면 -> 접근해야 한다.
void push_front(int val)
{
    
    if(_index>0)
    {
        list[_index].value = val;
        front_pivot->head = &list[_index];
        list[_index].tail = front_pivot;
        front_pivot = &list[_index];
        
    } 
    else
    {
        front_pivot->value = val;
    }

    _index++;
    length++;

}

void push_back(int val)
{
    if(_index>0)
    {
        list[_index].value = val;
        rear_pivot->tail = &list[_index];
        list[_index].head = rear_pivot;
        rear_pivot = &list[_index];
    }
    else
    {
        rear_pivot->value = val;
    }

    _index++;
    length++;
}

void pop_front(){
    
    if(!isEmpty())
    {
        answer[flag++] = front_pivot->value;
        if(front_pivot->tail ==nullptr)
        {
            front_pivot = &list[0];
            _index = 0;
        }
        else
        {
            front_pivot = front_pivot->tail;
        }       
        
    }else
    {
        answer[flag++] = -1;
    }
    
    if(length>0){ length--; }
    
    if(length==0){
        front_pivot=&list[0];
        rear_pivot= &list[0];
    }
}

void pop_back(){
    
    if(!isEmpty())
    {
        answer[flag++] = rear_pivot->value;
        
        if(rear_pivot->head == nullptr)
        {
            rear_pivot = &list[0];
            _index = 0;
        }
        else{
            rear_pivot = rear_pivot->head;
        }
        
    }else
    {
        answer[flag++] =-1;
    }
    
    if(length>0){ length--; }
    
    if(length==0){
        front_pivot=&list[0];
        rear_pivot= &list[0];
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
            if(command[6] == 'a') { push_back(readInt()); }
            else if(command[6] == 'r') { push_front(readInt()); }
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
                answer[flag++] = front_pivot->value;
            }
            else 
            {
                answer[flag++] =-1;
            }
            continue;
        }
        else if (c[0] == 98)
        {
            //b
            if(!isEmpty())
            {
                answer[flag++] =rear_pivot->value;
            }
            else
            {
                answer[flag++] =-1;
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
        
    }

    for(int i=0; i< flag; i++){
        printf("%d\n", answer[i]);
    }
    
    return 0;
}
