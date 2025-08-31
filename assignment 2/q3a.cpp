#include <iostream>
using namespace std;

int findMissingNumber(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        if (arr[i] != i + 1) {
            return i + 1; 
        }
    }
    return n; 
}
int main() {
    int n;
    cout << "Enter size of array (n-1): ";
    cin >> n;
    int arr[n];
    cout << "Enter sorted array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int missing = findMissingNumber(arr, n);
    cout << "The missing number is: " << missing << endl;

    return 0;
}
