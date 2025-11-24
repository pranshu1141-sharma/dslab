#include <iostream>
#include <climits>
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
  
    bool isBSTUtil(Node* node, int minVal, int maxVal) {
        if (node == nullptr) return true;
        
        if (node->data <= minVal || node->data >= maxVal) {
            return false;
        }
    
        return isBSTUtil(node->left, minVal, node->data) &&
               isBSTUtil(node->right, node->data, maxVal);
    }
    
    bool isBST_MinMax() {
        return isBSTUtil(root, INT_MIN, INT_MAX);
    }
 
    bool isBSTInOrder(Node* node, int& prev) {
        if (node == nullptr) return true;
       
        if (!isBSTInOrder(node->left, prev)) {
            return false;
        }
        
        if (node->data <= prev) {
            return false;
        }
        prev = node->data;
        
        return isBSTInOrder(node->right, prev);
    }
    
    bool isBST_InOrder() {
        int prev = INT_MIN;
        return isBSTInOrder(root, prev);
    }
    
    bool isBSTDirect(Node* node, Node* left, Node* right) {
        if (node == nullptr) return true;
        
        if (left != nullptr && node->data <= left->data) {
            return false;
        }
        if (right != nullptr && node->data >= right->data) {
            return false;
        }
        
        return isBSTDirect(node->left, left, node) &&
               isBSTDirect(node->right, node, right);
    }
    
    bool isBST_Direct() {
        return isBSTDirect(root, nullptr, nullptr);
    }
    
    void insertNode(int data) {
        root = insertUtil(root, data);
    }
    
    Node* insertUtil(Node* node, int data) {
        if (node == nullptr) {
            return createNode(data);
        }
        if (data < node->data) {
            node->left = insertUtil(node->left, data);
        } else {
            node->right = insertUtil(node->right, data);
        }
        return node;
    }
    
    void createCustomTree() {
        root = createNode(10);
        root->left = createNode(5);
        root->right = createNode(15);
        root->left->left = createNode(3);
        root->left->right = createNode(7);
    }
    
    void createInvalidBST() {
        root = createNode(10);
        root->left = createNode(5);
        root->right = createNode(15);
        root->left->right = createNode(12); 
    }
    
    void inOrder(Node* node) {
        if (node == nullptr) return;
        inOrder(node->left);
        cout << node->data << " ";
        inOrder(node->right);
    }
    
    void displayInOrder() {
        cout << "In-order: ";
        inOrder(root);
        cout << endl;
    }
};

int main() {
    int choice;
    BinaryTree bt;
    
    do {
        cout << "\nBinary Tree BST Checker Menu:\n";
        cout << "1. Check if Valid BST (Min-Max Method)\n";
        cout << "2. Check if Valid BST (In-order Method)\n";
        cout << "3. Check if Valid BST (Direct Method)\n";
        cout << "4. Create Valid BST and Check\n";
        cout << "5. Create Invalid BST and Check\n";
        cout << "6. Create Custom Tree and Check\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                cout << "\nMethod 1: Min-Max Approach\n";
                bt.displayInOrder();
                cout << "Is BST: " << (bt.isBST_MinMax() ? "YES" : "NO") << endl;
                break;
                
            case 2:
                cout << "\nMethod 2: In-order Traversal Approach\n";
                bt.displayInOrder();
                cout << "Is BST: " << (bt.isBST_InOrder() ? "YES" : "NO") << endl;
                break;
                
            case 3:
                cout << "\nMethod 3: Direct Validation Approach\n";
                bt.displayInOrder();
                cout << "Is BST: " << (bt.isBST_Direct() ? "YES" : "NO") << endl;
                break;
                
            case 4: {
                cout << "\nCreating Valid BST: 50, 30, 70, 20, 40, 60, 80\n";
                BinaryTree bst1;
                bst1.insertNode(50);
                bst1.insertNode(30);
                bst1.insertNode(70);
                bst1.insertNode(20);
                bst1.insertNode(40);
                bst1.insertNode(60);
                bst1.insertNode(80);
                
                bst1.displayInOrder();
                cout << "Is BST (Method 1): " << (bst1.isBST_MinMax() ? "YES" : "NO") << endl;
                cout << "Is BST (Method 2): " << (bst1.isBST_InOrder() ? "YES" : "NO") << endl;
                cout << "Is BST (Method 3): " << (bst1.isBST_Direct() ? "YES" : "NO") << endl;
                break;
            }
            
            case 5: {
                cout << "\nCreating Invalid BST (12 in left subtree > parent 10):\n";
                BinaryTree bst2;
                bst2.createInvalidBST();
                
                bst2.displayInOrder();
                cout << "Is BST (Method 1): " << (bst2.isBST_MinMax() ? "YES" : "NO") << endl;
                cout << "Is BST (Method 2): " << (bst2.isBST_InOrder() ? "YES" : "NO") << endl;
                cout << "Is BST (Method 3): " << (bst2.isBST_Direct() ? "YES" : "NO") << endl;
                break;
            }
            
            case 6: {
                cout << "\nCreating Custom Tree: 10, 5, 15, 3, 7\n";
                BinaryTree bst3;
                bst3.createCustomTree();
                
                bst3.displayInOrder();
                cout << "Is BST (Method 1): " << (bst3.isBST_MinMax() ? "YES" : "NO") << endl;
                cout << "Is BST (Method 2): " << (bst3.isBST_InOrder() ? "YES" : "NO") << endl;
                cout << "Is BST (Method 3): " << (bst3.isBST_Direct() ? "YES" : "NO") << endl;
                break;
            }
        }
    } while(choice != 0);
    
    return 0;
}
