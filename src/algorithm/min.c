#include <stdio.h>

int main(){

    int arr[10] = { 23,11,54,654,645,34523,78,76, 954, 345 };

    int selectionArr[10] = {0, }; 
    //printf("%d", sizeof(arr));
    //int arr[N];
    int min = arr[0];
    int selection = 0;

    int pos = 0;

    for (int i = 1; i < sizeof(arr)/sizeof(int); i++)
    {   
        if(min>arr[i])
        {
            min = arr[i];
            pos = i;
            //printf("%d ii\n", i);
            
        }
        if(i==9)
        {
            selectionArr[selection++] = min;
            arr[pos] = null;
            //printf("%d dd\n", selectionArr[0]);
        }

    }






    printf("%d\n", min);
    printf("%d\n", pos);
    printf("%d\n", selectionArr[0]);
 return 0;
}