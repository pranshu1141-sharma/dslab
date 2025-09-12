#include <iostream>
#include <cstring>
using namespace std;
#define MAX 100

class Queue {
    char arr[MAX];
    int front, rear;
public:
    Queue() { 
        front = -1; rear = -1;
        }

    bool isEmpty() { 
        return front == -1; 
        
    }
    bool isFull() { 
        return (rear + 1) % MAX == front; 
        
    }

    void enqueue(char ch) {
        if (isFull()) 
        return;
        if (isEmpty()) 
        front = 0;
        rear = (rear + 1) % MAX;
        arr[rear] = ch;
    }

    void dequeue() {
        if (isEmpty())
        return;
        if (front == rear){
             front = rear = -1;
        }
        else {
        front = (front + 1) % MAX;
        }
    }
    
    char frontElement() {
        if (isEmpty()) return '\0';
        return arr[front];
    }
};    
bool isRepeating(const string& s, char ch) {
    int count = 0;
    for (char c : s) {
        if (c == ch)
            count++;
        if (count > 1)
            return true;
    }
    return false;
}
int main(){
    string input;
    cout << "Enter characters separated by space: ";
    getline(cin, input);
    Queue q;
    string processed;
    cout << "Output: ";
    for (char ch : input) {
        if (ch == ' ') continue;
        processed.push_back(ch);
        q.enqueue(ch);
        while (!q.isEmpty() && isRepeating(processed, q.frontElement())) {
            q.dequeue();
        }

        if (q.isEmpty())
            cout << "-1 ";
        else
            cout << q.frontElement() << " ";
    }
    cout << endl;

    return 0;
}
