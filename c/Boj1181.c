#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>

void printArray(int *arr, int n) {
    
    int i;
    for (i = 0; i < n; i++) {

        printf("%d ", arr[i]);
    }
    printf("\n");
}

/*
int strToint(int start, int digit, char* str){

    int sum=0;

    int poww = (digit-start)-1;

    if((int)str[start] ==45){
        poww = poww-1;
        
        for (int j = start+1; j < digit; j++)
        {
        
            double n = (double)str[j] - (double)48;
            double powNum = pow((double)10,(double)(poww));

            sum += (int)(n*powNum);
            poww--;
        
        }
        sum = sum*-1;
                
    }else{

        for (int j = start; j < digit; j++)
        {
        
            double n = (double)str[j] - (double)48;
            double powNum = pow((double)10,(double)(poww));

            sum += (int)(n*powNum);
            poww--;
        
        }
    }

    return sum;
}
*/

typedef struct string
{
    char character[51];
    char length;

} string;


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

    if (strlen(str1) != strlen(str2))
    {
        fal++;
        return fal;
    }

    while (str1[i])
    {
        if (str1[i] != str2[i])
        {
            fal++;
            break;
        }
        i++;
    }

    return fal;
}

typedef struct arrayList{

    short length = 0;
    char *address = NULL;

} arrayList;








int main(){


//alphabet 26

    int N;
    scanf("%d", &N);

    char character[51];

    arrayList list[200001];

    for(int i=0; i<N; i++){
        
        scanf("%s", character);
        int len = strlen(character);

        if(arrayList[len])

        //char *characArr = malloc((len+1)*20000));

        if(!arrayList[len]){
            arrayList[len] = characArr;
            //printf("string %s", arrayList[len]);
        }else{
            arrayList[len]
            for (int i = 0; i<)
            {
            }
            strcompare(char* str1, char* str2)
        }

    }

    //int retu = strcompare(str[0].character,str[1].character);

    //printf("%d", retu);
    






    
    // if()

    /*
    
    

    for(int i=0; i<N; i++){
        
        printf("%d\n", strlen(str[i].character));
    }
    
    
    getchar();

    for (int j = 0; j < N; j++)
    {
        printf("%d %d\n", node[j].x, node[j].y);
    }
*/
    //free(sorted);
    //free(node);

    return 0;
}