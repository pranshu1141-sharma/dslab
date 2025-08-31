#include<iostream>
using namespace std;
int main(){
    int i,j,n;
    cout<<"Enter the size of matrix: ";
    cin>>n;
    int arr[n];
    cout<<"Enter elements in Diagonal matrix: ";
    for(i=0 ; i<n;i++){
        cin>>arr[i];
    }
    cout<<"\n The matrix is\n";
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if (i==j){
                cout<<arr[i]<<"\t";
            }
            else{
                cout<<"0\t";
            }
            
        }
        cout<<"\n";
    }
    return 0;
}