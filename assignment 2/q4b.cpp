#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int main(){
    char str[100];
    cout<<"Enter a word:";
    cin.getline(str,100);
    int n=strlen(str);
    for (int i=0; i<n/2; i++){
        char temp;
        temp = str[i];
        str[i]= str[n-i-1];
        str[n-i-1]= temp;
    }
    cout<<"reverse of word you enter:"<<str;
    return 0;
} 
