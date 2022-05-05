#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

void printArray(int *arr, int n) {
    
    int i;
    for (i = 0; i < n; i++) {

        printf("%c ", arr[i]);
    }
    printf("\n");
}

int len(const char* ch){

    //int c = (int)ch;
    int length = 0;
    
    while(*ch){
        
        ch++;
        length++;
    }
    
    return length;

}

int strcompare(char* str1, char* str2){

    int i = 0;
    int fal = 0;
/*
    if (strlen(str1) != strlen(str2))
    {
        fal++;
        return fal;
    }
*/

    while (str1[i])
    {
        if (str1[i] > str2[i])
        {
            fal++;
            break;
        }else if(str1[i] == str2[i]){
            i++;
        }else{
            fal--;
            break;
        }
    }

    return fal;
}

typedef struct arrayList{

    short length;
    char *address;

} arrayList;

typedef struct string
{
    char character[51];

} string;

void change(int* arr, int* next, int* pointer){

    int change = arr[*next];
    arr[*next] = arr[*pointer];
    arr[*pointer] = change;
}

int main(){

//alphabet 26

    int N;
    scanf("%d", &N);

    char character[51];

    char arr[20000];

    for (int i = 0; i < N; i++)
    {

        scanf("%s", character);

        printf("%s", character);
    }

    for (int i = 0; i < 5; i++){
        printf("%s", arr[i]);
    }
    
    return 0;
}