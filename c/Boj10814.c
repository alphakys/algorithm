#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct string{
    char name[101];
    int age;
    int index;
} string;

int compare(const void *a, const void *b){
    string *str1 = (string *)a;
    string *str2 = (string *)b;
    int n1 = str1->age;

    int n2 = str2->age;

    if(n1 > n2){
        return 1;
    }else if(n1 < n2){
        return -1;
    }else{
        
        if( str1->index >  str2->index){
            //printf("return %d : \n", 1);
            return 1;
        }else{
            //printf("return %d : \n", -1);
            return -1;
        }
    }
    
}

string list[100000];

int main(){

    int N;
    scanf("%d", &N);
    getchar();

    for(int i=0; i<N; i++){
        scanf("%d %s", &(list[i].age), &(list[i].name));

        list[i].index = i;
        
    }

    qsort(&list[0], N, sizeof(list[0]), compare);

    for(int i=0; i<N; i++){
        printf("%d %s\n", list[i].age, list[i].name);
    }

    return 0;
}