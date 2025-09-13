#include <iostream>
using namespace std;

class Queue {
    int* arr;
    int front, rear, max;
public:
    Queue(int size) {
        max = size;
        arr = new int[max];
        front = rear = -1;
    }
    bool isEmpty() {
        return front == -1;
    }
    bool isFull() {
        return rear == max - 1;
    }
    void enqueue(int x) {
        if (isFull()) {
            std::cout << "Queue overflow\n";
            return;
        }
        if (isEmpty()) front = 0;
        arr[++rear] = x;
    }
    int dequeue() {
        if (isEmpty()) {
            std::cout << "Queue underflow\n";
            return -1;
        }
        int val = arr[front];
        if (front == rear) front = rear = -1;
        else front++;
        return val;
    }
    int peek() {
        if (isEmpty()) return -1;
        return arr[front];
    }
    int size() {
        return isEmpty() ? 0 : rear - front + 1;
    }
    void clear() {
        front = rear = -1;
    }
    ~Queue() {
        delete[] arr;
    }
};
class StackTwoQueues {
    Queue* q1;
    Queue* q2;
    int max;
public:
    StackTwoQueues(int size) {
        capacity = size;
        q1 = new Queue(size);
        q2 = new Queue(size);
    }
    void push(int x) {
        q2->enqueue(x);
        while (!q1->isEmpty()) {
            q2->enqueue(q1->dequeue());
        }
        std::swap(q1, q2);
    }
    void pop() {
        if (q1->isEmpty()) {
            std::cout << "Stack is empty\n";
            return;
        }
        q1->dequeue();
    }
    int top() {
        return q1->peek();
    }
    bool empty() {
        return q1->isEmpty();
    }
    ~StackTwoQueues() {
        delete q1;
        delete q2;
    }
};
class StackOneQueue {
    Queue* q;
    int max;
public:
    StackOneQueue(int size) {
        max = size;
        q = new Queue(size);
    }
    void push(int x) {
        q->enqueue(x);
        int sz = q->size();
        for (int i = 0; i < sz - 1; ++i) {
            q->enqueue(q->dequeue());
        }
    }
    void pop() {
        if (q->isEmpty()) {
            std::cout << "Stack is empty\n";
            return;
        }
        q->dequeue();
    }
    int top() {
        return q->peek();
    }
    bool empty() {
        return q->isEmpty();
    }
    ~StackOneQueue() {
        delete q;
    }
};

int main() {
    cout << "    Stack Using Two Queues\n";
    StackTwoQueues s1(10);
    s1.push(1); s1.push(2); s1.push(3);
    cout << "Top: " << s1.top() << "\n";
    s1.pop();
    cout << "Top after pop: " << s1.top() << "\n";
    cout << "\n    Stack Using One Queue \n";
    StackOneQueue s2(10);
    s2.push(10); s2.push(20); s2.push(30);
    cout << "Top: " << s2.top() << "\n";
    s2.pop();
    cout << "Top after pop: " << s2.top() << "\n";
    return 0;
}