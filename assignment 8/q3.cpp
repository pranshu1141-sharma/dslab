#include <iostream>
#include <algorithm>
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
    
    Node* insert(Node* node, int data) {
        if (node == nullptr) {
            return createNode(data);
        }
        
        if (data < node->data) {
            node->left = insert(node->left, data);
        } else if (data > node->data) {
            node->right = insert(node->right, data);
        } else {
            cout << "Duplicate value " << data << " not allowed!\n";
        }
        return node;
    }
    
    Node* findMin(Node* node) {
        while (node && node->left != nullptr) {
            node = node->left;
        }
        return node;
    }
    
    Node* deleteNode(Node* node, int key) {
        if (node == nullptr) {
            cout << "Value " << key << " not found in BST!\n";
            return node;
        }
        
        if (key < node->data) {
            node->left = deleteNode(node->left, key);
        } else if (key > node->data) {
            node->right = deleteNode(node->right, key);
        } else {
            
            if (node->left == nullptr && node->right == nullptr) {
                delete node;
                return nullptr;
            }
            
            else if (node->left == nullptr) {
                Node* temp = node->right;
                delete node;
                return temp;
            } else if (node->right == nullptr) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            
            else {
                Node* temp = findMin(node->right);
                node->data = temp->data;
                node->right = deleteNode(node->right, temp->data);
            }
        }
        return node;
    }

    int maxDepth(Node* node) {
        if (node == nullptr) return 0;
        
        int leftDepth = maxDepth(node->left);
        int rightDepth = maxDepth(node->right);
        
        return max(leftDepth, rightDepth) + 1;
    }
   
    int minDepth(Node* node) {
        if (node == nullptr) return 0;
    
        if (node->left == nullptr && node->right == nullptr) {
            return 1;
        }
     
        if (node->left == nullptr) {
            return minDepth(node->right) + 1;
        }
       
        if (node->right == nullptr) {
            return minDepth(node->left) + 1;
        }
       
        return min(minDepth(node->left), minDepth(node->right)) + 1;
    }
    
    void inOrder(Node* node) {
        if (node == nullptr) return;
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }
    
public:
    BST() { root = nullptr; }
    
    void insertValue(int data) {
        root = insert(root, data);
    }
    
    void deleteValue(int data) {
        root = deleteNode(root, data);
    }
    
    void displayMaxDepth() {
        cout << "Maximum Depth: " << maxDepth(root) << endl;
    }
    
    void displayMinDepth() {
        cout << "Minimum Depth: " << minDepth(root) << endl;
    }
    
    void displayInOrder() {
        cout << "In-order: ";
        inOrder(root);
        cout << endl;
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
    cout << "    20 40 60 80\n\n";
    
    bst.displayInOrder();
    
    do {
        cout << "\nBinary Search Tree Menu:\n";
        cout << "1. Insert an element (no duplicates)\n";
        cout << "2. Delete an element\n";
        cout << "3. Display Maximum Depth\n";
        cout << "4. Display Minimum Depth\n";
        cout << "5. Display In-order\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                bst.insertValue(value);
                bst.displayInOrder();
                break;
            case 2:
                cout << "Enter value to delete: ";
                cin >> value;
                bst.deleteValue(value);
                bst.displayInOrder();
                break;
            case 3:
                bst.displayMaxDepth();
                break;
            case 4:
                bst.displayMinDepth();
                break;
            case 5:
                bst.displayInOrder();
                break;
        }
    } while(choice != 0);
    
    return 0;
}

