#include <stdio.h>
#include <unistd.h>
unsigned int sz = 1021<<13;


int main()
{

    //printf("%u", 1343 << 14);
    
    char str[sz], *p = str; read(0, str, sz);

    for (; *p++!='\0'; ){
    
        printf("%d ", *p);
    }
    //printf("%s", str);
    // for (; *++p;);
    // write(1, str, p-str);

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

