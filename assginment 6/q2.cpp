#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class CircularLinkedList {
    Node* tail;
public:
    CircularLinkedList() { tail = nullptr; }

    void insertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        if (tail == nullptr) {
            tail = newNode;
            tail->next = tail; 
        } else {
            newNode->next = tail->next; 
            tail->next = newNode;       
            tail = newNode;             
        }
    }

    void displayWithHeadRepeat() {
        if (tail == nullptr) {
            cout << "List is empty.\n";
            return;
        }
        
        Node* head = tail->next; 
        Node* temp = head;
        
        do {
            cout << temp->data << "->";
            temp = temp->next;
        } while (temp != head);
        
        cout << head->data << endl;
    }
};

int main() {
    CircularLinkedList cll;

    cll.insertAtEnd(20);
    cll.insertAtEnd(100);
    cll.insertAtEnd(40);
    cll.insertAtEnd(80);
    cll.insertAtEnd(60);
    
    cout << "Circular Linked List with head repeated at end:\n";
    cll.displayWithHeadRepeat();
    
    return 0;
}
