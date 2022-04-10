#include <stdio.h>
#include <stdlib.h>

void change(int* arr, int left, int right){

    int change = arr[left];
    arr[left] = arr[right];
    arr[right] = change;
}

void divide(int* arr, int left, int right){
    
    int mid = (right - left + 1) / 2;
   
    if (mid > 1)
    {
        divide(arr, left, mid - 1); // 0,3
        //divide(arr, mid, right);   // 4,7
    }

    if(arr[left] >arr[right]){
        
        change(arr, left, right);

        for (int i = 0; i < 8; i++){
            printf("%d ", arr[i]);
        }
    }

}

//       (0,7)
//  (0,3)       (4,7)
//(0,1)(2,3)



int main(){

    int N = 8;

    /*scanf("%d", &N);

    int* arr = malloc(sizeof(int)*N);

    for (int i = 0; i < N; i++){
        scanf("%d", &arr[i]);
    }
*/
    int arr[8] = {27, 10, 12, 20, 25, 13, 15, 22};

    //int sorted[];

    divide(arr, 0, 7);
    
    for (int i = 0; i < N; i++){
        printf("%d\n", arr[i]);
    }

/*
    for (int insert = 1; insert < N; insert++)
    {

        for (int i = insert-1; i >=0; i--)
        {
            if(arr[i]> arr[insert]){
                
                change(arr, &i, &insert);
                insert--;
                
            }
        }
        
    }

    for (int i = 0; i < N; i++){
        printf("%d\n", arr[i]);
    }
*/
    return 0;
}