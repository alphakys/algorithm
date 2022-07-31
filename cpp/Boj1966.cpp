#include <iostream>
using namespace std;

void print(const void *arr, int size, int _sizet){
    
    if(_sizet>1)
    {   
        int* a = (int *)arr;
        for (int i = 0; i < size; i++)
        {
            cout << a[i] << " ";
        }
    }
    else
    {
        char* arr = (char *)arr;
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
    }

    cout << "\n";    
}

int arr[200];
int* ptr_arr[100];

int front=0;
int rear =0;
int size =0;

void enqueue(int idx){

    arr[++rear] = arr[idx];
}

void pick(int *front, int *max, int *size){
    
    //cout << *front << " " << *max << " " << *size << endl;
    for(int j=*front; j<*front+*size; j++){
            
        if(arr[j]==*max)
        {
            cout << arr[j] << endl;
            ptr_arr[M];
            *front = ++j;
            (*size)--;
            break;
        }
        else
        {
            enqueue(j);     
        }
                
    }
}

int getMax(int* front, int* size){
    
    int max = 0;

    for(int j=*front; j<*front+*size; j++){
            
        if(arr[j]>max)
        {
            max = arr[j];
        }
    }
    return max;
}

int main(){
    
    int T, N, M;

    cin >> T;
    
    for(int i=0; i<T; i++){
        cin >> N >> M;
        cin.get();
        
        rear = N-1;
        size = N;

        for(int j=0; j<N; j++){
            cin >> arr[j];
            ptr_arr[j] = &arr[j];     
        }

        ptr_arr[M];

        for(int k=0; k<N; k++){

            int max = getMax(&front, &size);
            cout << "max : " << max << "\n"; 
            pick(&front, &max, &size);
            //cout << front << " " << rear << " " << size << endl;
        }

        
        print(arr, 15, 4);
              
    }

    




    return 0;
}