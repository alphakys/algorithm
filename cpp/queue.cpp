//
// Created by alpha on 24. 2. 21.
//
#define Q_LIMIT 4

class Queue
{

private:

    int front = 0;
    int rear = 0;
    int arr[Q_LIMIT] = {0,};

public:

    void enqueue(int val){

        if (rear == Q_LIMIT){
            cout << "queue is full";

        }else{
            arr[rear++] = val;
        }
        return;
    }

    bool is_empty(){
        if (rear == front){
            cout << "queue is empty\n";
            return true;
        }
        else{
            return false;
        }
    }

    void dequeue(){

        if(is_empty() == true){
            return;
        }

        cout << "dequeue : " << arr[front] << "\n-------\n";

        for (int i = front+1; i < rear; ++i) {
            arr[i-1] = arr[i];
        }
        rear--;
    }

    void display(){
        cout << "display" << "\n";

        if(is_empty()){
            return;
        }

        for (int i = front; i < rear; i++) {
            cout << arr[i] << "\n";
        }
        cout << "---------\n";
    }

    void q_front(){
        cout << "front\n";

        if(is_empty()){
            return;
        }

        cout << arr[front] << "\n----\n";

    }

};

int main(){

}