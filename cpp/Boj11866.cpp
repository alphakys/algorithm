#include <iostream>
using namespace std;

int main(){

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

    cout << ">";

    return 0;

}