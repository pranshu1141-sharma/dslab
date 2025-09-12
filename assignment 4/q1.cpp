#include <iostream>
using namespace std;
#define size 100

class Queue{
    private:
    int queue[size];
    int front, rear;
    public:
    Queue(){
        front = -1;
        rear = -1;
    }
    void enqueue(int val){
        if(isFull()){
            cout<<"Overflow";
        }
        else{
            if(front == -1)
                front =0;
                queue[++rear]=val;
                cout<<"Enqueue : "<<val<<endl;
        }
    }
    
    void dequeue(){
        if (isEmpty()){
            cout<<"Underflow";
        }
        else{
          cout<<"Dequeue : "<<queue[front]<<endl;
          front++;
          if(front>rear){
              front=rear=-1;
          }
        }
    }
    
    bool isEmpty(){
        return (front == -1);
    }
    
    bool isFull(){
        return (rear == size-1);
    }
    
    void display(){
        if (isEmpty()){
            cout<<"Queue is empty";
        }
        else{
            cout<<"Queue: ";
            for(int i = front ; i<=rear;i++){
                cout<<queue[i]<<" ";
            }
        }
    }
    
    void peek(){
         if (isEmpty()){
            cout<<"Queue is empty";
        }
        else{
            cout<<"Front Element: "<<queue[front]<<endl;
        }
    }
};

int main(){
    Queue q;
    int ch,v;
    while(true){cout << "\n---- Queue Operations Menu ----" << endl;
    cout << "1. Enqueue" << endl;
    cout << "2. Dequeue" << endl;
    cout << "3. Check if Queue is Empty" << endl;
    cout << "4. Check if Queue is Full" << endl;
    cout << "5. Display Queue" << endl;
    cout << "6. Peek Front Element" << endl;
    cout << "7. Exit" << endl;
    cout << "Enter your choice (1-7): ";
    cin >> ch;
    switch (ch) {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> v;
            q.enqueue(v);
        break;
        case 2:
            q.dequeue();
        break;
        case 3:
            cout << (q.isEmpty() ? "Queue is empty" : "Queue is not empty") << endl;
        break;
        case 4:
            cout << (q.isFull() ? "Queue is full" : "Queue is not full") << endl;
        break;
        case 5:
            q.display();
        break;
        case 6:
            q.peek();
        break;
        case 7:
           cout << "Exiting program." << endl;
        return 0;
        default:
            cout << "Invalid choice! Please select again." << endl;
        }
        
    }
    return 0;

}
