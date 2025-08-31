#include <iostream>
#include <string>
using namespace std;
class Stack {
    char *arr;
    int top;
    int capacity;
public:
    Stack(int size) {
        arr = new char[size];
        capacity = size;
        top = -1;
    }
    ~Stack() { delete[] arr; }
    bool isEmpty() { return top == -1; }
    bool isFull() { return top == capacity - 1; }
    void push(char c) {
        if (!isFull())
            arr[++top] = c;
        else
            cout << "Stack overflow\n";
    }
    char pop() {
        if (!isEmpty())
            return arr[top--];
        else {
            cout << "Stack underflow\n";
            return '\0';
        }
    }
    char peek() {
        if (!isEmpty())
            return arr[top];
        else
            return '\0';
    }
};
bool isMatchingPair(char opening, char closing) {
    return (opening == '(' && closing == ')') ||
           (opening == '{' && closing == '}') ||
           (opening == '[' && closing == ']');
}
bool isBalanced(const string& expr) {
    Stack st(expr.length());
    for (char ch : expr) {
        if (ch == '(' || ch == '{' || ch == '[') {
            st.push(ch);
        } else if (ch == ')' || ch == '}' || ch == ']') {
            if (st.isEmpty())
                return false;
            char top = st.pop();
            if (!isMatchingPair(top, ch))
                return false;
        }
    }
    return st.isEmpty();
}
int main() {
    string expression;
    cout << "Enter an expression: ";
    getline(cin, expression);

    if (isBalanced(expression))
        cout << "Balanced parentheses" << endl;
    else
        cout << "Unbalanced parentheses" << endl;
    return 0;
}
