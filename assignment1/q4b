#include <iostream>
using namespace std;

int main() {
    int A[100][100], B[100][100], C[100][100];
    int r1, c1, r2, c2;
        cout << "Enter rows and columns of Matrix A: ";
    cin >> r1 >> c1;
       cout << "Enter rows and columns of Matrix B: ";
    cin >> r2 >> c2;
         if (c1 != r2) {
        cout << "Matrix multiplication not possible (columns of A ≠ rows of B)." << endl;
        return 0;
    }
     cout << "Enter elements of Matrix A:\n";
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
            cin >> A[i][j];
    cout << "Enter elements of Matrix B:\n";
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
            cin >> B[i][j];
        for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            C[i][j] = 0;
            for (int k = 0; k < c1; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    cout << "Resultant Matrix (A x B):\n";
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
