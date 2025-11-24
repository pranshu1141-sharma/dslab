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
    int countKey(int key) {
        int count = 0;
        Node* temp = head;
        while (temp) {
            if (temp->data == key)
                count++;
            temp = temp->next;
        }
        return count;
    }
    void deleteAllKey(int key) {
        while (head && head->data == key) {
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
        }
        Node* curr = head;
        while (curr && curr->next) {
            if (curr->next->data == key) {
                Node* toDelete = curr->next;
                curr->next = toDelete->next;
                delete toDelete;
            } else {
                curr = curr->next;
            }
        }
    }
    void displayList() {
        Node* temp = head;
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
        cout << "3. occurrences to count:\n";
        cout << "4. Exit\nChoose: ";//1->2->1->2->1->3->1
        cin >> choice;
        switch (choice) {
            case 1:
                cout << "Value: "; cin >> val;
                list.insertAtBeginning(val); break;
            case 2:
                cout << "Value: "; cin >> val;
                list.insertAtEnd(val); break;
            case 3:
                cout << "The number : ";
                cin >> key;
                cout << "Original List: ";
                list.displayList();
                count = list.countKey(key);
                cout << "Count: " << count << endl;
                list.deleteAllKey(key);
                cout << "Updated Linked List: ";
                list.displayList();
                break;
            default:
                cout << "Invalid choice!\n";
        }
    }
    return 0;
}

