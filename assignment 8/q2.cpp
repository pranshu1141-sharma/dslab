#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

class BST {
    Node* root;
    
    Node* createNode(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
    }
    
public:
    BST() { root = nullptr; }
 
    Node* insert(Node* node, int data) {
        if (node == nullptr) {
            return createNode(data);
        }
        if (data < node->data) {
            node->left = insert(node->left, data);
        } else {
            node->right = insert(node->right, data);
        }
        return node;
    }

    bool searchRecursive(Node* node, int key) {
        if (node == nullptr) return false;
        
        if (node->data == key) return true;
        
        if (key < node->data) {
            return searchRecursive(node->left, key);
        } else {
            return searchRecursive(node->right, key);
        }
    }

    bool searchNonRecursive(int key) {
        Node* temp = root;
        while (temp != nullptr) {
            if (temp->data == key) {
                return true;
            } else if (key < temp->data) {
                temp = temp->left;
            } else {
                temp = temp->right;
            }
        }
        return false;
    }

    int findMax(Node* node) {
        if (node == nullptr) return -1;

        if (node->right == nullptr) {
            return node->data;
        }
        return findMax(node->right);
    }

    int findMin(Node* node) {
        if (node == nullptr) return -1;
        
        if (node->left == nullptr) {
            return node->data;
        }
        return findMin(node->left);
    }

    Node* findSuccessor(Node* node, int key) {
        Node* successor = nullptr;
        Node* temp = root;
        while (temp != nullptr) {
            if (temp->data == key) {
              
                if (temp->right != nullptr) {
                    successor = temp->right;
                    while (successor->left != nullptr) {
                        successor = successor->left;
                    }
                }
                return successor;
            } else if (temp->data > key) {
                successor = temp;
                temp = temp->left;
            } else {
                temp = temp->right;
            }
        }
        return successor;
    }
    
    Node* findPredecessor(Node* node, int key) {
        Node* predecessor = nullptr;
        Node* temp = root;
        
        while (temp != nullptr) {
            if (temp->data == key) {
                if (temp->left != nullptr) {
                    predecessor = temp->left;
                    while (predecessor->right != nullptr) {
                        predecessor = predecessor->right;
                    }
                }
                return predecessor;
            } else if (temp->data < key) {
                predecessor = temp;
                temp = temp->right;
            } else {
                temp = temp->left;
            }
        }
        return predecessor;
    }
 
    void inOrder(Node* node) {
        if (node == nullptr) return;
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }

    void insertValue(int data) {
        root = insert(root, data);
    }
    
    void displayInOrder() {
        cout << "In-order: ";
        inOrder(root);
        cout << endl;
    }
    
    void search(int key) {
        cout << "Search Recursive: " << (searchRecursive(root, key) ? "Found" : "Not Found") << endl;
        cout << "Search Non-Recursive: " << (searchNonRecursive(key) ? "Found" : "Not Found") << endl;
    }
    
    void findMaxMin() {
        cout << "Maximum: " << findMax(root) << endl;
        cout << "Minimum: " << findMin(root) << endl;
    }
    
    void successor(int key) {
        Node* succ = findSuccessor(root, key);
        if (succ != nullptr) {
            cout << "In-order Successor of " << key << ": " << succ->data << endl;
        } else {
            cout << "In-order Successor of " << key << ": Not Found (no successor)" << endl;
        }
    }
    
    void predecessor(int key) {
        Node* pred = findPredecessor(root, key);
        if (pred != nullptr) {
            cout << "In-order Predecessor of " << key << ": " << pred->data << endl;
        } else {
            cout << "In-order Predecessor of " << key << ": Not Found (no predecessor)" << endl;
        }
    }
};

int main() {
    BST bst;
    int choice, value;
    
    
    cout << "Building BST with values: 50, 30, 70, 20, 40, 60, 80\n";
    bst.insertValue(50);
    bst.insertValue(30);
    bst.insertValue(70);
    bst.insertValue(20);
    bst.insertValue(40);
    bst.insertValue(60);
    bst.insertValue(80);
    
    cout << "\nTree Structure:\n";
    cout << "        50\n";
    cout << "       /  \\\n";
    cout << "      30   70\n";
    cout << "     / \\   / \\\n";
    cout << "    20 40 60 80\n";
    
    bst.displayInOrder();
    
    do {
        cout << "\nBinary Search Tree Functions Menu:\n";
        cout << "1. Search (Recursive & Non-Recursive)\n";
        cout << "2. Find Maximum and Minimum\n";
        cout << "3. Find In-order Successor\n";
        cout << "4. Find In-order Predecessor\n";
        cout << "5. Insert a new value\n";
        cout << "6. Display In-order\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1: {
                cout << "Enter value to search: ";
                cin >> value;
                bst.search(value);
                break;
            }
            case 2:
                bst.findMaxMin();
                break;
            case 3: {
                cout << "Enter node value: ";
                cin >> value;
                bst.successor(value);
                break;
            }
            case 4: {
                cout << "Enter node value: ";
                cin >> value;
                bst.predecessor(value);
                break;
            }
            case 5: {
                cout << "Enter value to insert: ";
                cin >> value;
                bst.insertValue(value);
                cout << "Value inserted.\n";
                bst.displayInOrder();
                break;
            }
            case 6:
                bst.displayInOrder();
                break;
        }
    } while(choice != 0);
    
    return 0;
}
