#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int strToint(int start, char* str){

    int digit=0;
    char* digit_flag = str;

    while(!(*digit_flag ==32)){

        digit_flag++;
        digit++;
 
    }

    int sum=0;

    int poww = (digit-start)-1;

    for (int j = start; j < digit; j++)
    {
    
        double n = (double)str[j] - (double)48;
        double powNum = pow((double)10,(double)(poww));

        sum += (int)(n*powNum);
        poww--;
    
    }
    
    return sum;
}

typedef struct string{
    char s[105];
    int index;
} string;

int compare(const string *a, const string *b){
    int n1 = strToint(0, (char *)(a->s));
    
    int n2 = strToint(0, (char *)(b->s));

    //printf("return %d : %d    %d : %d \n", n1, n2, a->index, b-> index);

    if(n1 > n2){
        return 1;
    }else if(n1 < n2){
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


int main(){

    int N;
    scanf("%d", &N);
    getchar();

    string* list = (string *)malloc(sizeof(string)*100001);
/*
    for(int i=1; i<100001; i++){
        list[i] = (string *)malloc(sizeof(string));
        memset(list[i],0,sizeof(string));
    }
*/
    string str;

    for(int i=1; i<=N; i++){
        //scanf("%s", str);
        fgets(str.s, 105, stdin);

        char* ch = str.s;

        int k=0;

        while((*ch)){
            if((*ch)==10 || (*ch)==30){
                break;
            }
            
            list[i].s[k] = *ch;
            k++;
            ch++;
        }
        list[i].index = i;
        
    }

/*
    for(int i=1; i<=N; i++){
        int len = strlen(list[i].s);
        printf("index : %d\n", list[i].index);
        for(int j=0; j <len; j++){
            
            printf("%c", list[i].s[j]);
        }
        printf("\n");
    }
    */


   /*
    for(int i=1; i<=N; i++){
        printf("%d %d", &list[i].s[i], list[i].index);
        
        printf("\n");
    }
*/

    qsort(&list[1], N, sizeof(list[1]), compare);

    for(int i=1; i<=N; i++){
        int len = strlen(list[i].s);
        
        for(int j=0; j <len; j++){
            
            printf("%c", list[i].s[j]);
        }
        printf("\n");
    }


    free(list);

    return 0;
}