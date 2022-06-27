#include <stdio.h>
//#include <unistd.h>
#include <stdlib.h>

int sz = 30;
char str[30];
char *p = str;

char readChar()
{
    /*
    if (p == str+sz)
    {
        fread(p=str, 1, sz, stdin);
    }
    */
    return *p++;
}

int readInt()
{
    int sum = 0;
    char c = readChar();

    int minus = 1;

    if (c == 45)
    {
        minus = -1;
        c = *p++;
    }

    for (; c & 16; c = readChar())
    {
        sum = sum * 10 + (c & 15);
    }

    return sum * minus;
}

typedef struct node{
    int val;
    int idx;
} node;



int main()
{
    
    fread(str, 1, sz, stdin);
    
    node no[1000000];

    int N = readInt();

    for (int i = 0; i < N; i++)
    {
        
        no[i].val = readInt();
        no[i].idx = i;
        
    }   

/*
    for (int i = 0; i < N; i++)
    {
        //int a = readInt();
        printf("%d %d\n", no[i].val, no[i].idx);
    }
*/    
    return 0;
}
//12개