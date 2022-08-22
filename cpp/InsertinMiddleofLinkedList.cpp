//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node 
{
    int data;
    struct Node *next;
    
    Node(int x) {
        data = x;
        next = NULL;
    }
};

// function to display the linked list
void display(Node* head)
{
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
	cout<<endl;
}

Node* insertInMiddle(Node* head, int x);

int main()
{
    int T, n, x;
    cin>>T;
    while(T--)
    {
        cin>> n >> x;
        
        struct Node *head = new Node(x);
        struct Node *tail = head;
        
        for (int i=0; i<n-1; i++)
        {
            cin>>x;
            tail->next = new Node(x);
            tail = tail->next;
        }
        
        cin>> x;
        head = insertInMiddle(head, x);
        display(head);
    }
    return 0;
}

// } Driver Code Ends


/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

int countNode(Node* head){
    int length =0;
    Node* cnt = head;
    for(; cnt!=nullptr; cnt = cnt->next){
        length++;
    }
    return length;
}


//Function to insert a node in the middle of the linked list.
Node* insertInMiddle(Node* head, int x)
{
    int idx = countNode(head);
    if( idx%2==1 )
    {
        Node* target = head;
        
        for(int i=0; i<idx/2; i++){target = target->next;}
        Node* n = new Node(x);
        n->next = target->next;
        target->next = n;
    }else if( idx%2==0 )
    {
        Node* target = head;
        
        for(int i=0; i<(idx/2)-1; i++){target = target->next;}
        Node* n = new Node(x);
        n->next = target->next;
        target->next = n;        
    }  
    
    return head;
    
}