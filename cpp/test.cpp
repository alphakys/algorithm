#include <iostream>
using namespace std;

typedef struct Node {
    Node* head;
    Node* tail;
    int value;
} Node;

Node n[10];
int idx=0;

void push(int* val){

    if(idx>0){
        n[idx].value = *val;
        n[idx-1].tail = &n[idx];
        n[idx].head = &n[idx-1];
    }
    else
    {
        n[idx].value = *val;
    }
    
    idx++;
}

int main(){

    int a=10, b=11, c=12;
    
    push(&a);
    push(&b);
    push(&c);
    
    for(int i=0; i< 10; i++){
        
        printf("head : %p , tail : %p, value : %d\n", n[i].head, n[i].tail, n[i].value);

    }

    printf("0: %p, 1: %p, 2: %p", &n[0], &n[1], &n[2]);

    return 0;
}