#include <iostream>
using namespace std;

typedef struct Node{
    int value;
    int idx;
} node;

node arr[600];

int front=0;
int rear =0;
int size_ =0;

void initialize(){
    front=0;
    rear =0;
    size_ =0;
    
}

void enqueue(int idx){

    arr[++rear] = arr[idx];
}


int pick(int *front, int *max, int *size_, int *M){
    
    for(int j=*front; j<*front+*size_; j++){
            
        if(arr[j].value==*max)
        {
            if(arr[j].idx ==*M){
                return 1;
            }

            *front = ++j;
            (*size_)--;
            break;
        }
        else
        {
            enqueue(j);     
        }       
    }
    return 0;
}

int getMax(int* front, int* size_){
    
    int max = 0;

    for(int j=*front; j<*front+*size_; j++){
            
        if(arr[j].value > max)
        {
            max = arr[j].value;
        }
    }
    return max;
}

int main(){
    
    int T, N, M;

    cin >> T;
    
    int a[100];
    int len = 0;

    for(int i=0; i<T; i++){
        cin >> N >> M;
        cin.get();
        
        rear = N-1;
        int size_ = N;

        for(int j=0; j<N; j++){
            int n;
            cin >> n;
            arr[j].value = n;
            arr[j].idx = j;
            
        }

        for(int k=0; k<N; k++){

            int max = getMax(&front, &size_);
            //cout << "max : " << max << "\n"; 
            int flag = pick(&front, &max, &size_, &M);
            if( flag ==1)
            {
                a[len++] = k+1;
                //cout << endl << k+1 << endl;
                initialize();
                break;
            }
            
        }      
    }

    for(int i=0; i<T; i++){
        cout << a[i] << endl;
    }

    return 0;
}