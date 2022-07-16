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
int rear= -1;
int front=-1;
int size = 0;

void enqueue(int val)
{
    arr[++rear] = val;
    size++;
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
        arr[front++] = 0;
        size--;
        return ret;
    }
}


int isEmpty(){
   
    if(front==-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
   
}


int size =23;
char buff[23];

char *p = buff;

char readChar(){
    
    if(p==buff+size){
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

void readString(){

    char c = readChar();
    char ret = 0;
    for (;; c = readChar())
    {
        //printf("c : %d\n", c);
        if (c == 102)
        {
            //f
            printf("%d\n", front);
            //ret = 102;
            p=p+5;
            break;
        }
        else if (c == 98)
        {
            //b
            printf("%d\n", rear);
            p=p+4;
            break;
        }else if(c==101)
        {
            //e
            ret = 101;
            p=p+5;
            break;
        }else if(c==115)
        {
            //s
            ret = 115;
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
                ret = 111;
                p = p + 3;
                break;
            }
        }
    }

    //for (char c = readChar(); c!=10; c = readChar());

    //return ret;
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

    printInt(arr, 10);



    /* printf("%d\n",isEmpty());
    enqueue(3);
    enqueue(4);
    enqueue(5);
    printf("%d\n", dequeue());
    printf("%d\n", dequeue());



    printf("---------------\n");
    printf("front : %d\n", front);
    printInt(arr, 10);
 */
    return 0;
}