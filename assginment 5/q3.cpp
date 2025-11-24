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
    
    void printMiddle() {
        if (!head) {
            cout << "List is empty." << endl;
            return;
        }
        Node* slow = head;
        Node* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        cout << "Middle element: " << slow->data << endl;
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
        cout << "3. Find Middle:\n";
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
                list.displayList();
                list.printMiddle();
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
