#include <iostream>
using namespace std;

struct Triplet {
    int row;
    int col;
    int val;
};
int main() {
    int rows, cols, nonZero;
    cout << "Enter matrix dimensions (rows cols): ";
    cin >> rows >> cols;

    cout << "Enter number of non-zero elements: ";
    cin >> nonZero;
    Triplet sparse[nonZero];
    cout << "Enter row, column and value of each non-zero element:\n";
    for (int i = 0; i < nonZero; i++) {
        cin >> sparse[i].row >> sparse[i].col >> sparse[i].val;
    }
    cout << "\nThe sparse matrix in triplet form:\n";
    cout << "Row  Col  Value\n";
    cout <<rows<<"\t"<<cols<<"\t"<<nonZero<<"\n";
    for (int i = 0; i < nonZero; i++) {
        cout << sparse[i].row << "\t"
             << sparse[i].col << "\t"
             << sparse[i].val<< endl;
    }
    Triplet transpose[nonZero];
    for (int i = 0; i < nonZero; i++) {
        transpose[i].row = sparse[i].col;
        transpose[i].col = sparse[i].row;
        transpose[i].val = sparse[i].val;
    }        cout << "\nTranspose of the sparse matrix in triplet form:\n";
    cout << "Row  Col  Value\n";
    cout <<rows<<"\t"<<cols<<"\t"<<nonZero<<"\n";
    for (int i = 0; i < nonZero; i++) {
        cout << transpose[i].row <<"\t"
             << transpose[i].col << "\t"
             << transpose[i].val << endl;
    }
    return 0;
}
