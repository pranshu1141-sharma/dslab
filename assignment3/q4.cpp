#include <iostream>
#include <string>
using namespace std;
class Stack {
    char* arr;
    int top;
    int capacity;
public:
    Stack(int size) {
        arr = new char[size];
        capacity = size;
        top = -1;
    }
    ~Stack() {
        delete[] arr;
    }
    bool isEmpty() {
        return top == -1;
    }
    bool isFull() {
        return top == capacity - 1;
    }
    void push(char c) {
        if (!isFull())
            arr[++top] = c;
        else
            cout << "Stack Overflow\n";
    }
    char pop() {
        if (!isEmpty())
            return arr[top--];
        else {
            cout << "Stack Underflow\n";
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
int precedence(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}
string infixToPostfix(const string& infix) {
    Stack st(infix.length());
    string postfix = "";
    for (char ch : infix) {
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9')) {
            postfix += ch;
        }
        else if (ch == '(') {
            st.push(ch);
        }
        else if (ch == ')') {
            while (!st.isEmpty() && st.peek() != '(') {
                postfix += st.pop();
            }
            if (!st.isEmpty() && st.peek() == '(')
                st.pop(); 
            else {
                cout << "Invalid expression\n";
                return "";
            }
        }
        else {
            while (!st.isEmpty() && precedence(st.peek()) >= precedence(ch)) {
                postfix += st.pop();
            }
            st.push(ch);
        }
    }
    while (!st.isEmpty()) {
        if (st.peek() == '(') {
            cout << "Invalid expression\n";
            return "";
        }
        postfix += st.pop();
    }
    return postfix;
}
int main() {
    string infixExp;
    cout << "Enter infix expression: ";
    getline(cin, infixExp);
    string postfixExp = infixToPostfix(infixExp);
    if (!postfixExp.empty())
        cout << "Postfix Expression: " << postfixExp << endl;
    return 0;
}