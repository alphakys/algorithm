#include <iostream>
using namespace std;

typedef struct Node{
    int value;
    Node* next;
}Node;

class Queue{

    private:
        int val;
        
    public:    
        Node n;

    void valSetter(int);
        //val = a;
        

    int valGetter();
        //return val; 
    

    //Queue(){cout << &val << endl;}
};

int Queue:: valGetter(){return val;}
void Queue:: valSetter(int a){val = a;}



int main(){
    
    // int i=10;
    // int j=20;

    // const int* ptr = &i;
    // cout << *ptr << endl;
    // ptr = &j;
    // cout << *ptr << endl;

    const int i=10;
    int j=20;

    int constb *ptr = &i;
    cout << *ptr << endl;
    
    //const int a;
    //a = 2;
    //const는 read-only variable이라서 처음에 할당된 값 말고 다른 값을 할당할 수 없다.

    //Queue *q = new Queue();
    Queue q;
    //q.valSetter(2);
    //cout << q.valGetter();
    //cout << "1: " << &(q->n) << endl;
    //cout << "2 : " << q << endl;

    return 0;
}