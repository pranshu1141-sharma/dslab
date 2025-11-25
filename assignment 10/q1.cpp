#include <iostream>
#include <vector>
#include <algorithm>
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
    
    sort(nums.begin(), nums.end());
    
    bool hasDuplicate = false;
    for (int i = 0; i < n - 1; i++) {
        if (nums[i] == nums[i + 1]) {
            hasDuplicate = true;
            break;
        }
    }
    
    cout << "Contains duplicates: " << (hasDuplicate ? "true" : "false") << endl;
    
    return 0;
}
