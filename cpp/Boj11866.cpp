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

int main(){

    //풀이 2 큐
    
    int N, K;
    cin >> N >> K;

    int arr[N];

    for (int i = 0; i < N; i++)
    {
        arr[i] = i + 1;
        //cout << "arr : " << arr[i] << " i : " << i << endl; 
    }

    // for (int i = 0; i < N; i++)
    // {
    //     arr[i] = i + 1;
    // }

    print(arr, N, sizeof(arr)/N);

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