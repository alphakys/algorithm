#include <stdio.h>
#include <unistd.h>
int sz = 1<<16;
int main()
{

    char str[sz], *p = str; read(0, str, sz);
    int cnt = 0;

    for (; *p == ' '; p++);

    for (;; p++)
    {
        
        if (p == str + sz)
            read(0, p = str, sz);

        if (*p == '\n')
        {
            if(*--p==' ')
                cnt--;
            break;
        }

        if (*p == ' ')
        {
            cnt++;
        }
    }
    
    printf("%d", cnt + 1);
    
    return 0;
}

