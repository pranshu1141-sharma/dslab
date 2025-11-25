#include <iostream>
#include <queue>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

class BinaryTree {
    Node* root;
    
    Node* createNode(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
    }
    
public:
    BinaryTree() { root = nullptr; }
    
    bool checkDuplicates_Array(Node* node, int visited[], int& count) {
        if (node == nullptr) return false;
        
        for (int i = 0; i < count; i++) {
            if (visited[i] == node->data) {
                return true; 
            }
        }
        
        visited[count] = node->data;
        count++;
        
        return checkDuplicates_Array(node->left, visited, count) || 
               checkDuplicates_Array(node->right, visited, count);
    }
    
    bool hasDuplicates() {
        int visited[100]; 
        int count = 0;
        return checkDuplicates_Array(root, visited, count);
    }
    
    void collectValues(Node* node, int values[], int& count) {
        if (node == nullptr) return;
        
        values[count] = node->data;
        count++;
        
        collectValues(node->left, values, count);
        collectValues(node->right, values, count);
    }
    
    bool hasDuplicates_Sorting() {
        int values[100];
        int count = 0;
        
        collectValues(root, values, count);
        
        for (int i = 0; i < count - 1; i++) {
            for (int j = i + 1; j < count; j++) {
                if (values[i] > values[j]) {
                    int temp = values[i];
                    values[i] = values[j];
                    values[j] = temp;
                }
            }
        }
        
        for (int i = 0; i < count - 1; i++) {
            if (values[i] == values[i + 1]) {
                return true;
            }
        }
        return false;
    }
    
    void insert(int data) {
        Node* newNode = createNode(data);
        if (root == nullptr) {
            root = newNode;
            return;
        }
        
        queue<Node*> q;
        q.push(root);
        
        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            
            if (current->left == nullptr) {
                current->left = newNode;
                return;
            } else {
                q.push(current->left);
            }
            
            if (current->right == nullptr) {
                current->right = newNode;
                return;
            } else {
                q.push(current->right);
            }
        }
    }
    
    void display() {
        if (root == nullptr) {
            cout << "Tree is empty\n";
            return;
        }
        
        cout << "Tree (Level-order): ";
        queue<Node*> q;
        q.push(root);
        
        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            cout << current->data << " ";
            
            if (current->left) q.push(current->left);
            if (current->right) q.push(current->right);
        }
        cout << endl;
    }
};

int main() {
    BinaryTree bt;
    int choice, value, n;
    
    cout << "Enter number of nodes to insert: ";
    cin >> n;
    
    cout << "Enter node values: ";
    for (int i = 0; i < n; i++) {
        cin >> value;
        bt.insert(value);
    }
    
    do {
        cout << "\n===== Duplicate Detection in Binary Tree =====\n";
        cout << "1. Check Duplicates (Using Array)\n";
        cout << "2. Check Duplicates (Using Sorting)\n";
        cout << "3. Display Tree\n";
        cout << "4. Insert New Node\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1: {
                bool hasDup = bt.hasDuplicates();
                if (hasDup) {
                    cout << "Result: Duplicates Found\n";
                } else {
                    cout << "Result: No Duplicates\n";
                }
                break;
            }
            case 2: {
                bool hasDup = bt.hasDuplicates_Sorting();
                if (hasDup) {
                    cout << "Result: Duplicates Found\n";
                } else {
                    cout << "Result: No Duplicates\n";
                }
                break;
            }
            case 3:
                bt.display();
                break;
            case 4: {
                cout << "Enter value to insert: ";
                cin >> value;
                bt.insert(value);
                cout << "Node inserted\n";
                break;
            }
        }
    } while(choice != 0);
    
    return 0;
}
