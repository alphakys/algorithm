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



typedef struct Node{
    int value;
    
    struct node *parentNode;
    struct node *rightNode;
    struct node *leftNode;

} Node;

/*
node* constructor(int n){
    node *Node = malloc(sizeof(node));
    Node->value = n;
    return Node;
}
*/
void swap(int index_a, int index_b){
    int temp = index_a;
    index_a = index_b;
    index_b = temp;
}

int main()
{

    int N;

    scanf("%d", &N);

    int n;

    int heapArr[10];
    int index = 0;
    
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &n);
        if(n==0){

        }else{
            
            if(heapArr[1] == 0){
                heapArr[1] = n;
                index++;
            }

            if (heapArr[index]==0)
            {
                heapArr[index] = n;
            }else if(heapArr[index]<n){
                
                if(heapArr[index/2] <n){
                    heapArr[index/2] = n;
                }
            }

        }
    }

    
    /*
    printf("%p\n", constructor);
    printf("%p\n", constructor(11));
    
    node test;
    test.leftNode = constructor;
    printf("%p", test.leftNode(11));
    printf("%d", test.leftNode.value);

    node* rootNode = malloc(sizeof(node));
    
    rootNode->leftNode = malloc(sizeof(node));
    rootNode->rightNode = malloc(sizeof(node));

    int N;

    //scanf("%d", &N);

    int n;
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &n);
        if(n==0){

        }else{
            
            if(rootNode->value==0){
                rootNode->value = n;
            }
            node* parentNode = rootNode;

            int val = parentNode->value;
            if (val<=n)
            {
                parentNode->value = n;
                node* r_Node = malloc(sizeof(node));
                r_Node->value = parentNode->value;
                parentNode->rightNode = r_Node;
                
            }else{

            }
        }
    }

    printf("%d", rootNode->value);

    free(rootNode);
    */
    /*
    long long a = 1 << 31;
    printf("%lld", a);
    */
    return 0;
}

