#include <iostream>
#include <vector>
using namespace std;

class MaxPriorityQueue {
private:
    vector<int> heap;
    
    int parent(int i) { return (i - 1) / 2; }
    
    int leftChild(int i) { return 2 * i + 1; }
    
    int rightChild(int i) { return 2 * i + 2; }
    
    void heapifyUp(int i) {
        while (i > 0 && heap[parent(i)] < heap[i]) {
            swap(heap[parent(i)], heap[i]);
            i = parent(i);
        }
    }
    
    void heapifyDown(int i) {
        int maxIndex = i;
        int left = leftChild(i);
        int right = rightChild(i);
        
        if (left < heap.size() && heap[left] > heap[maxIndex]) {
            maxIndex = left;
        }
        if (right < heap.size() && heap[right] > heap[maxIndex]) {
            maxIndex = right;
        }
        
        if (i != maxIndex) {
            swap(heap[i], heap[maxIndex]);
            heapifyDown(maxIndex);
        }
    }
    
public:
 
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
        cout << "Inserted " << value << " into Max Priority Queue\n";
    }
    
    
    int getMax() {
        if (heap.empty()) {
            cout << "Queue is empty!\n";
            return -1;
        }
        return heap[0];
    }
    
    int extractMax() {
        if (heap.empty()) {
            cout << "Queue is empty!\n";
            return -1;
        }
        
        int maxValue = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        
        if (!heap.empty()) {
            heapifyDown(0);
        }
        
        return maxValue;
    }
    
    bool isEmpty() {
        return heap.empty();
    }
    
    int size() {
        return heap.size();
    }
    
    void display() {
        if (heap.empty()) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "Max Priority Queue: ";
        for (int val : heap) {
            cout << val << " ";
        }
        cout << endl;
    }
};

class MinPriorityQueue {
private:
    vector<int> heap;
    
    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }
    
    void heapifyUp(int i) {
        while (i > 0 && heap[parent(i)] > heap[i]) {
            swap(heap[parent(i)], heap[i]);
            i = parent(i);
        }
    }
    
    void heapifyDown(int i) {
        int minIndex = i;
        int left = leftChild(i);
        int right = rightChild(i);
        
        if (left < heap.size() && heap[left] < heap[minIndex]) {
            minIndex = left;
        }
        if (right < heap.size() && heap[right] < heap[minIndex]) {
            minIndex = right;
        }
        
        if (i != minIndex) {
            swap(heap[i], heap[minIndex]);
            heapifyDown(minIndex);
        }
    }
    
public:
    void insert(int value) {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
        cout << "Inserted " << value << " into Min Priority Queue\n";
    }
    
    int getMin() {
        if (heap.empty()) {
            cout << "Queue is empty!\n";
            return -1;
        }
        return heap[0];
    }
    
    int extractMin() {
        if (heap.empty()) {
            cout << "Queue is empty!\n";
            return -1;
        }
        
        int minValue = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        
        if (!heap.empty()) {
            heapifyDown(0);
        }
        
        return minValue;
    }
    
    bool isEmpty() {
        return heap.empty();
    }
    
    int size() {
        return heap.size();
    }
    
    void display() {
        if (heap.empty()) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "Min Priority Queue: ";
        for (int val : heap) {
            cout << val << " ";
        }
        cout << endl;
    }
};

int main() {
    int choice, queueType, value;
    MaxPriorityQueue maxPQ;
    MinPriorityQueue minPQ;
    
    cout << "Select Priority Queue Type:\n";
    cout << "1. Max Priority Queue (Higher value = Higher priority)\n";
    cout << "2. Min Priority Queue (Lower value = Higher priority)\n";
    cout << "Enter choice: ";
    cin >> queueType;
    
    do {
        cout << "\nPriority Queue Operations:\n";
        cout << "1. Insert\n";
        cout << "2. Get Highest Priority Element (Peek)\n";
        cout << "3. Extract Highest Priority Element\n";
        cout << "4. Display Queue\n";
        cout << "5. Check if Empty\n";
        cout << "6. Get Size\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        if (queueType == 1) {
            switch(choice) {
                case 1:
                    cout << "Enter value: ";
                    cin >> value;
                    maxPQ.insert(value);
                    break;
                case 2:
                    cout << "Highest Priority Element: " << maxPQ.getMax() << endl;
                    break;
                case 3:
                    cout << "Extracted: " << maxPQ.extractMax() << endl;
                    break;
                case 4:
                    maxPQ.display();
                    break;
                case 5:
                    cout << "Is Empty: " << (maxPQ.isEmpty() ? "YES" : "NO") << endl;
                    break;
                case 6:
                    cout << "Size: " << maxPQ.size() << endl;
                    break;
            }
        } else if (queueType == 2) {
            switch(choice) {
                case 1:
                    cout << "Enter value: ";
                    cin >> value;
                    minPQ.insert(value);
                    break;
                case 2:
                    cout << "Highest Priority Element: " << minPQ.getMin() << endl;
                    break;
                case 3:
                    cout << "Extracted: " << minPQ.extractMin() << endl;
                    break;
                case 4:
                    minPQ.display();
                    break;
                case 5:
                    cout << "Is Empty: " << (minPQ.isEmpty() ? "YES" : "NO") << endl;
                    break;
                case 6:
                    cout << "Size: " << minPQ.size() << endl;
                    break;
            }
        }
    } while(choice != 0);
    
    return 0;
}
