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

typedef struct Node
{
    int x;
    int y;

} Node;

void mergeSort(Node* arr, int left, int right, Node* sorted, int method){
    
    int mid = (right - left + 1) / 2;
    
    if (mid >= 1)
    {
        mid = left + mid;
       
        mergeSort(arr, left, mid - 1, sorted, method);
        mergeSort(arr, mid, right, sorted, method);  
        
    }
        
    int pointer = left;

    int leftPos = left; 
    int rightPos = right; 
    int midPos = left + ((right - left + 1) / 2);

    int m = left + ((right - left + 1) / 2);
    

    for(int i=0; i<right-left+1; i++)
    {
       
        if(leftPos>=m){
            sorted[pointer++] = arr[midPos++];
        }else if(midPos>rightPos){
            sorted[pointer++] = arr[leftPos++];
        }else{
            
            if(method==1){
                if(arr[leftPos].x > arr[midPos].x){
                    sorted[pointer++] = arr[midPos++];
                
                }else{
                    sorted[pointer++] = arr[leftPos++];
                
                }
            }else{
                if(arr[leftPos].y > arr[midPos].y){
                    sorted[pointer++] = arr[midPos++];
                
                }else{
                    sorted[pointer++] = arr[leftPos++];
                
                }
            }
            

        }
        
    }
    
    for(int i=left; i<=right; i++){
        arr[i] = sorted[i];
        
    }
        
}
/*
10
1 11
1 10
1 9
1 8
1 7
1 6
1 5
1 4
1 3
1 2
*/


int main(){

    int N;

    char str[16];

    scanf("%d", &N);

    getchar();

    //Node* node = (Node *)malloc(sizeof(Node)*100000);
    Node node[100000] = {0,0};

    int positive[100001] = {0};
    int negative[100001] = {0};

    for (int i = 0; i < N; i++)
    {
        
        fgets(str, 16, stdin);
        int start = 0;
        
        for (int k = 0; k < 15; k++){
               
            if((int)str[k] ==32){
                node[i].x = strToint(start, k, str);
                
                if(strToint(start, k, str)>=0){
                    positive[strToint(start, k, str)]++;
                }else{
                    negative[strToint(start, k, str)*-1]++;
                }

                start = k+1;
            }else if((int)str[k] ==10){
                node[i].y = strToint(start, k, str);
                
                break;
            }

        }


    }


    Node* sorted = (Node *)malloc(sizeof(Node)*N);

    mergeSort(node, 0, N-1, sorted, 2);

/*
    for (int j = 0; j < N; j++)
    {
        printf("1/ %d %d\n", node[j].x, node[j].y);
    }
*/

    for (int j = -100000; j < 100001; j++)
    {   
        //printf("%d %d\n", positive[j], negative[j]);
        if(j<0 && negative[j*-1]>1){
            
            for(int i=0; i<N; i++){
                
                if(node[i].x == j){
                    memset(sorted,0,sizeof(Node)*negative[j*-1]);
                    mergeSort(node, i, i+negative[j*-1]-1, sorted, 1);
                    break;
                }
            }

        }else if(j>=0 && positive[j]>1){
            
            for(int i=0; i<N; i++){
                
                if(node[i].x == j){
                    //printf("%d", positive[j]);
                    //sizeof(Node)*positive[j]
                    memset(sorted,0,sizeof(Node)*positive[j]);
                    mergeSort(node, i, i+positive[j]-1, sorted, 1);
                    break;
                }
            }

        }
    }

    for (int j = 0; j < N; j++)
    {
        printf("%d %d\n", node[j].x, node[j].y);
    }

    free(sorted);
    //free(node);

    return 0;
}