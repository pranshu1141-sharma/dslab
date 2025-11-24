#include <iostream>
using namespace std;

class HeapSort {
private:
    
    void maxHeapify(int arr[], int n, int i) {
        int largest = i;
        int left = 2 * i + 1;     
        int right = 2 * i + 2;    
        
        if (left < n && arr[left] > arr[largest]) {
            largest = left;
        }
        if (right < n && arr[right] > arr[largest]) {
            largest = right;
        }
        
        if (largest != i) {
            swap(arr[i], arr[largest]);
            maxHeapify(arr, n, largest);
        }
    }
    
    void minHeapify(int arr[], int n, int i) {
        int smallest = i;
        int left = 2 * i + 1;     
        int right = 2 * i + 2;     
       
        if (left < n && arr[left] < arr[smallest]) {
            smallest = left;
        }
        if (right < n && arr[right] < arr[smallest]) {
            smallest = right;
        }
        
        if (smallest != i) {
            swap(arr[i], arr[smallest]);
            minHeapify(arr, n, smallest);
        }
    }
    
public:
  
    void buildMaxHeap(int arr[], int n) {
        for (int i = n / 2 - 1; i >= 0; i--) {
            maxHeapify(arr, n, i);
        }
    }
    
    void buildMinHeap(int arr[], int n) {
        for (int i = n / 2 - 1; i >= 0; i--) {
            minHeapify(arr, n, i);
        }
    }
    
    void heapSortIncreasing(int arr[], int n) {
        buildMaxHeap(arr, n);
        
        for (int i = n - 1; i > 0; i--) {
            swap(arr[0], arr[i]);
            
            maxHeapify(arr, i, 0);
        }
    }
    
    void heapSortDecreasing(int arr[], int n) {
        buildMinHeap(arr, n);
    
        for (int i = n - 1; i > 0; i--) {
            swap(arr[0], arr[i]);
            
            minHeapify(arr, i, 0);
        }
    }
};

void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    HeapSort hs;
    int n;
    
    cout << "Enter number of elements: ";
    cin >> n;
    
    int* arr = new int[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    int choice;
    do {
        cout << "\nHeapsort Menu:\n";
        cout << "1. Heapsort - Increasing Order\n";
        cout << "2. Heapsort - Decreasing Order\n";
        cout << "3. Display Original Array\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1: {
                int* temp = new int[n];
                for (int i = 0; i < n; i++) {
                    temp[i] = arr[i];
                }
                hs.heapSortIncreasing(temp, n);
                cout << "After Heapsort (Increasing): ";
                display(temp, n);
                delete[] temp;
                break;
            }
            
            case 2: {
                int* temp = new int[n];
                for (int i = 0; i < n; i++) {
                    temp[i] = arr[i];
                }
                hs.heapSortDecreasing(temp, n);
                cout << "After Heapsort (Decreasing): ";
                display(temp, n);
                delete[] temp;
                break;
            }
            
            case 3:
                cout << "Original Array: ";
                display(arr, n);
                break;
        }
    } while(choice != 0);
    
    delete[] arr;
    return 0;
}
