#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list
{
    int i;
    int index;

} list;




int compare(const list *a, const list *b){

    if((int *)(a->i) > (int *)(b->i)){
        return 1;
    }else if((int *)(a->i) < (int *)(b->i)){
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




void main(){

    int a;
    char name[4];
    
    scanf("%d %s", &a, &name);

    printf("%d %s", a, name);
/*
    list l[30000];
    
    for(int i=0; i<30000; i++){
                
        l[i].index = i;
        l[i].i = 1;
        //printf("%d\n", l[i].i);
                
    }

    qsort(l, 30000, sizeof(l[0]), compare);

    for(int i=0; i<30000; i++){
                
        printf("%d\n", l[i].index);
                
    }
*/    
    

/*
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
        
        }

*/

}