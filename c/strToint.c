
//str --> int array

void strToint(char* str, int* arr){

    int index = 0;
    int start = 0;
    int i = 0;
    int sum = 0;
    while (str[index] !=0)
    {

        if (str[index] == 32 || str[index] == 10)
        {
            int digit = index-start;
            int poww = digit- 1;
            //printf("index : %d  start : %d  digit : %d  poww : %d\n", index, start, digit, poww);

            if ((int)str[start] == 45)
            {
                poww = poww - 1;

                for (int j = start + 1; j < start+digit; j++)
                {

                    double n = (double)str[j] - (double)48;
                    double powNum = pow((double)10, (double)(poww));

                    sum += (int)(n * powNum);
                    poww--;
                }
                sum = sum * -1;
                   
                }
                else
                {

                    for (int j = start; j < start+digit; j++)
                    {
                    
                        double n = (double)str[j] - (double)48;
                        double powNum = pow((double)10,(double)(poww));

                        sum += (int)(n*powNum);
                        poww--;
                    
                    }

                }

                arr[i++] = sum;
                
                sum = 0;

                start = index + 1;
                index++;
                
        }
        else
        {
            index++;
        }

    }
}


int strToint(char* str){
    int start = 0;

    int sum = 0;

    for (int i = 0; str[i] != '0'; i++)
    {
        printf("%c", str[i]);
    }

    return sum;
}




// str --> int
int strToint(char* str){
    int start = 0;
    int digit = strlen(str);

    printf("%d", digit);
    int sum = 0;

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