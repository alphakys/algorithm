#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
char rbuf[1 << 20];


int strToint(char* str){
    int start = 0;

    int sum = 0;

    for (int i = 0; str[i] != '\0'; ++i)
    {
        printf("%c", str[i]);
        //sum = (str[i]-48)*(10);
    }

    //printf("%d", sum);
    return sum;
}


void main(){

    char c[6] = "1123";
    char a = 127;
    //printf("%d", a);
    strToint(c);
}