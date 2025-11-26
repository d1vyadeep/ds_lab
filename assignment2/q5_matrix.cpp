#include <iostream>
using namespace std;

void diagonalMatrix() {
    int n, i, j;
    
    cout << "\n--- diagonal matrix ---\n";
    cout << "enter size of matrix (n x n): ";
    cin >> n;
    
    int diag[n];
    
    cout << "enter diagonal elements:\n";
    for(i = 0; i < n; i++) {
        cout << "element [" << i << "][" << i << "]: ";
        cin >> diag[i];
    }
    
    cout << "\nstored array: ";
    for(i = 0; i < n; i++) {
        cout << diag[i] << " ";
    }
    
    cout << "\n\nmatrix representation:\n";
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(i == j)
                cout << diag[i] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
    
    cout << "\nspace saved: " << n*n << " - " << n << " = " << (n*n - n) << " elements\n";
    cout << "storage required: " << n << " elements only\n";
}

void tridiagonalMatrix() {
    int n, i, j, index;
    
    cout << "\n--- tri-diagonal matrix ---\n";
    cout << "enter size of matrix (n x n): ";
    cin >> n;
    
    int tri[3*n - 2];
    
    cout << "enter elements:\n";
    index = 0;
    
    for(i = 0; i < n; i++) {
        if(i > 0) {
            cout << "lower diagonal [" << i << "][" << i-1 << "]: ";
            cin >> tri[index++];
        }
        cout << "main diagonal [" << i << "][" << i << "]: ";
        cin >> tri[index++];
        if(i < n-1) {
            cout << "upper diagonal [" << i << "][" << i+1 << "]: ";
            cin >> tri[index++];
        }
    }
    
    cout << "\nstored array: ";
    for(i = 0; i < 3*n - 2; i++) {
        cout << tri[i] << " ";
    }
    
    cout << "\n\nmatrix representation:\n";
    index = 0;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(i == j || i == j-1 || i == j+1) {
                int pos = (i < j) ? (3*i + 1) : (i == j) ? (3*i - (i>0?i-1:0)) : (3*j + 2);
                if(i == 0) pos = (j == 0) ? 0 : 1;
                else if(j == i-1) pos = 3*i - 2;
                else if(j == i) pos = 3*i - 1;
                else pos = 3*i;
                cout << tri[pos] << " ";
            }
            else
                cout << "0 ";
        }
        cout << endl;
    }
    
    cout << "\nspace saved: " << n*n << " - " << (3*n-2) << " = " << (n*n - 3*n + 2) << " elements\n";
    cout << "storage required: " << (3*n-2) << " elements only\n";
}

void lowerTriangularMatrix() {
    int n, i, j, index;
    
    cout << "\n--- lower triangular matrix ---\n";
    cout << "enter size of matrix (n x n): ";
    cin >> n;
    
    int size = n * (n + 1) / 2;
    int lower[size];
    
    cout << "enter lower triangular elements (row-wise):\n";
    index = 0;
    for(i = 0; i < n; i++) {
        for(j = 0; j <= i; j++) {
            cout << "element [" << i << "][" << j << "]: ";
            cin >> lower[index++];
        }
    }
    
    cout << "\nstored array: ";
    for(i = 0; i < size; i++) {
        cout << lower[i] << " ";
    }
    
    cout << "\n\nmatrix representation:\n";
    index = 0;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(j <= i)
                cout << lower[index++] << " ";
            else
                cout << "0 ";
        }
        if(j > i) index -= (i + 1);
        cout << endl;
    }
    
    cout << "\nspace saved: " << n*n << " - " << size << " = " << (n*n - size) << " elements\n";
    cout << "storage required: " << size << " elements (n*(n+1)/2)\n";
}

void upperTriangularMatrix() {
    int n, i, j, index;
    
    cout << "\n--- upper triangular matrix ---\n";
    cout << "enter size of matrix (n x n): ";
    cin >> n;
    
    int size = n * (n + 1) / 2;
    int upper[size];
    
    cout << "enter upper triangular elements (row-wise):\n";
    index = 0;
    for(i = 0; i < n; i++) {
        for(j = i; j < n; j++) {
            cout << "element [" << i << "][" << j << "]: ";
            cin >> upper[index++];
        }
    }
    
    cout << "\nstored array: ";
    for(i = 0; i < size; i++) {
        cout << upper[i] << " ";
    }
    
    cout << "\n\nmatrix representation:\n";
    index = 0;
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(j >= i)
                cout << upper[index++] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
    
    cout << "\nspace saved: " << n*n << " - " << size << " = " << (n*n - size) << " elements\n";
    cout << "storage required: " << size << " elements (n*(n+1)/2)\n";
}

void symmetricMatrix() {
    int n, i, j, index;
    
    cout << "\n--- symmetric matrix ---\n";
    cout << "enter size of matrix (n x n): ";
    cin >> n;
    
    int size = n * (n + 1) / 2;
    int sym[size];
    
    cout << "enter lower/upper triangular elements (stored once):\n";
    index = 0;
    for(i = 0; i < n; i++) {
        for(j = 0; j <= i; j++) {
            cout << "element [" << i << "][" << j << "]: ";
            cin >> sym[index++];
        }
    }
    
    cout << "\nstored array: ";
    for(i = 0; i < size; i++) {
        cout << sym[i] << " ";
    }
    
    cout << "\n\nmatrix representation:\n";
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(j <= i) {
                index = i * (i + 1) / 2 + j;
                cout << sym[index] << " ";
            }
            else {
                index = j * (j + 1) / 2 + i;
                cout << sym[index] << " ";
            }
        }
        cout << endl;
    }
    
    cout << "\nspace saved: " << n*n << " - " << size << " = " << (n*n - size) << " elements\n";
    cout << "storage required: " << size << " elements (n*(n+1)/2)\n";
    cout << "note: element [i][j] = element [j][i]\n";
}

int main() {
    int choice;
    
    do {
        cout << "\n====== efficient matrix storage ======\n";
        cout << "1. diagonal matrix\n";
        cout << "2. tri-diagonal matrix\n";
        cout << "3. lower triangular matrix\n";
        cout << "4. upper triangular matrix\n";
        cout << "5. symmetric matrix\n";
        cout << "6. exit\n";
        cout << "enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                diagonalMatrix();
                break;
            case 2:
                tridiagonalMatrix();
                break;
            case 3:
                lowerTriangularMatrix();
                break;
            case 4:
                upperTriangularMatrix();
                break;
            case 5:
                symmetricMatrix();
                break;
            case 6:
                cout << "exiting program...\n";
                break;
            default:
                cout << "invalid choice!\n";
        }
    } while(choice != 6);
    
    return 0;
}