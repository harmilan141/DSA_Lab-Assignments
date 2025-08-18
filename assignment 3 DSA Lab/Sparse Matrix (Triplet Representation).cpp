#include <iostream>
using namespace std;

struct Term {
    int row, col, val;
};

struct SparseMatrix {
    int rows, cols, terms;
    Term data[100]; // triplet form
};

// Input sparse matrix
void readSparse(SparseMatrix &s) {
    cout << "Enter rows, cols, terms: ";
    cin >> s.rows >> s.cols >> s.terms;
    cout << "Enter row, col, value for " << s.terms << " terms:\n";
    for (int i = 0; i < s.terms; i++) {
        cin >> s.data[i].row >> s.data[i].col >> s.data[i].val;
    }
}

// Print sparse matrix
void printSparse(SparseMatrix s) {
    cout << "Row Col Val\n";
    for (int i = 0; i < s.terms; i++) {
        cout << s.data[i].row << " " << s.data[i].col << " " << s.data[i].val << endl;
    }
}

// (a) Transpose
SparseMatrix transpose(SparseMatrix s) {
    SparseMatrix t;
    t.rows = s.cols;
    t.cols = s.rows;
    t.terms = s.terms;
    for (int i = 0; i < s.terms; i++) {
        t.data[i].row = s.data[i].col;
        t.data[i].col = s.data[i].row;
        t.data[i].val = s.data[i].val;
    }
    return t;
}

// (b) Addition
SparseMatrix add(SparseMatrix a, SparseMatrix b) {
    SparseMatrix c;
    if (a.rows != b.rows || a.cols != b.cols) {
        c.terms = 0; return c;
    }
    c.rows = a.rows; c.cols = a.cols;
    int i=0, j=0, k=0;
    while (i<a.terms && j<b.terms) {
        if (a.data[i].row==b.data[j].row && a.data[i].col==b.data[j].col) {
            c.data[k].row=a.data[i].row;
            c.data[k].col=a.data[i].col;
            c.data[k].val=a.data[i].val+b.data[j].val;
            i++; j++; k++;
        }
        else if (a.data[i].row<b.data[j].row || 
                (a.data[i].row==b.data[j].row && a.data[i].col<b.data[j].col)) {
            c.data[k++] = a.data[i++];
        }
        else c.data[k++] = b.data[j++];
    }
    while (i<a.terms) c.data[k++] = a.data[i++];
    while (j<b.terms) c.data[k++] = b.data[j++];
    c.terms=k;
    return c;
}

// (c) Multiplication
SparseMatrix multiply(SparseMatrix a, SparseMatrix b) {
    SparseMatrix c;
    if (a.cols != b.rows) {
        c.terms = 0; return c;
    }
    c.rows = a.rows; c.cols = b.cols; c.terms = 0;

    for (int i=0;i<a.terms;i++) {
        for (int j=0;j<b.terms;j++) {
            if (a.data[i].col == b.data[j].row) {
                int r=a.data[i].row, co=b.data[j].col;
                int val=a.data[i].val * b.data[j].val;

                // check if term already exists
                int found=-1;
                for (int k=0;k<c.terms;k++) {
                    if (c.data[k].row==r && c.data[k].col==co) {
                        found=k; break;
                    }
                }
                if (found!=-1) c.data[found].val += val;
                else {
                    c.data[c.terms].row=r;
                    c.data[c.terms].col=co;
                    c.data[c.terms].val=val;
                    c.terms++;
                }
            }
        }
    }
    return c;
}

int main() {
    SparseMatrix a,b,c;
    int choice;
    do {
        cout << "\n--- Sparse Matrix Operations ---\n";
        cout << "1. Input & Display Sparse Matrix\n";
        cout << "2. Transpose\n";
        cout << "3. Addition\n";
        cout << "4. Multiplication\n";
        cout << "0. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice) {
            case 1: readSparse(a); printSparse(a); break;
            case 2: { readSparse(a); c=transpose(a); printSparse(c); break; }
            case 3: { readSparse(a); readSparse(b); c=add(a,b); printSparse(c); break; }
            case 4: { readSparse(a); readSparse(b); c=multiply(a,b); printSparse(c); break; }
        }
    } while(choice!=0);

    return 0;
}
