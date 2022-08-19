#include <stdio.h>
#include <iostream>
using namespace std;

class ClassG{
    public:
        static int get(){ return x;}
        static int x;
};

int b = 1;
    

int main(void){
    static int a = b;
    cout << a;
    
    return 0;

}
