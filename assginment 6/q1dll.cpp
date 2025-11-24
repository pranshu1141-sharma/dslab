#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* prev;
    Node* next;
};

class DoublyLinkedList {
    Node* head;
public:
    DoublyLinkedList() { head = nullptr; }

    void insertAtBeginning(int value) {
        Node* newNode = new Node{value, nullptr, head};
        if (head) head->prev = newNode;
        head = newNode;
    }
    void insertAtEnd(int value) {
        Node* newNode = new Node{value, nullptr, nullptr};
        if (!head) { head = newNode; return; }
        Node* temp = head;
        while (temp->next) temp = temp->next;
        temp->next = newNode;
        newNode->prev = temp;
    }
    void insertAfter(int key, int value) {
        Node* temp = head;
        while (temp && temp->data != key) temp = temp->next;
        if (!temp) { cout << "Key not found.\n"; return; }
        Node* newNode = new Node{value, temp, temp->next};
        if (temp->next) temp->next->prev = newNode;
        temp->next = newNode;
    }
    void insertBefore(int key, int value) {
        Node* temp = head;
        while (temp && temp->data != key) temp = temp->next;
        if (!temp) { cout << "Key not found.\n"; return; }
        Node* newNode = new Node{value, temp->prev, temp};
        if (temp->prev) temp->prev->next = newNode;
        else head = newNode;
        temp->prev = newNode;
    }

    void deleteNode(int value) {
        Node* temp = head;
        while (temp && temp->data != value) temp = temp->next;
        if (!temp) { cout << "Node not found.\n"; return; }
        if (temp->prev) temp->prev->next = temp->next;
        else head = temp->next;
        if (temp->next) temp->next->prev = temp->prev;
        delete temp;
    }

    bool search(int value) {
        Node* temp = head;
        while (temp) {
            if (temp->data == value) return true;
            temp = temp->next;
        }
        return false;
    }

    void display() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << "\n";
    }
};

int main() {
    DoublyLinkedList dll;
    int choice, value, key;
    do {
        cout << "\nDoubly Linked List Menu:\n";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert after a node\n";
        cout << "4. Insert before a node\n";
        cout << "5. Delete node\n";
        cout << "6. Search node\n";
        cout << "7. Display\n";
        cout << "0. Exit\n";
        cin >> choice;
        switch(choice) {
            case 1: cout << "Enter value: "; cin >> value; dll.insertAtBeginning(value); break;
            case 2: cout << "Enter value: "; cin >> value; dll.insertAtEnd(value); break;
            case 3: cout << "Enter key: "; cin >> key; cout << "Enter value: "; cin >> value; dll.insertAfter(key, value); break;
            case 4: cout << "Enter key: "; cin >> key; cout << "Enter value: "; cin >> value; dll.insertBefore(key, value); break;
            case 5: cout << "Enter value to delete: "; cin >> value; dll.deleteNode(value); break;
            case 6: cout << "Enter value to search: "; cin >> value; cout << (dll.search(value) ? "Found\n" : "Not found\n"); break;
            case 7: dll.display(); break;
        }
    } while(choice != 0);
    return 0;
}
