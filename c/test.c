#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

#define buff_size 5
void printArray(int *arr, int n) {
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





int readInt(char* str){
    
    int res = 0;
    
    //15랑 아스키코드상 숫자인 친구들을 (15 & 48) 연산하면 실제 숫자로 반환됨
    for(int i=0; str[i]!='\0'; i++){

        res = (res * 10) + (str[i] & 15);
    }
    return res;
}

int sz = 1<<16;

char* readChar(){

}

int main()
{

    //char sum[6] = "91235";

    //readInt(sum);

    //15랑 & 연산하면 아스키코드상 숫자인 친구들은 실제 숫자로 반환됨

    //printf("%d", 1 << 15);

    char str[sz], *p = str; read(0, str, sz);
    int cnt = 0;

    for (; *p == ' '; p++);

    for (;; p++)
    {
        //printf("%d\n", p);
        if (p == str + sz)
            read(0, p = str, sz);

        if (*p == '\n')
        {
            if(*--p==' ')
                cnt--;
            break;
        }

        if (*p == ' ')
        {
            cnt++;
        }
    }
    
    //write(1, &cnt, 4);
    printf("%d", cnt + 1);
    /*
    for (;; p++)
    {
        if (p == str + 10)
            read(0, str, 10);
        if (*p == '\n')
            break;
    }

    printf("%s", str);
*/
    // printf("%d", 16 & 32);
    /*
        intTobit(16);
        intTobit(32);
        intTobit(48);
        intTobit(47);

        printf("%d", 16 & 32);

        if (16 & 47)
        {
            printf("true");
        }
        else
        {
            printf("false");
        }
    */
    return 0;
}

