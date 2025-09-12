#include <iostream>
using namespace std;
#define max 100

class Queue{
    int queue[max];
    int front,rear;
    public:
    Queue(){
        front = -1;
        rear = -1;
    }
    bool isEmpty() {
        return front == -1;
    }

    bool isFull() {
        return rear == max - 1;
    }
    
    void enqueue(int val){
        if(isFull()){
            cout<<"Overflow\n";
            return;
        }
        if(isEmpty()){
            front=0;
        }
        queue[++rear]=val;
    }
    
    int dequeue(){
        if(isEmpty()){
            cout<<"Underflow\n";
            return -1;
        }
         int val = queue[front];
        if (front == rear)
            front = rear = -1;
        else
            front++;
        return val;
    }
    
    int size(){
        if(isEmpty()){
            return 0;
        }
        return rear-front+1;
    }
    
    void display(){
        if(isEmpty()){
            cout<<"Queue is Empty\n";
            return;
        }
            for(int i=front;i<=rear;i++){
                cout<<queue[i]<<" ";
            }
            cout<<endl;
    }
    
    void interleave(){
        int n = size();
        
        int half = n / 2;
        int temp[max];
        int idx = 0;

        for (int i = 0; i < half; i++) {
            temp[idx++] = queue[front + i];
            temp[idx++] = queue[front + half + i];
        }

        for (int i = 0; i < n; i++) {
            queue[front + i] = temp[i];
        }
    }
};
int main(){
    Queue q;
    int n;
    cout<<"Lenght of Array:";
    cin>>n;
    if (n % 2 != 0 || n > max) {
        cout << "Please enter an even number <= " << max << endl;
        return 1;
    }
    cout<<"Enter element: ";
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
        q.enqueue(arr[i]);
    }
    cout << "Original queue: ";
    q.display();
    q.interleave();
    cout << "Interleaved queue: ";
    q.display();
    return 0;
}
