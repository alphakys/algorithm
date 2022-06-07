#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
char rbuf[1 << 20];

int compare(const void *a, const void *b){

    if(strcmp(a,b)>0){
        return -1;
    }
    else
    {
        return 1;
    };
}


void strToint(char* str, int* arr, char delim){

    int start = 0;
    int end = 0;
    int index = 0;
    while (str[index] != '\0')
    {
        if ( str[index] == delim )
        {
            end = index - 1;

            if ((int)str[start] == 45)
            {
            }

        else
        {
            index++;
        }

        }
    }
}

void main(){

    char s[100] = "Acbok Ceedrill Buslill";
    char s1[11] = " Ceedrilb";
    char s2[11] = "Buslill";

    int i = 0;
    int len = strlen(s)-1;
    //printf("%d", len);
    //s[22] = 97;
    //printf("%s\n", s);

    char* s3;
    while (s1[i] != 0)
    {
        //printf("%d", s1[i]);
        //s[len++] = s1[i++];
        strcpy(s3,&s1[i++]);
        // printf("%c\n", s[len]);

        //printf("%s\n", s);
        //i++;
    }

    printf("%s\n", s3);

    // printf("cat : %s\n", strcat(s, s1));
    // printf("%s", s);

    /* printf("%s", strtok(s, " "));
    char *ptr = strtok(s, " ");

    while(ptr !=NULL){
        printf("%s", ptr);
        ptr = strtok(NULL, " ");

    }
    for (int i = 0; i < 3; i++)
    {
    //    printf("%s\n", arr[i]);
    }

    */
}