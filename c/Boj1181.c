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


int main(){

//alphabet 26

    int N;
    scanf("%d", &N);

    char str[51];

    char arr[20000];

    for (int i = 0; i < N; i++)
    {

        scanf("%s", str);

        arr[i] = str[0];

        //printf("%s", character);
    }

    for (int i = 0; i < 5; i++){

        char ch = arr[0];
        char *ptr = (&arr[0])++;

        printf("%p %c %d\n", ch, ch, ch);
        printf("%p %c %d\n", ptr, *ptr, ptr);
        
        /*
        int fal = strcompare(&arr[i], &arr[i+1]);
        printf("%c", fal);
        */
    }
    
    return 0;
}