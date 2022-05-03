#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

typedef struct string
{
    char character[2];
    //char *allocSize;
    //char length;

} string;

int strcmpare(char* str1, char* str2){
/*
    if(0 == str1){
        printf("%p", str1);
        return 0;
    }

    int i = 0;

    if(strlen(str1)!=strlen(str2)){
        printf("not same");
    }

    while ((int)str1[i] == (int)str2[i])
    {
        printf("%c", str1[i]);
        i++;
    }
*/
    return 0;
}

void main(){


string arr[5][5];




        for(int j=0; j<5; j++){

            memset(arr[j],NULL,sizeof(string)*5);

            for(int i=0; i<5; i++){
                printf("j : %d, i : %d, p : %d\n",j, i, arr[j][i]);
            }
            /*
            if(!arr[1][j].character){
                printf("%d %d", j,arr[1][j]);
                break;
            }
        */
        }



}