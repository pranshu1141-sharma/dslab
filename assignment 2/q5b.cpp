#include<iostream>
using namespace std;
int main(){
int i,j,n,size,k=0;
cout<<"Enter the size of matrix: ";
cin>>n;
size= 3*n-2;
int arr[size];
cout<<"Enter elements in Tri-Diagonal matrix: ";
for( i=0;i<size;i++){
    cin>>arr[i];
}
cout<<"\n The matrix is:\n";
for(i=0; i<n;i++){
    for(j=0;j<n;j++){
        if(i-j==-1||i-j==0||i-j==1){
            cout<<arr[k]<<"\t";
            k++;
        }
        else{
            cout<<"0\t";
        }
    }
   cout<<"\n";
}
return 0;}