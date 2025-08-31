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
    for(int i=0;i<n;i++){
        bool notsame = true;
        for(int j=0;j<i;j++){
        if(arr[i]==arr[j]){
            notsame = false ;
            break;
        }
        }
        if (notsame){
            count++;
        }
           }
            cout<<"Number of Elements: "<<count<<endl;
    return 0;
}