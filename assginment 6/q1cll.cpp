#include <iostream>
using namespace std;

struct Node{
    int data;
    Node* next;
};
class Circularlinkedlist{
    Node* tail;
    public:
    Circularlinkedlist(){
        tail=nullptr;
    }
    void insertatbeginning(int value){
        Node* newNode=new Node();
        newNode->data=value;
        if(tail==nullptr){
            newNode->next=newNode;
            tail=newNode;
        }else{
            newNode->next=tail->next;
            tail->next=newNode;
        }
    }
    void insertatend(int value){
        insertatbeginning(value);
        tail=tail->next;
    }
    void insertafter(int key, int value){
        if(tail==nullptr)return;
        Node* temp=tail->next;
        do{
            if(temp->data==key){
                Node* newNode=new Node();
                newNode->data=value;
                newNode->next=temp->next;
                temp->next=newNode;}
                if(temp==tail){
                tail=new Node;
                    return;
                }
                temp=temp->next;
            }while(temp!=tail->next);
            cout<<"Key not found\n";
    }
    bool search (int value){
        if(tail==nullptr)
        return false;
        Node* temp=tail->next;
        do{
            if(temp->data==value)
            return true;
            temp=temp->next;
        }while(temp!=tail->next);
        return false;
    }
    void display(){
        if(tail==nullptr){
            cout<<"empty\n";
            return;
        }
        Node* temp=tail->next;
        do{
            cout<<temp->data<<" ";
            temp=temp->next;
        }while(temp!=tail->next);
        cout<<"\n";
    }
    void deletenode(int value) {
        if (tail == nullptr) return;
        Node* curr = tail->next;
        Node* prev = tail;

        do {
            if (curr->data == value) {
                if (curr == prev) {
                    delete curr;
                    tail = nullptr;
                    return;
                }
                prev->next = curr->next;
                if (curr == tail)
                    tail = prev;
                if (curr == tail->next)
                    tail->next = prev->next;
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != tail->next);
        cout << "Node not found for deletion.\n";
    }
};
int main(){
    Circularlinkedlist cll;
    int choice,key,value;
    do{
       cout << "\tCircular Linked List Menu:\t";
        cout << "1. Insert at beginning\n";
        cout << "2. Insert at end\n";
        cout << "3. Insert after \n";
        cout << "4. Delete \n";
        cout << "5. Search \n";
        cout << "6. Display\n";
        cout << "0. Exit\n";
        cin >> choice;
        switch(choice) {
            case 1: cout << "Enter value: "; 
            cin >> value;
            cll.insertatbeginning(value);
            break;
            case 2: cout << "Enter value: ";
            cin >> value; 
            cll.insertatend(value); 
            break;
            case 3: cout << "Enter key: ";
            cin >> key; 
            cout << "Enter value: "; 
            cin >> value;
            cll.insertafter(key, value); 
            break;
            case 4: cout << "Enter value to delete: ";
            cin >> value;
            cll.deleteNode(value);
            break;
            case 5: cout << "Enter value to search: ";
            cin >> value;
            cout << (cll.search(value) ? "Found\n" : "Not found\n");
            break;
            case 6: cll.display();
            break;
        }
    } while(choice != 0);
    return 0;
}
