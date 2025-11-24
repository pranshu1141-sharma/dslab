#include <iostream>
using namespace std;

void display(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void improvedSelectionSort(int arr[], int n) {
    int left = 0, right = n - 1;
    
    while (left < right) {
        int minIdx = left;
        int maxIdx = left;
        
        for (int i = left; i <= right; i++) {
            if (arr[i] < arr[minIdx]) {
                minIdx = i;
            }
            if (arr[i] > arr[maxIdx]) {
                maxIdx = i;
            }
        }
        
        swap(arr[left], arr[minIdx]);
        
        if (maxIdx == left) {
            maxIdx = minIdx;
        }

        swap(arr[right], arr[maxIdx]);
        
        left++;
        right--;
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;
    
    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << "\nOriginal Array: ";
    display(arr, n);
    
    improvedSelectionSort(arr, n);
    
    cout << "After Improved Selection Sort: ";
    display(arr, n);
    
    return 0;
}
