#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

int sizeDoublyLinkedList(Node* head) {
    int count = 0;
    Node* temp = head;
    while (temp != nullptr) {
        count++;
        temp = temp->next;
    }
    return count;
}

int sizeCircularLinkedList(Node* head) {
    if (head == nullptr) return 0;
    
    int count = 1;
    Node* temp = head->next;
    while (temp != head) {
        count++;
        temp = temp->next;
    }
    return count;
}

int main() {
 
    Node* dll_head = new Node{1, nullptr, new Node{2, nullptr, new Node{3, nullptr, 
                              new Node{4, nullptr, nullptr}}}};
    dll_head->next->prev = dll_head;
    dll_head->next->next->prev = dll_head->next;
    dll_head->next->next->next->prev = dll_head->next->next;
    
    cout << "Size of Doubly Linked List: " << sizeDoublyLinkedList(dll_head) << endl;
    
    Node* cll_head = new Node{1, nullptr, new Node{2, nullptr, new Node{3, nullptr, nullptr}}};
    cll_head->next->next->next = cll_head; 
    
    cout << "Size of Circular Linked List: " << sizeCircularLinkedList(cll_head) << endl;
    
    return 0;
}
