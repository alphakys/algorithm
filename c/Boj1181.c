#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int strcompare(char* str1, char* str2){

    int i = 0;
    int flag = 0;

    while (str1[i] || str2[i])
    {
        if (str1[i] > str2[i])
        {
            flag--;
            break;
        }else if(str1[i] == str2[i]){
            i++;
            
        }
        else
        {
            flag++;
            break;
        }
    }

    if(flag==0){
        str2[0] = '0';
    }
    return flag;
    

    
}

typedef struct string {
    char s[51];
    int length;
} string;


int compare(const void *a, const void *b){
    string *str1 = (string *)a;
    string *str2 = (string *)b;
    int n1 = str1->length;

    int n2 = str2->length;

    if(n1 > n2){
        return 1;
    }else if(n1 < n2){
        return -1;
    }else{

        int flag = strcompare(str1->s, str2->s);
        if (flag <0)
        {
            //printf("return %d : \n", 1);
            return 1;
        }
        else
        {
            //printf("return %d : \n", -1);
            return -1;
        }
    }
    
}

int main()
{

    int N;
    scanf("%d", &N);

    string arr[20000];

    for (int i = 0; i < N; i++)
    {

        scanf("%s", &(arr[i].s));

        int len = strlen(arr[i].s);
        arr[i].length = len;
        //printf("%c %d", arr[i].s[0], arr[i].length);
    }

    qsort(arr,N,sizeof(arr[0]), compare);

    for (int i = 0; i < N; i++)
    {
        char *p = (arr[i].s);

        if(*p =='0'){
            continue;
        }

        while(*p){

            printf("%c", *p);
            p++;
        }
        printf("\n");

    }
   
    return 0;
}