#include <iostream>
using namespace std;

// Diagonal Matrix storage 
void diagonalMatrix() {
    int n;
    cout << "Enter size of diagonal matrix: ";
    cin >> n;
    int diag[n];
    cout << "Enter " << n << " diagonal elements: ";
    for (int i = 0; i < n; i++) cin >> diag[i];

    cout << "Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) cout << diag[i] << " ";
            else cout << 0 << " ";
        }
        cout << endl;
    }
}

// Tri-diagonal matrix 
void triDiagonalMatrix() {
    int n;
    cout << "Enter size of tri-diagonal matrix: ";
    cin >> n;
    int size = 3*n - 2;
    int tri[size];
    cout << "Enter " << size << " elements (lower, main, upper): ";
    for (int i = 0; i < size; i++) cin >> tri[i];

    cout << "Matrix:\n";
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i-j==1 || i==j || j-i==1) cout << tri[k++] << " ";
            else cout << 0 << " ";
        }
        cout << endl;
    }
}

// Lower triangular matrix 
void lowerTriangular() {
    int n;
    cout << "Enter size: ";
    cin >> n;
    int size = n*(n+1)/2;
    int lower[size];
    cout << "Enter " << size << " elements (row-wise): ";
    for (int i = 0; i < size; i++) cin >> lower[i];

    cout << "Matrix:\n";
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j <= i) cout << lower[k++] << " ";
            else cout << 0 << " ";
        }
        cout << endl;
    }
}

// Upper triangular matrix 
void upperTriangular() {
    int n;
    cout << "Enter size: ";
    cin >> n;
    int size = n*(n+1)/2;
    int upper[size];
    cout << "Enter " << size << " elements (row-wise upper part): ";
    for (int i = 0; i < size; i++) cin >> upper[i];

    cout << "Matrix:\n";
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j >= i) cout << upper[k++] << " ";
            else cout << 0 << " ";
        }
        cout << endl;
    }
}

// Symmetric matrix 
void symmetricMatrix() {
    int n;
    cout << "Enter size: ";
    cin >> n;
    int size = n*(n+1)/2;
    int sym[size];
    cout << "Enter " << size << " elements (lower half row-wise): ";
    for (int i = 0; i < size; i++) cin >> sym[i];

    cout << "Matrix:\n";
    int k = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j <= i) cout << sym[k++] << " ";
            else cout << sym[j*(j+1)/2 + i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int choice;
    do {
        cout << "\n--- Special Matrices ---\n";
        cout << "1. Diagonal Matrix\n";
        cout << "2. Tri-diagonal Matrix\n";
        cout << "3. Lower Triangular Matrix\n";
        cout << "4. Upper Triangular Matrix\n";
        cout << "5. Symmetric Matrix\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: diagonalMatrix(); break;
            case 2: triDiagonalMatrix(); break;
            case 3: lowerTriangular(); break;
            case 4: upperTriangular(); break;
            case 5: symmetricMatrix(); break;
        }
    } while(choice != 0);

    return 0;
}
