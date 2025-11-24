#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};
class LinkedList {
private:
    Node* head;
public:
    LinkedList() : head(nullptr) {}
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }
    void reverseList() {
        Node* prev = nullptr;
        Node* curr = head;
        Node* next;
        while (curr) {
            next = curr->next;  
            curr->next = prev;   
            prev = curr;        
            curr = next;
        }
        head = prev;
        cout << "List reversed.\n";
    }
    void displayList() {
        Node* temp = head;
        cout << "Linked List: ";
        while (temp) {
            cout << temp->data;
            if (temp->next) cout << "->";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    LinkedList list;
    int choice, val, key, count;
    while (true) {
        cout << "\n--- Singly Linked List Menu ---\n";
        cout << "1. Insertion at beginning\n";
        cout << "2. Insertion at end\n";
        cout << "3. Reverse Linked list:\n";
        cout << "4. Exit\nChoose: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Value: "; cin >> val;
                list.insertAtBeginning(val); break;
            case 2:
                cout << "Value: "; cin >> val;
                list.insertAtEnd(val); break;
            case 3:
                cout << "Original ";
                list.displayList();
                list.reverseList();
                cout << "Reversed ";
                list.displayList();
                break;
            case 4:
                return 0;
                break;
            default:
                cout << "Invalid choice!\n";
        }
    }
    return 0;
}