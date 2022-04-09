#include <stdio.h>

void change(int* arr, int* selection, int* min){

    int change = arr[*selection];
    arr[*selection] = *min;
    *min = change;
}


int main(){

    int arr[10] = { 23,11,54,654,645,34523,78,76, 954, 345 };

    //int min = arr[0];
    

    for (int selection = 0; selection < 10; selection++)
    {

        int* min = &arr[selection];

        for (int i = selection; i < 10; i++)
        {
            if(*min> arr[i]){
                min = &arr[i];
            }
        }
        
        change(arr, &selection, min);

    }

    for (int i = 0; i < 10; i++){
        printf("%d\n", arr[i]);
    }

        return 0;
}