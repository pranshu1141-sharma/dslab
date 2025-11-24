#include <iostream>
using namespace std;

struct Node {
    char data;
    Node* prev;
    Node* next;
};

bool isPalindrome(Node* head, Node* tail) {
    while (head != tail && head->prev != tail) {
        if (head->data != tail->data) return false;
        head = head->next;
        tail = tail->prev;
    }
    return true;
}

int main() {
    Node* head = new Node{'r', nullptr, new Node{'a', nullptr, new Node{'c', nullptr, 
                  new Node{'e', nullptr, new Node{'c', nullptr, new Node{'a', nullptr, 
                  new Node{'r', nullptr, nullptr}}}}}}};
    
    head->next->prev = head;
    head->next->next->prev = head->next;
    head->next->next->next->prev = head->next->next;
    head->next->next->next->next->prev = head->next->next->next;
    head->next->next->next->next->next->prev = head->next->next->next->next;
    head->next->next->next->next->next->next->prev = head->next->next->next->next->next;
    
    Node* tail = head->next->next->next->next->next->next;
    
    cout << "Is 'racecar' palindrome: " << (isPalindrome(head, tail) ? "YES" : "NO") << endl;
    
    return 0;
}
