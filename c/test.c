#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

#define buff_size 5

/*
char buff[buff_size];
char *p = buff;

char* readChar(char ch){

    if(p == buff+buff_size){
        read(0, p=buff, buff_size);
        return *p++;
    }
}
*/

void bit(){

    int sum = 0;

    char bit[9] = "00001111";
    int len = 7;

    for (int i = 0; i < 8; i++)
    {
        int n = (bit[i]-48) << len--;
        printf("%d\n", n);
        sum += n;
    }

    printf("%d", sum);
}

//unsigned int a = 1 << 12; 11개 숫자 들어가면 됨

void main()
{
    //1200000;

    int sum = 15;

    char bit[9] = "00001111";
    int len = 7;

    for (int i = 0; i < 8; i++)
    {
        int n = (bit[i]-48) << len--;
        printf("%d\n", n);
        sum += n;
    }

    
    
    
    printf("%d", sum);
    // printf("%d", print(b));
    //  printf("%p %p", p, buff);
    /*
    if(p == buff+buff_size){
        read(0, p=buff, buff_size);
    }
*/
    // char c = ReadChar(); c & 16; ret = 10 * ret + (c & 15), c = ReadChar()
    // unsigned int a = 1<<31;
    // printf("%u", a);
    
    /*
    for(int i=0; i<3; i++){
        read(0, buff, buff_size);
        //printf("%p %p %p\n", buff, p, buff+buff_size);
        
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