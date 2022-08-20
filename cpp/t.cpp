#include <stdio.h>
#include <iostream>
using namespace std;

typedef struct Node{
    int value;
    Node* next;
} Node;

class Solution{
  
  public:
    Node *head = nullptr;
    //Function to insert a node at the beginning of the linked list.
    Node* insertAtBegining(int x) {
        
        if( head == nullptr ){ Node n; n.value = x; head = &n;}
        else{ }
    }
    
    
    //Function to insert a node at the end of the linked list.
    Node* insertAtEnd(Node *head, int x)  {
       // Your code here
    }
};

int main(void){

    Solution s;
    cout << &s.head << endl;
    cout << &s << endl;
    if(s.head){cout << "not null";}
    else{
        cout << "null";
    }
    
    return 0;

}
