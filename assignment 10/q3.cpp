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
    
    cout << "Frequency Count:\n";
    int i = 0;
    while (i < n) {
        int count = 1;
        int current = nums[i];
        
        while (i + 1 < n && nums[i + 1] == current) {
            count++;
            i++;
        }
        
        cout << current << " → " << count << " time" 
             << (count > 1 ? "s" : "") << "\n";
        i++;
    }
    
    return 0;
}
