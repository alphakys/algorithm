#include <stdio.h>
#include <stdlib.h>

int main(){
    int arr[7] = { 1, 4, 5, 9, 0, -1, 5 };

    int sum = 0;

    for (int i = 0; i < 7; i++)
    {
        sum += abs(arr[i] % 2);
    }

    printf("%d", sum);
}
