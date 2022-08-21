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
        
        if( head == nullptr ){ head = new Node(); head->value = x; cout << "head : " << head << endl;}
        else{ 
            Node* curr = head;
            cout << "첫 : " << curr << endl;
            for(;curr->next!=nullptr; curr = curr->next)
            { 
                cout << "t: " << curr << endl; 
            }
            cout << curr <<endl;
            curr->next = new Node();
            curr->next->value = x;
            cout << curr->next <<endl;

            // nextNode = new Node();
            // cout << nextNode << endl;
            // nextNode->value = x;
            // cout << "curr : " << curr->next << endl;
            // cout << "hhh : " << head->next << endl;
            // head = curr;
            
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
    


    cout <<"헤드1 : " << s->head->value << endl;

    cout <<"헤드2 : " << s->head->next->value << endl;
    cout <<"헤드3 : " << s->head->next->next->value << endl;
    s->display();
    
    
    
    return 0;

}
