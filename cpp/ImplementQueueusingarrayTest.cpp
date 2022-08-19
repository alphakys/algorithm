#include <iostream>
using namespace std;

typedef struct Node{
    int value;
    Node* next;
}Node;

class Queue{
    private:
        
        int index = 0;
    
    public:   
        Node n[100]; 
        void push(int);
        int pop();
        
};

void Queue:: push(int x)
{
    if(index ==0){ n[index++].value = x; }
    else{ n[index].value = x; n[index-1].next = &n[index]; index++;}
    
}

//Function to pop front element from the queue.
int Queue :: pop()
{
    return 0;
}


int main(){
    
    Queue *q = new Queue();
    int Q;
    cin >> Q;

    while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            q->push(a);
        }else if(QueryType==2){
            cout<<q->pop()<<" ";

        }
    }

    for (int i = 0; i < 5; i++)
    {
        cout << q->n[i].value;
    }
    
    return 0;
}

