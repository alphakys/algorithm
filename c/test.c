#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <unistd.h>

#define buff_size 5

/*
char buff[buff_size];
char *p = buff;

char* readChar(char ch){

    if(p == buff+buff_size){
        read(0, p=buff, buff_size);
        return *p++;
    }
}
*/

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
}

int readInt(){

    return 0;
}

//unsigned int a = 1 << 12; 11개 숫자 들어가면 됨

void main()
{
    int sum = 11;
    //1101
    int b = 16;
    printf("%d", 50 & 15);
    // intTobit(16);
/*
a : 40  0010 1000
a : 41  0010 1001
a : 42  0010 1010
a : 43  0010 1011
a : 44  0010 1100
a : 45  0010 1101
a : 46  0010 1110
a : 47  0010 1111
a : 48  0011 0000
a : 49  0011 0001
a : 50  0011 0010
a : 51  0011 0011
a : 52  0011 0100
a : 53  0011 0101
a : 54  0011 0110
a : 55  0011 0111
a : 56  0011 1000
a : 57  0011 1001
a : 58  0011 1010
a : 59  0011 1011
a : 60  0011 1100
a : 61  0011 1101
a : 62  0011 1110
a : 63  0011 1111
a : 64  0100 0000
a : 65  0100 0001
a : 66  0100 0010

*/

/*
    int a = 40;
    for (int i = 0; i < 27; i++)
    {
        printf("a : %d  ", a);
        intTobit(a);
        printf("\n");
        a++;
    }
*/
// 48부터 57까지 0001 0000

    // printf("%d",(1<<4) - (sum >> 0) );
    //  int len = 7;
    /*
        for (int i = 0; i < 8; i++)
        {
            int n = (bit[i]-48) << len--;
            //printf("%d\n", n);
            sum += n;
        }
    */

    //printf("%d", sum);
    // printf("%d", print(b));
    //  printf("%p %p", p, buff);
    /*
    if(p == buff+buff_size){
        read(0, p=buff, buff_size);
    }
*/
    // char c = ReadChar(); c & 16; ret = 10 * ret + (c & 15), c = ReadChar()
    // unsigned int a = 1<<31;
    // printf("%u", a);
    
    /*
    for(int i=0; i<3; i++){
        read(0, buff, buff_size);
        //printf("%p %p %p\n", buff, p, buff+buff_size);
        
    }
    */
    //fread(buff, sizeof(char), buff_size, stdin);
    
    //printf("%s", buff);



    //int i = 0;
    
    /*
    int i = 0;
    while (i<2)
    {
        if( (p+buff_size) ==buff ){
            fread(buff, sizeof(char), p = buff, stdin);
            i++;
        }
    }

    int j = 0;
    while (j < 20)
    {
        printf("%c", buff[j++]);
    }
    */
}