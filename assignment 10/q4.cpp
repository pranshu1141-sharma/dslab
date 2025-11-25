#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    
    vector<int> nums(n);
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    map<int, int> freqMap;
    
    for (int num : nums) {
        freqMap[num]++;
    }
    
    int result = -1;
    for (int num : nums) {
        if (freqMap[num] == 1) {
            result = num;
            break;
        }
    }
    
    if (result == -1) {
        cout << "No non-repeating element found\n";
    } else {
        cout << "First non-repeating element: " << result << endl;
    }
    
    return 0;
}
