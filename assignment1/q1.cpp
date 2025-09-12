#include <iostream>
using namespace std;

const int MAX = 100; 
int arr[MAX];        
int n = 0;           
void create() {
    cout << "Enter number of elements: ";
    cin >> n;
    if (n > MAX) {
        cout << "Size exceeds maximum limit!" << endl;
        return;
    }
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    cout << "Array created successfully.\n";
}
void display() {
    if (n == 0) {
        cout << "Array is empty.\n";
        return;
    }
    cout << "Array elements: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}
void insert() {
    if (n >= MAX) {
        cout << "Array is full. Cannot insert.\n";
        return;
    }
    int pos, val;
    cout << "Enter position (0 to " << n << "): ";
    cin >> pos;
    cout << "Enter value to insert: ";
    cin >> val;

    if (pos < 0 || pos > n) {
        cout << "Invalid position!\n";
        return;
    }
    for (int i = n; i > pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos] = val;
    n++;
    cout << "Element inserted.\n";
}
void deleteElement() {
    if (n == 0) {
        cout << "Array is empty.\n";
        return;
    }
    int pos;
    cout << "Enter position (0 to " << n - 1 << ") to delete: ";
    cin >> pos;

    if (pos < 0 || pos >= n) {
        cout << "Invalid position!\n";
        return;
    }

    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--;
    cout << "Element deleted.\n";
}
void linearSearch() {
    if (n == 0) {
        cout << "Array is empty.\n";
        return;
    }
    int key;
    cout << "Enter value to search: ";
    cin >> key;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            cout << "Value found at index " << i << endl;
            return;
        }
    }
    cout << "Value not found in array.\n";
}
int main() {
    int choice;
    do {
        cout << "\n——MENU——\n";
        cout << "1. CREATE\n";
        cout << "2. DISPLAY\n";
        cout << "3. INSERT\n";
        cout << "4. DELETE\n";
        cout << "5. LINEAR SEARCH\n";
        cout << "6. EXIT\n";
        cout << "Enter your choice (1-6): ";
        cin >> choice;

     if (choice == 1) {
    create();
     }
     else if (choice == 2) {
    display();
     }
     else if (choice == 3) {
    insert();
    }
    else if (choice == 4) {
    deleteElement();
    }
   else if (choice == 5) {
    linearSearch();
   }
   else if (choice == 6) {
    cout << "Exiting program.\n";
   }
    else {
    cout << "Invalid choice! Try again.\n";
}
        }
     while (choice != 6);
    return 0;
}
