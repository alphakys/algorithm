#include <stdio.h>
#include <unistd.h>

int sz = 1<<16;
char str[1<<16];
char *p = str;

char readChar()
{
    
    if (p == str+sz)
    {
        fread(p=str, 1, sz, stdin);
    }

    return *p++;
}

int readInt()
{
    int sum = 0;
    
    for (char c = readChar(); c & 16; c = readChar()){
        
        sum = sum * 10 + (c & 15);
    }
    
    return sum;
}

int main()
{
    
    fread(str, 1, sz, stdin);
    
    int n = readInt();

    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        int a = readInt();
        sum += a;
        
    }

    printf("%d\n%lld",n, sum);
    return 0;
}
