#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
//char rbuf[1 << 20];

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


void charArray(char *arr, int n) {
    int i;
    for (i = 0; i < n; i++) {

        printf("%d ", arr[i]);
    }
    printf("\n");
}

//#pragma GCC optimize("03");

void main()
{

    int N;
    
    scanf("%d", &N);
    getchar();

    //char str[N*9+(N+1)];
    char str[N];

    for (int i = 0; i < N; i++)
    {
        fread(str,1,1,stdin);
        printf("%s\n", str);
    }

    charArray(str,10);
    /*
    char s[100] = "-1 -2 -4 -8 9 1 1 2 3 3 4 4";
    int arr[10];
    int positive[40] = {0,};
    int negative[40] = {0,};
    // int* arr = strToint(s, arr, ' ');

    countNumber(s, positive, negative, ' ');

    printArray(positive, 10);
    printArray(negative, 10);

    char s1[11] = " Ceedrilb";
    char s2[11] = "Buslill";

    //int i = 0;
    //int len = strlen(s)-1;


    while (s1[i] != 0)
    {
        strcpy(s3,&s1[i++]);
    }

    //printf("%s\n", s3);
    */
}