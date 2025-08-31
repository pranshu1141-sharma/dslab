#include <iostream>
#include <string>
using namespace std;

int main() {
    char c;
    cout<<"Enter your character: "<<endl;
    cin>>c;
    char l;
    if( c >= 'A' && c <='Z'){
        l = c+('a'-'A');
    }else{
        l=c;
    }
    cout<<"In lower:"<<l<<endl;
    return 0;
}