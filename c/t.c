#include <stdio.h>
#include <unistd.h>
int sz = 1<<16;

int main()
{

    char str[sz], *p = str; read(0, str, sz);
    
    for (; *++p;);
    write(1, str, p-str);

/*
    for (; ; p++)
    {
        if (p == str + sz)
            read(0, p = str, sz);

        if (*p == '\n')
        {
            write(1, c, p-c);
            c = p+1;
            //break;                
        }

    }
*/    
    //printf("%d", 1);
    
    return 0;
}

