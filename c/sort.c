#include <stdio.h>

int main(){

    int N;

    scanf("%d", &N);

    int arr[N];

    for (int i = 0; i < N; i++)
    {   
        scanf("%d", &arr[i]);
    }
//5,4,3,2,1

    int itr = 1;
    for (int i = 0; i < N; i++)
    {
        int flag = arr[i];
        int order = i;
        

        for (int j = i + 1; j < N; j++)
        {

            if (flag > arr[j])
            {
                //order=0, j=1 5  4
                //order=1, j=2 5  3

                int change = arr[j];
                arr[j] = flag;
                arr[order++] = change;

                //printf("order : %d  j : %d  jarr[] : %d  oarr[] : %d \n", order, j-1, arr[j-1], arr[order]);
            }
            else
            {
                i = 0;
                itr++;
                break;
            }
        }
        //printf("%d\n", itr);
        if (itr == N)
        {
            break;
        }
    }

    for (int i = 0; i < N; i++)
    {
        printf("%d\n", arr[i]);
    }

    return 0;
}