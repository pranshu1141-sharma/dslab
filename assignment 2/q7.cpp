#include <iostream>
#include <string>
using namespace std;

int main() {
    int n,count=0;
    cout<<"Enter of Elements: "<<endl;
    cin>>n;
    int arr[n];
    cout<<"Enter elements:"<<endl;
    for(int i=0; i<n;i++){
        cin>>arr[i];
    }
    for(int i=0; i<n;i++){
        for(int j=i+1;j<n;j++){
            if (arr[i]>arr[j]){
                count++;
            }
        }
    }
    cout<<"Number of Inversions: "<<count<<endl;
    return 0;
}