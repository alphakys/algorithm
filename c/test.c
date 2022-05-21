#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
typedef struct list
{
    int i;
    int index;

} list;




int compare(const list *a, const list *b){

    if((int *)(a->i) > (int *)(b->i)){
        return 1;
    }else if((int *)(a->i) < (int *)(b->i)){
        return -1;
    }else{
        
        if( a->index >  b->index){
            //printf("return %d : \n", 1);
            return 1;
        }else{
            //printf("return %d : \n", -1);
            return -1;
        }
        
    }
    
}
*/

#include <stdio.h>
#include <fcntl.h>

//#include <sstream>
#include <unistd.h>

void print(char* str){

    for (int i = 0; i < 4; i++)
    {
        printf("%c", str[i]);
    }
}

void star(char* s, int N){

    if(N<4){
        star(s, N + 1);
    }

    for (int j = 0; j < N-1; j++)
    {
        print(s);
    }
    printf("\n");
    
}

void main(){

    char s[5] = "____";

    star(s, 1);
    /*
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < i; j++)
        {
            print(s);
        }
        printf("\n");
    }
    */
}