#include <stdio.h>
#include <iostream>
using namespace std;

typedef struct Node{

    Node* next;
    int value;

    Node(int x){
        value = x;
        next = nullptr;
    }
} Node;

class Solution{
  
  public:
    Node* head = nullptr;
    
    //Function to insert a node at the beginning of the linked list.
    void insertAtBegining(int x) {
        if( head ==nullptr ) { head = new Node(x); }
        else{
            Node* node = new Node(x);
            Node* tmp = head;
            head = node;
            head->next = tmp;

            //head->value = x;    
        }
    }
    
    //Function to insert a node at the end of the linked list.
    void insertAtEnd(int x) {
        if( head ==nullptr ) { head = new Node(x); }
        else{
            Node* node = head;
            for(; node->next !=nullptr; node = node->next){}
            node->next = new Node(x);
            
        }
    }

    void display()
    {
        Node* node = head;
        for(; node !=nullptr; node = node->next){ cout << node->value << " ";}
    }
};

int main(void){
    
    Solution *s = new Solution();
    
    s->insertAtBegining(9);
    s->insertAtEnd(5);
    s->insertAtEnd(6);
    s->insertAtBegining(2);
    s->insertAtBegining(5);
    
    
    s->display();
    
    
    
    return 0;

}
