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
        cout << val << " inserted at the beginning.\n";
    }
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) temp = temp->next;
            temp->next = newNode;
        }
        cout << val << " inserted at the end.\n";
    }
    void insertBefore(int val, int beforeVal) {
        if (!head) {
            cout << "List is empty!\n";
            return;
        }
        if (head->data == beforeVal) {
            insertAtBeginning(val);
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->data != beforeVal) temp = temp->next;
        if (!temp->next) {
            cout << beforeVal << " not found!\n";
            return;
        }
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
        cout << val << " inserted before " << beforeVal << ".\n";
    }
    void insertAfter(int val, int afterVal) {
        Node* temp = head;
        while (temp && temp->data != afterVal) temp = temp->next;
        if (!temp) {
            cout << afterVal << " not found!\n";
            return;
        }
        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
        cout << val << " inserted after " << afterVal << ".\n";
    }
    void deleteFromBeginning() {
        if (!head) {
            cout << "List is empty!\n";
            return;
        }
        Node* temp = head;
        head = head->next;
        delete temp;
        cout << "Node deleted from beginning.\n";
    }
    void deleteFromEnd() {
        if (!head) {
            cout << "List is empty!\n";
            return;
        }
        if (!head->next) {
            delete head;
            head = nullptr;
            cout << "Node deleted from end.\n";
            return;
        }
        Node* temp = head;
        while (temp->next->next) temp = temp->next;
        delete temp->next;
        temp->next = nullptr;
        cout << "Node deleted from end.\n";
    }
    void deleteSpecific(int val) {
        if (!head) {
            cout << "List is empty!\n";
            return;
        }
        if (head->data == val) {
            deleteFromBeginning();
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->data != val) temp = temp->next;
        if (!temp->next) {
            cout << val << " not found!\n";
            return;
        }
        Node* toDelete = temp->next;
        temp->next = toDelete->next;
        delete toDelete;
        cout << val << " deleted from the list.\n";
    }
    void searchNode(int val) {
        Node* temp = head;
        int pos = 1;
        while (temp) {
            if (temp->data == val) {
                cout << val << " found at position " << pos << ".\n";
                return;
            }
            temp = temp->next;
            pos++;
        }
        cout << val << " not found in the list.\n";
    }
    void displayList() {
        if (!head) {
            cout << "List is empty!\n";
            return;
        }
        Node* temp = head;
        cout << "Linked List: ";
        while (temp) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
};
int main() {
    LinkedList list;
    int choice, val, key;
    while (true) {
        cout << "\n--- Singly Linked List Menu ---\n";
        cout << "1. Insertion at beginning\n";
        cout << "2. Insertion at end\n";
        cout << "3. Insert before a node\n";
        cout << "4. Insert after a node\n";
        cout << "5. Deletion from beginning\n";
        cout << "6. Deletion from end\n";
        cout << "7. Delete a specific node\n";
        cout << "8. Search for a node\n";
        cout << "9. Display list\n";
        cout << "10. Exit\nChoose: ";
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Value: "; cin >> val;
                list.insertAtBeginning(val); break;
            case 2:
                cout << "Value: "; cin >> val;
                list.insertAtEnd(val); break;
            case 3:
                cout << "Value to insert and before which value: ";
                cin >> val >> key;
                list.insertBefore(val, key); break;
            case 4:
                cout << "Value to insert and after which value: ";
                cin >> val >> key;
                list.insertAfter(val, key); break;
            case 5:
                list.deleteFromBeginning(); break;
            case 6:
                list.deleteFromEnd(); break;
            case 7:
                cout << "Value to delete: "; cin >> val;
                list.deleteSpecific(val); break;
            case 8:
                cout << "Value to search: "; cin >> val;
                list.searchNode(val); break;
            case 9:
                list.displayList(); break;
            case 10:
                cout << "Exiting.\n"; return 0;
            default:
                cout << "Invalid choice!\n";
        }
    }
}
