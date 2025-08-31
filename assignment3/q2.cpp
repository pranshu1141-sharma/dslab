#include <iostream>
#include <string>
using namespace std;
#define MAX 100 
class CharStack {
    char arr[MAX];
    int top;
public:
    CharStack() { top = -1; }
    bool isFull() { return top == MAX - 1; }
    bool isEmpty() { return top == -1; }

    void push(char c) {
        if (!isFull()) arr[++top] = c;
        else cout << "Stack overflow\n";
    }
    char pop() {
        if (!isEmpty()) return arr[top--];
        else {
            cout << "Stack underflow\n";
            return '\0';
        }
    }
};
int main() {
    string s;
    cout << "Enter a string: ";
    getline(cin, s);
    CharStack st;
    for (int i = 0; i < s.length(); i++) {
    st.push(s[i]);
     }
    cout << "Stack contents (top to bottom): ";
    while (!st.isEmpty()) {
        cout << st.pop();
    }
    cout << endl;
    return 0;
}
