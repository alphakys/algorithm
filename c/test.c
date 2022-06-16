#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

int buff_size = 10000;

void main()
{
    //printf("%c", 11&&2);
    char buff[buff_size], *p = buff;
    //printf("%p %p", p, buff);
    //
    //fread(buff, sizeof(char), buff_size, stdin);
    read(0, buff, buff_size);
    int i = 0;
    printf("%s", buff);
    /*
    int i = 0;
    while (i<2)
    {
        if( (p+buff_size) ==buff ){
            fread(buff, sizeof(char), p = buff, stdin);
            i++;
        }
    }

    int j = 0;
    while (j < 20)
    {
        printf("%c", buff[j++]);
    }
    */
}