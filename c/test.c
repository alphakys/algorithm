#include <stdio.h>

#include <unistd.h>


void printArray(char *arr, int n) {
    int i;
    for (i = 0; i < n; i++) {

        printf("%d ", arr[i]);
    }
    printf("\n");
}


void bitToint(char* str){

    int sum = 0;

    //char bit[9] = "00001111";
    int len = 7;

    for (int i = 0; i < 8; i++)
    {
        int n = (str[i]-48) << len--;
        sum += n;
    }

    printf("%d\n", sum);
}


void intTobit(int a){

    //자신의 index만큼 >> 시프트 연산을 하면 첫번째 자리에서 자신의 숫자를 구할 수 있다.
    char bit[9];

    for (int i = 7, j=0; i >= 0; i--, j++)
    {
        bit[j] = (a >> i) & 1;
    }
    
    for (int i = 0; i <8; i++)
    {
       printf("%d", bit[i]);
       if(i==3){
           printf(" ");
       }
    }
    printf("\n");
}


int sz = 1<<16;
char str[1<<16];
char *p = str;

char readChar()
{
    
    if (p == str+sz)
    {
        fread(p=str, 1, sz, stdin);
    }

    return *p++;
}

int readInt()
{
    int sum = 0;
    
    for (char c = readChar(); c & 16; c = readChar()){
        
        sum = sum * 10 + (c & 15);
    }
    
    return sum;
}


void binarySearch(){
    
}



int main()
{
    int size = 10;
    int a[10] = {1, 2, 44, 45, 77, 88, 92, 94, 97, 98};
                // 0  1   2  3    4   5   6  7   8   9
    int search = 97;

    int start = 0;
    int end = size;
    int pivot = size / 2;
    
    if(a[pivot] <search){
        printf("%d\n", a[pivot]);
        start = pivot;
        pivot = (end - start) / 2;
        // printf("answer : %d", pivot);
    }else if(a[pivot] ==search){
        printf("answer : %d", pivot);
    }





    //printf("%d", 45 & 44);
    return 0;
}
