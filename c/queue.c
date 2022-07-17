#include <stdio.h>

#define MAX_SIZE 2000001

void printInt(int *arr, int n) {
    int i;
    for (i = 0; i < n; i++) {

        printf("%d ", arr[i]);
    }
    printf("\n");
}

int arr[MAX_SIZE];
int rear= -1;
int front=-1;
int length = 0;

void enqueue(int val)
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


int size =40;
char buff[40];

char *p = buff;

char readChar(){
    
    if(p>=buff+size){
        fread(p=buff, 1, size, stdin);
    }

    return *p++;
}

int readInt(){
    
    int sum = 0;
    char c = readChar();

    /* int minus = 1;
    if (c == 45)
    {
        minus = -1;
        c = readChar();
    } */

    for (; c & 16; c = readChar())
    {
        sum = (sum * 10) + (c & 15);
    }
   
    return sum;
} 
//0 2 0 0 0
void readString(){

    char c = readChar();
    char ret = 0;
    for (;; c = readChar())
    {
        
        if (c == 102)
        {
            //f
            if(length==0){
                printf("%d\n", -1);
                p=p+5;
                break;
            }
            printf("%d\n", arr[front]);
            p=p+5;
            break;
        }
        else if (c == 98)
        {
            //b
            if(length==0){
                printf("%d\n", -1);
                p=p+4;
                break;
            }
            printf("%d\n", arr[rear]);
            p=p+4;
            break;
        }else if(c==101)
        {
            //e
            printf("%d\n", isEmpty());
            p=p+5;
            break;
        }else if(c==115)
        {
            //s
            printf("%d\n", length);
            p=p+4;
            break;
        }else if(c==112)
        {
            //u
            if(*p==117)
            {
                //ret = 117;
                p = p + 4;
                //ret = readInt();
                //printf("%d\n", readInt());
                enqueue(readInt());
                break;
            }
            else
            {
                //o
                printf("%d\n", dequeue());
                p = p + 3;
                break;
            }
        }
    }

}




int main(){
    
    int N;
    fread(buff, 1, size, stdin);

    N= readInt();

    for (int i = 0; i < N; i++)
    {
        readString();
        //printf("str : %d\n", );
    }

    return 0;
}
/* 
pop -1
pop -1
pop -1
push 100
push 2
back 2
front 100
pop 100
pop 2
front -1 
empty 1

*/