#include <stdio.h>
#include <iostream>
using namespace std;

typedef struct Node {
    Node* head;
    Node* tail;
    int value;
} Node;

int main(){

    Node  p1;
    cout << sizeof(p1);
    return 0;

}