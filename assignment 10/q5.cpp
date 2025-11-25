#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
public:
   
    bool detectLoop(Node* head) {
        if (head == nullptr) return false;
        
        Node* slow = head;
        Node* fast = head;
        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;         
            fast = fast->next->next;     
            
            if (slow == fast) {
                return true;  
            }
        }
        return false;
    }
    
    Node* findLoopStart(Node* head) {
        if (head == nullptr) return nullptr;
        
        Node* slow = head;
        Node* fast = head;
        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
            
            if (slow == fast) {
                Node* ptr1 = head;
                Node* ptr2 = slow;
                
                while (ptr1 != ptr2) {
                    ptr1 = ptr1->next;
                    ptr2 = ptr2->next;
                }
                return ptr1;
            }
        }
        return nullptr;
    }
    
    void display(Node* head, int maxNodes = 10) {
        if (head == nullptr) {
            cout << "List is empty\n";
            return;
        }
        
        Node* temp = head;
        int count = 0;
        cout << "List: ";
        
        while (temp != nullptr && count < maxNodes) {
            cout << temp->data << " -> ";
            temp = temp->next;
            count++;
        }
        
        if (count == maxNodes) {
            cout << "... (loop detected)";
        } else {
            cout << "null";
        }
        cout << endl;
    }
};

int main() {
    LinkedList ll;
    int choice, n, loopPos;
    
    cout << "Enter number of nodes: ";
    cin >> n;
    
    Node* head = nullptr;
    Node* tail = nullptr;
    
    cout << "Enter node values: ";
    for (int i = 0; i < n; i++) {
        int data;
        cin >> data;
        
        Node* newNode = new Node();
        newNode->data = data;
        newNode->next = nullptr;
        
        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    do {
        cout << "\n===== Loop Detection (Floyd's Algorithm) =====\n";
        cout << "1. Detect Loop\n";
        cout << "2. Find Loop Start Node\n";
        cout << "3. Create Loop at Position\n";
        cout << "4. Display List\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1: {
                bool hasLoop = ll.detectLoop(head);
                cout << "Output: " << (hasLoop ? "true" : "false") << endl;
                break;
            }
            case 2: {
                Node* loopStart = ll.findLoopStart(head);
                if (loopStart != nullptr) {
                    cout << "Loop starts at node with value: " << loopStart->data << endl;
                } else {
                    cout << "No loop found\n";
                }
                break;
            }
            case 3: {
                cout << "Enter position to create loop (0 to " << n-1 << "): ";
                cin >> loopPos;
                
                if (loopPos < 0 || loopPos >= n) {
                    cout << "Invalid position\n";
                    break;
                }
                
                Node* loopNode = head;
                for (int i = 0; i < loopPos; i++) {
                    loopNode = loopNode->next;
                }
                
                tail->next = loopNode;
                cout << "Loop created! Last node now points to node " << loopPos << "\n";
                break;
            }
            case 4:
                ll.display(head);
                break;
        }
    } while(choice != 0);
    
    return 0;
}
