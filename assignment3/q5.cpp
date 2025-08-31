#include <iostream>
#include <string>
using namespace std;
class Stack {
    int* arr;
    int top;
    int capacity;
public:
    Stack(int size) {
        arr = new int[size];
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
    void push(int val) {
        if (!isFull())
            arr[++top] = val;
        else
            cout << "Stack Overflow\n";
    }
    int pop() {
        if (!isEmpty())
            return arr[top--];
        else {
            cout << "Stack Underflow\n";
            return -1;  
        }
    }
};
bool isOperator(char c) {
    return (c == '+' || c == '-' || c == '*' || c == '/');
}
int applyOp(int a, int b, char op) {
    switch (op) {
    case '+': return a + b;
    case '-': return a - b;
    case '*': return a * b;
    case '/': return a / b;
    default: return 0;
    }
}
int evaluatePostfix(const string& expr) {
    Stack st(expr.length());
    for (char ch : expr) {
    if (isdigit(ch)) {
            st.push(ch - '0');
        }
        else if (isOperator(ch)) {
            int val2 = st.pop();
            int val1 = st.pop();
            int res = applyOp(val1, val2, ch);
            st.push(res);
        }
    }
    return st.pop();
}
int main() {
    string postfix;
    cout << "Enter postfix expression (single digit operands, no spaces): ";
    cin >> postfix;
    int result = evaluatePostfix(postfix);
    cout << "Evaluation result: " << result << endl;
    return 0;
}
