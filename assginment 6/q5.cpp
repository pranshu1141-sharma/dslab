#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

bool isCircular(Node* head) {
    if (head == nullptr) return false;
    
    Node* temp = head->next;
    while (temp != nullptr && temp != head) {
        temp = temp->next;
    }
    return (temp == head);
}

int main() {
    Node* head1 = new Node{1, new Node{2, new Node{3, nullptr}}};
    cout << "List 1 is circular: " << (isCircular(head1) ? "YES" : "NO") << endl;
 
    Node* head2 = new Node{1, new Node{2, new Node{3, nullptr}}};
    head2->next->next->next = head2; 
    cout << "List 2 is circular: " << (isCircular(head2) ? "YES" : "NO") << endl;
    
    return 0;
}
