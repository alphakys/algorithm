#include <iostream>
using namespace std;

int main(){

    int N, K;
    cin >> N >> K;

    int arr[N+1];
    int front = 0;
    

    for (int i = 1; i < N + 1; i++)
    {
        front += K;

        if(front>N){
            front = front - N;
        }
        cout << front << ' ';
    }

    /* for (int i = 1; i < N + 1; i++){
        cout << arr[i];
    } */
        // 1 2 3 4 5 6 7

        // cout << '<' << ' ' << K << '>';
        // cout << "강한친구 대한육군";
        return 0;

}