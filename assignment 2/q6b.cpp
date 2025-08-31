#include <iostream>
using namespace std;
struct Triplet {
    int row;
    int col;
    int val;
};
void addSparseMatrices(Triplet A[], int m, Triplet B[], int n) {
    int i = 0, j = 0, k = 0;
    Triplet result[m + n];
    while (i < m && j < n) {
        if (A[i].row < B[j].row || (A[i].row == B[j].row && A[i].col < B[j].col)) {
            result[k++] = A[i++];
        } else if (B[j].row < A[i].row || (B[j].row == A[i].row && B[j].col < A[i].col)) {
            result[k++] = B[j++];
        } else {
            int summedVal = A[i].val + B[j].val;
            if (summedVal != 0) {
                result[k].row = A[i].row;
                result[k].col = A[i].col;
                result[k].val = summedVal;
                k++;
            }
            i++;
            j++;
        }
    }
    while (i < m) result[k++] = A[i++];
    while (j < n) result[k++] = B[j++];
    cout << "Resultant Sparse Matrix after Addition (Triplet form):\n";
    cout << "Row\tCol\tValue\n";
    for (int x = 0; x < k; x++) {
        cout << result[x].row << "\t" << result[x].col << "\t" << result[x].val << endl;
    }
}
int main() {
    int m, n;
    cout << "Enter number of non-zero elements in first matrix: ";
    cin >> m;
    Triplet A[m];
    cout << "Enter row, column and value of each non-zero element for matrix A:\n";
    for (int i = 0; i < m; i++) {
        cin >> A[i].row >> A[i].col >> A[i].val;
    }
    cout << "Enter number of non-zero elements in second matrix: ";
    cin >> n;
    Triplet B[n];
    cout << "Enter row, column and value of each non-zero element for matrix B:\n";
    for (int i = 0; i < n; i++) {
        cin >> B[i].row >> B[i].col >> B[i].val;
    }
    addSparseMatrices(A, m, B, n);
    return 0;
}
