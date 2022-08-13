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

int answer[100];
int flag = 0;

#define MAX_SIZE 9//10000
#define START 0

Node list[10];

int front_pivot=MAX_SIZE;
//int start =MAX_SIZE-1;  

int rear_pivot= START;
//int _end = 0;

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

void push_front(int val)
{
    //arr[--front_pivot] = val;
    list[]
    length++;
    //printInt(arr, 10);
}

void push_back(int val)
{
    arr[++rear_pivot] = val;
    length++;
    //printInt(arr, 10);
}

void pop_front(){
    
    if(!isEmpty())
    {
        start < front_pivot ? front_pivot=MAX_SIZE, start =MAX_SIZE-1, answer[flag++] = arr[_end++] : answer[flag++] =arr[front_pivot++];
        printf("start : %d, front_pivot : %d / _end : %d, rear_pivot : %d\n", start, front_pivot, _end, rear_pivot);
    }else
    {
        answer[flag++] = -1;
    }
    
    if(length>0){
        length--;
    }
}

void pop_back(){
    
    if(!isEmpty())
    {
        _end > rear_pivot ? rear_pivot=-1, _end=0, answer[flag++] =arr[start--] : answer[flag++] = arr[rear_pivot--];
        printf("start : %d, front_pivot : %d / _end : %d, rear_pivot : %d\n", start, front_pivot, _end, rear_pivot);
    }else
    {
        answer[flag++] =-1;
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
                //printInt(arr, 10);
                //printf("FFF : start : %d, front_pivot : %d / _end : %d, rear_pivot : %d\n", start, front_pivot, _end, rear_pivot);
                //printf("dsfdsf : %d", arr[rear_pivot]);
                
                printf("start : %d, front_pivot : %d / _end : %d, rear_pivot : %d\n", start, front_pivot, _end, rear_pivot);
                start < front_pivot ? answer[flag++] = arr[_end] : answer[flag++] =arr[front_pivot];
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
                
                printf("start : %d, front_pivot : %d / _end : %d, rear_pivot : %d\n", start, front_pivot, _end, rear_pivot);
                //printInt(arr, 10);
                _end > rear_pivot ? answer[flag++] =arr[start] : answer[flag++] = arr[rear_pivot];
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
            if( c[4]== 'f') {  pop_front(); }
            else{  pop_back(); }
        }
        //printf("start : %d, front_pivot : %d / _end : %d, rear_pivot : %d\n", start, front_pivot, _end, rear_pivot);
        //printInt(arr, 10);
    }

    for(int i=0; i< flag; i++){
        printf("%d\n", answer[i]);
    }
    return 0;
}


// #include <stdio.h>
// #include <iostream>
// using namespace std;

// void printInt(int *arr, int n) {
//     int i;
//     for (i = 0; i < n; i++) {

//         printf("%d ", arr[i]);
//     }
//     printf("\n");
// }

// int answer[100];
// int flag = 0;

// #define MAX_SIZE 10//10000
// int arr[MAX_SIZE];

// int front_pivot=-1;
// int start=0;

// int rear_pivot= MAX_SIZE;
// int _end= MAX_SIZE-1;

// int length = 0;

// int isEmpty(){
//     //int sz = (front_pivot - start+1) + (rear_pivot - _end+1);
//     if(length==0)
//     {
//         return 1;
//     }
//     else
//     {
//         return 0;
//     }
   
// }

// void push_front(int val)
// {
//     arr[++front_pivot] = val;
//     length++;
//     //printInt(arr, 10);
// }

// void push_back(int val)
// {
//     arr[--rear_pivot] = val;
//     length++;
//     //printInt(arr, 10);
// }

// void pop_front(){
    
//     if(!isEmpty())
//     {
//         start > front_pivot ? front_pivot=-1, start =0, answer[flag++] =arr[rear_pivot++] : answer[flag++] =arr[front_pivot--];
//     }else
//     {
//         answer[flag++] = -1;
//     }
//     printf("start : %d, front_pivot : %d / _end : %d, rear_pivot : %d\n", start, front_pivot, _end, rear_pivot);
//     if(length>0){
//         length--;
//     }
// }

// void pop_back(){
    
//     if(!isEmpty())
//     {
//         _end < rear_pivot ? rear_pivot=MAX_SIZE, _end=MAX_SIZE-1, answer[flag++] =arr[start++] : answer[flag++] = arr[rear_pivot--];
        
//     }else
//     {
//         answer[flag++] =-1;
//     }
//     printf("start : %d, front_pivot : %d / _end : %d, rear_pivot : %d\n", start, front_pivot, _end, rear_pivot);
//     if(length>0){
//         length--;
//     }
// }

// int size_ =30;
// char buff[30];

// char *p = buff;

// char readChar(){
    
//     if(p>=buff+size_){
        
//         fread(p=buff, 1, size_, stdin);
//     }

//     return *p++;
// }

// int readInt(){
    
//     int sum = 0;
//     char c = readChar();

//     for (; c & 16; c = readChar())
//     {
//         sum = (sum * 10) + (c & 15);
//     }
    
//     return sum;
// } 

// char command[6];

// char* readString(){

//     int idx = 0;
//     for (char c = readChar(); c!= 10; c = readChar())
//     {   
//         if(c==32)
//         {   
//             if(command[6] == 'a'){ push_back(readInt()); }
//             else if(command[6] == 'r') { push_front(readInt()); };
//             command[0] = '\0';
//             break;
//         }else
//         {
//             command[idx++] = c;
//         }
        
//     }
//     command[idx] = '\0';
//     return command;
// }

// int main(){
    
//     int N;
//     fread(buff, 1, size_, stdin);

//     N= readInt();

//     for (int i = 0; i < N; i++)
//     {
//         char* c = readString();
//         if (c[0] == 102)
//         {
//             //f
//             if(!isEmpty())
//             {
//                 printInt(arr, 10);
//                 printf("FFF : start : %d, front_pivot : %d / _end : %d, rear_pivot : %d\n", start, front_pivot, _end, rear_pivot);
//                 printf("dsfdsf : %d", arr[rear_pivot]);
//                 start > front_pivot ? answer[flag++] =arr[_end] : answer[flag++] = arr[front_pivot];
//             }
//             else 
//             {
//                 answer[flag++] =-1;//printf("-1\n");
//             }
//             continue;
//         }
//         else if (c[0] == 98)
//         {
//             //b
//             if(!isEmpty())
//             {
//                 _end < rear_pivot ? answer[flag++] = arr[start] : answer[flag++] =arr[rear_pivot];
//             }else
//             {
//                 answer[flag++] =-1;
//                 //printf("-1\n"); 
//             }
//             continue;

//         }else if(c[0]==101)
//         {
//             //e
//             answer[flag++] =isEmpty();
//             continue;

//         }else if(c[0]==115)
//         {
//             //s
//             answer[flag++] =length;
//             continue;

//         }else if(c[0]==112)
//         {   
//             if( c[4]== 'f') { pop_front(); }
//             else{ pop_back(); }
//         }
//         //printf("start : %d, front_pivot : %d / _end : %d, rear_pivot : %d\n", start, front_pivot, _end, rear_pivot);
//         //printInt(arr, 10);
//     }

//     for(int i=0; i< flag; i++){
//         printf("%d\n", answer[i]);
//     }
//     return 0;
// }
