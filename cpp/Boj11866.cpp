#include <iostream>
using namespace std;

int main(){

    int N, K;
    cin >> N >> K;

    int arr[N+1] = {0,};
    //int front = 1;
    // 1 2 3 4 5 6 7

    for (int front = 1, cnt=1; arr[front]==0; front++, cnt++)
    {
        //cout << "v : " << front << " cnt : " << cnt <<"\n";
        if(cnt==K)
        {
            if(front>N)
            {
                front = front - N;
            }
            arr[front]=1;
            cnt = 0;
            cout << front << ' ';
        }
        
        /* if (front > N)
        {
            front = front - N;
        }

        if(!arr[front])
        {    
            
            arr[front] = 1;
        }
        else
        {

        } */
        
        
    }

    
    return 0;

}