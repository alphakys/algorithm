#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

int buff_size = 1<<10;

void main()
{
    //printf("%c", 11&&2);
    char buff[buff_size], *p = buff;
    
    //printf("%p %p", p, buff);
    /*
    if(p == buff+buff_size){
        read(0, p=buff, buff_size);
    }
*/

//unsigned int a = 1<<31;
//printf("%u", a);
read(0, buff, buff_size);
    
    /*
    for(int i=0; i<3;i++){
        
        printf("%d", atoi(buff));
        //getchar();
        
    }
    */
    //fread(buff, sizeof(char), buff_size, stdin);
    
    //printf("%s", buff);



    //int i = 0;
    
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