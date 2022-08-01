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

int arr[100];

int getMax(int N){
 
    int max = 0;
    for(int j=0; j<N; j++){
         
        if(arr[j] > max)
        {
            max = arr[j];
        }
    }
    return max;
}

int main(){

    int T, N, M;
    cin >> T;
    
    //1 1 2 2 3 3 3 3 1

    for(int i=0; i<T; i++){
        
        cin >> N >> M;
        cin.get();

        int a[100];
        int idx = 0;

        for(int j=0; j<N; j++){
            
            cin >> arr[j];
        }
        
        int m = getMax(N);
        
        int flag = 0;
        int cnt = 0;

        while(1){
            int k=flag;

            for(; k<N; k++){
            
                if(arr[k]==m)
                {
                    if(k==M){
                        goto print;
                        break;
                    }else
                    {
                        
                        a[idx++] = arr[k];
                        arr[k] = 0;
                        break;

                    }
                }
                
            }

            m = getMax(N);

            if(k>=N-1){
                k=-1;
            }
            flag = ++k;
            cnt++;

        }
        
        print: cout << cnt+1 << "\n";

    }

    return 0;
}


//***풀이 1 큐***

// typedef struct Node{
//     int value;
//     int idx;
// } node;

// #define MAX_SIZE 600

// node arr[MAX_SIZE];

// int front=0;
// int rear =0;
// int size_ =0;

// void initialize(){
//     front=0;
//     rear =0;
//     size_ =0;
    
// }

// void enqueue(int idx){

//     if(rear ==MAX_SIZE-1)
//     {
//         rear = -1;
//     }
//     arr[++rear] = arr[idx];
// }


// int pick(int *front, int *max, int *size_, int *M){
    
//     for(int j=*front; j<*front+*size_; j++){
            
//         if(arr[j].value==*max)
//         {
//             if(arr[j].idx ==*M){
//                 return 1;
//             }

//             if(*front ==MAX_SIZE-1)
//             {
//                 *front = -1;
//             }

//             *front = ++j;
//             (*size_)--;
//             break;
//         }
//         else
//         {
//             enqueue(j);     
//         }       
//     }
//     return 0;
// }

// int getMax(int* front, int* size_){
    
//     int max = 0;

//     for(int j=*front; j<*front+*size_; j++){
            
//         if(arr[j].value > max)
//         {
//             max = arr[j].value;
//         }
//     }
//     return max;
// }

// //1 1 2 2 3 3 3 3 1

// int main(){
    
//     int T, N, M;

//     cin >> T;
    
//     int a[100];
//     int len = 0;

//     for(int i=0; i<T; i++){
//         cin >> N >> M;
//         cin.get();
        
//         rear = N-1;
//         int size_ = N;

//         for(int j=0; j<N; j++){
//             int n;
//             cin >> n;
//             arr[j].value = n;
//             arr[j].idx = j;
            
//         }

//         for(int k=0; k<N; k++){

//             int max = getMax(&front, &size_);
//             //cout << "max : " << max << endl;
//             int flag = pick(&front, &max, &size_, &M);
            
//             //printf("front %d size %d rear %d\n", front , size_ , rear);

//             if( flag ==1)
//             {
//                 a[len++] = k+1;
                
//                 initialize();
//                 break;
//             }
            
//         }      
//     }

//     for(int i=0; i<T; i++){
//         cout << a[i] << endl;
//     }

//     return 0;
// }