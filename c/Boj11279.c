#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

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


int positive[10000001] ;
int negative[10000001] ;

typedef struct node{
    int value;
    int ptr = 0;

    //struct node *nextNode;
    //struct node *rightNode;


} node;

int main()
{

    node* rootNode = malloc(sizeof(node));

    int N;

    scanf("%d", &N);

    int n;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &n);
        if(n==0){

        }else{
            
            if(rootNode->num==0){
                rootNode->num = n;
            }else{

                rootNode->num = (rootNode->num) > n ? rootNode->num : n;
                
            }
        }
    }

    printf("%d", rootNode->num);

    free(rootNode);
    /*
    long long a = 1 << 31;
    printf("%lld", a);
    */
    return 0;
}
