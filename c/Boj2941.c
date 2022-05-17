#include <stdio.h>
#include <string.h>

int main(){

    char str[101];
    scanf("%s", str);

    int i;
    int minus;

    int len = strlen(str);
    for (i = 0; i< len; i++)
    {

        switch (str[i])
        {
        case 45: 
            minus++;
            //printf(" minus : %d , i : %d\n", minus, i);
            break;
        case 61:
            if(str[i-1]==122 && str[i-2]==100){
                minus = minus + 2;
                //printf(" minus : %d , i : %d\n", minus, i);
                break;
            }

            minus++;
            //printf(" minus : %d , i : %d\n", minus, i);
            break;

        case 106:
            if(str[i-1] ==110 || str[i-1] ==108){
                minus++;
                //printf(" minus : %d , i : %d\n", minus, i);
                break;
            };
        
        }
        //printf("%c", str[i]);    
    }

    printf("%d\n", len-minus);
    return 0;
}

/*
- 45
= 61
a 97

č	c=
ć	c-
dž	dz=
đ	d-
lj	lj
nj	nj
š	s=
ž	z=
*/