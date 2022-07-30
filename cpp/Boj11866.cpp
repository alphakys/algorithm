#include <iostream>
using namespace std;

void pop(int *arr, int idx){

    cout << arr[idx] << ", ";
    arr[idx] = 0;
}

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

int main(){

    //풀이 2 큐
    //1 2 3 
    //4 5 6 
    //7 1 2 
    //4 5 7 
    //1 4 5
    //1 4

    int N, K;
    cin >> N >> K;

    int arr[N];

    for (int i = 1; i <= N; i++)
    {
        arr[i] = i;    
    }

    int front = 0;
    

    for (int i = 0; i < 3; i++)
    {   
        front += K;
        pop(arr, front);
    }


    cout << endl;
    print(arr, 10, sizeof(arr)/N);

    /* 풀이 1 
    int N, K;
    cin >> N >> K;

    int arr[N+1] = {0,};
    //int front = 1;
    // 1 2 3 4 5 6 7
    int len = N;
    
    cout << "<";

    for (int front = 1, cnt = 1; len > 0; front++, cnt++)
    {
        //cout << "v : " << front << " cnt : " << cnt <<"\n";
        if(arr[front]>0)
        {
            cnt--;
        }
        
        if(cnt==K && len>1)
        {
            arr[front]=1;
            cnt = 0;
            cout << front << ", ";
            len--;
        }else if(cnt==K && len==1)
        {
            cout << front;
            len--;
        }
        front = front+1 > N ? 0 : front;
            
    }

    cout << ">"; */

    return 0;

}