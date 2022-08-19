#include <stdio.h>
#include <iostream>
using namespace std;

class ClassG{
    public:
        static int get(){ return x;}
        static int x;
};

int a(){
    static int a = 0;
    
    return a++;
}

int b(){
    static int a = 0;
    
    return a++;
}


int main(void){
    
    cout << a()<< endl;
    cout << a()<< endl;
    cout << a()<< endl;
    cout << b()<< endl;
    cout << b()<< endl;
    cout << b()<< endl;
    
    return 0;

}
