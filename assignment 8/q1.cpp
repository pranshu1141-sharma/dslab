#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
};

class BinaryTree {
    Node* root;
    
public:
    BinaryTree() { root = nullptr; }
    
    // Create a new node
    Node* createNode(int data) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->left = nullptr;
        newNode->right = nullptr;
        return newNode;
    }
    
    // Insert node in binary tree
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
    
    // a. Pre-order Traversal: Root -> Left -> Right
    void preOrder(Node* node) {
        if (node == nullptr) return;
        
        cout << node->data << " ";           // Visit root
        preOrder(node->left);                // Traverse left subtree
        preOrder(node->right);               // Traverse right subtree
    }
    
    // b. In-order Traversal: Left -> Root -> Right
    void inOrder(Node* node) {
        if (node == nullptr) return;
        
        inOrder(node->left);                 // Traverse left subtree
        cout << node->data << " ";           // Visit root
        inOrder(node->right);                // Traverse right subtree
    }
    
    // c. Post-order Traversal: Left -> Right -> Root
    void postOrder(Node* node) {
        if (node == nullptr) return;
        
        postOrder(node->left);               // Traverse left subtree
        postOrder(node->right);              // Traverse right subtree
        cout << node->data << " ";           // Visit root
    }
    
    // Public wrapper functions
    void insertValue(int data) {
        root = insert(root, data);
    }
    
    void displayPreOrder() {
        cout << "Pre-order Traversal: ";
        preOrder(root);
        cout << endl;
    }
    
    void displayInOrder() {
        cout << "In-order Traversal: ";
        inOrder(root);
        cout << endl;
    }
    
    void displayPostOrder() {
        cout << "Post-order Traversal: ";
        postOrder(root);
        cout << endl;
    }
};

int main() {
    BinaryTree bt;
    int choice, value;
    
    // Build a sample tree: 50, 30, 70, 20, 40, 60, 80
    cout << "Building Binary Tree with values: 50, 30, 70, 20, 40, 60, 80\n";
    bt.insertValue(50);
    bt.insertValue(30);
    bt.insertValue(70);
    bt.insertValue(20);
    bt.insertValue(40);
    bt.insertValue(60);
    bt.insertValue(80);
    
    cout << "\nTree Structure:\n";
    cout << "        50\n";
    cout << "       /  \\\n";
    cout << "      30   70\n";
    cout << "     / \\   / \\\n";
    cout << "    20 40 60 80\n";
    
    do {
        cout << "\nBinary Tree Traversals Menu:\n";
        cout << "1. Pre-order Traversal (Root -> Left -> Right)\n";
        cout << "2. In-order Traversal (Left -> Root -> Right)\n";
        cout << "3. Post-order Traversal (Left -> Right -> Root)\n";
        cout << "4. Display All Traversals\n";
        cout << "5. Insert a new value\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                bt.displayPreOrder();
                break;
            case 2:
                bt.displayInOrder();
                break;
            case 3:
                bt.displayPostOrder();
                break;
            case 4:
                bt.displayPreOrder();
                bt.displayInOrder();
                bt.displayPostOrder();
                break;
            case 5:
                cout << "Enter value to insert: ";
                cin >> value;
                bt.insertValue(value);
                cout << "Value inserted.\n";
                break;
        }
    } while(choice != 0);
    
    return 0;
}
