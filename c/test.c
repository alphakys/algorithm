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

void printArray(int *arr, int n) {
    int i;
    for (i = 0; i < n; i++) {

        printf("%d ", arr[i]);
    }
    printf("\n");
}

void strToint(char* str, int* arr, char delim){
    
    int arr_ptr = 0;
    int index = 0;
    int s_flag = 0;
    char s[10];

    while (str[index] != '\0')
    {
        if ( str[index] == delim )
        {
            arr[arr_ptr++] = atoi(s);
            s_flag = 0;
            
            memset(s,0,10);
            index++;
        }
        else
        {   
            printf("%c\n", str[index]);
            s[s_flag++] = str[index++];
            
        }

       
    }
    arr[arr_ptr++] = atoi(s);
}

void main(){
    char s[100] = "11 23 45 4 8 9 75";
    int arr[10];

    //char delim = '';
    strToint(s, arr, ' ');
    printArray(arr, 10);

    char s1[11] = " Ceedrilb";
    char s2[11] = "Buslill";

    //int i = 0;
    //int len = strlen(s)-1;

/*
    while (s1[i] != 0)
    {
        strcpy(s3,&s1[i++]);
    }
*/
    //printf("%s\n", s3);

}