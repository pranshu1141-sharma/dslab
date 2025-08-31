#include <iostream>
#include <string>
#include <cstring>
using namespace std;
int main(){
    char str[100],str1[100];
    cout<<"Enter a word:";
    cin>>str;
    int n=strlen(str);
    int j=0;
    for (int i=0; i<n; i++){
        char ch= str[i];
        if( ch >= 'A' && ch <='Z'){
        ch = ch+('a'-'A');
    }
       if(ch != 'a' && ch != 'e' && ch!= 'i' && ch!= 'o' && ch!= 'u'){
           str1[j]=str[i];
           j++;
       }
    }
    cout<<"without vowel:"<<str1;
    return 0;
} 
