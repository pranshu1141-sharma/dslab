#include<iostream>
using namespace std;
int main(){
int n;
cout<<"Enter the size of matrix: ";
cin>>n;
int arr[n][n];
cout<<"Enter elements of matrix: ";
for( int i=0;i<n;i++){
    for(int j=i;j<n;j++){
        cin>>arr[i][j];
        arr[j][i]=arr[i][j];
    }
}
cout<<"\n The matrix is:\n";
for(int i=0; i<n;i++){
    for(int j=0;j<n;j++){
      cout<<arr[i][j]<<"\t";
        
    }
      cout<<"\n";
    
    }
      return 0;
    
}
