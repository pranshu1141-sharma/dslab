#include <iostream>
using namespace std;
int findMissingNumber(int arr[], int n) {
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] != mid + 1) {
            if (mid == 0 || arr[mid - 1] == mid) {
                return mid + 1;  
            }
            high = mid - 1;
        } else {
            low = mid + 1;
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
