#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

int buff_size = 5;

void main()
{
    char buff[buff_size], *p = buff;
    //printf("%p %p", p, buff);
    read(0, p=buff, buff_size);
    //fread(buff, sizeof(char), buff_size, stdin);

    printf("%p %p %s", p, buff, buff);
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