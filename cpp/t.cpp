#include <stdio.h>
#include <iostream>
using namespace std;

typedef struct Node{

    Node* next;
    int value;
} Node;

class Solution{
  
  public:
    Node* head = nullptr;
    
    //Function to insert a node at the beginning of the linked list.
    void insertAtBegining(int x) {
        
        if( head == nullptr ){ head = new Node(); head->value = x; }
        else{ 
            Node* curr = head;
            for(;curr->next!=nullptr; curr = curr->next){}
            
            curr->next = new Node();
            curr->next->value = x;
            
        }
    }
    
    //Function to insert a node at the end of the linked list.
    void insertAtEnd(Node *head, int x)  {
        
    }

    void display()
    {
        Node* curr = head;
        for(; curr!=nullptr; curr = curr->next)
        {
            cout << curr->value << " ";
        }
      
    }
};

int main(void){
    
    Solution *s = new Solution();
    //cout <<1;
    s->insertAtBegining(1);
    s->insertAtBegining(2);
    s->insertAtBegining(3);
    
    s->display();
    
    
    
    return 0;

}
