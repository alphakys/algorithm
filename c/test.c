#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
char rbuf[1 << 20];

void main(){

    //printf("%d", 1 << 20);
    fread(rbuf,1, 5, stdin);

    printf("%s", rbuf);
}