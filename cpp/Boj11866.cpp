#include <iostream>
using namespace std;

void print(const void *arr, int size, int _sizet){

    if(_sizet>1)
    {
        arr = (int*)arr;
    }
    else
    {
        arr = (char*)arr;
    }

    if (size == 0)
    {
        //array
        for (int i = 0; i < 7; i++)
        {
            //cout << arr[i] << " " ;
        }
    }
    else
    {
        for (int i = 0; i < 7; i++)
        {
            //cout << arr[i];
        }
    }
}

int main(){

    //풀이 2 큐
    
    int N, K;
    cin >> N >> K;

    int arr[N];

    cout << sizeof(arr);
    // print(arr, 10, sizeof(arr[0]));

    for (int i = 0; i < N; i++)
    {
        arr[i] = i + 1;
    }

    for (int i = 0; i < N; i++)
    {
        arr[i] = i + 1;
    }

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