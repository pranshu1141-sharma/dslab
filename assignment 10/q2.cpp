#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n1, n2;
    cout << "Enter size of first array: ";
    cin >> n1;
    vector<int> A(n1);
    cout << "Enter elements: ";
    for (int i = 0; i < n1; i++) {
        cin >> A[i];
    }
    
    cout << "Enter size of second array: ";
    cin >> n2;
    vector<int> B(n2);
    cout << "Enter elements: ";
    for (int i = 0; i < n2; i++) {
        cin >> B[i];
    }
    
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    vector<int> common;
    int i = 0, j = 0;
    
    while (i < n1 && j < n2) {
        if (A[i] == B[j]) {
            common.push_back(A[i]);
            i++;
            j++;
        } else if (A[i] < B[j]) {
            i++;
        } else {
            j++;
        }
    }
    
    cout << "Common elements: ";
    if (common.empty()) {
        cout << "None\n";
    } else {
        for (int elem : common) {
            cout << elem << " ";
        }
        cout << endl;
    }
    
    return 0;
}
