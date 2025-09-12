#include <iostream>
using namespace std;

int main() {
    int matrix[100][100], transpose[100][100];
    int r, c;
    cout << "Enter number of rows and columns: ";
    cin >> r >> c;
    cout << "Enter the matrix:\n";
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            cin >> matrix[i][j];
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            transpose[j][i] = matrix[i][j];
    cout << "Transpose of the matrix:\n";
    for (int i = 0; i < c; i++) {
        for (int j = 0; j < r; j++) {
            cout << transpose[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
