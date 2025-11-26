#include <iostream>
using namespace std;

void reverseArray() {
    int arr[100], n, i, temp;
    
    cout << "\n--- reverse array ---\n";
    cout << "enter number of elements: ";
    cin >> n;
    
    cout << "enter elements: ";
    for(i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << "original array: ";
    for(i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    
    for(i = 0; i < n/2; i++) {
        temp = arr[i];
        arr[i] = arr[n-1-i];
        arr[n-1-i] = temp;
    }
    
    cout << "\nreversed array: ";
    for(i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void matrixMultiplication() {
    int a[10][10], b[10][10], c[10][10];
    int r1, c1, r2, c2, i, j, k;
    
    cout << "\n--- matrix multiplication ---\n";
    cout << "enter rows and columns of first matrix: ";
    cin >> r1 >> c1;
    
    cout << "enter rows and columns of second matrix: ";
    cin >> r2 >> c2;
    
    if(c1 != r2) {
        cout << "matrix multiplication not possible!\n";
        cout << "columns of first matrix must equal rows of second matrix\n";
        return;
    }
    
    cout << "enter elements of first matrix:\n";
    for(i = 0; i < r1; i++) {
        for(j = 0; j < c1; j++) {
            cin >> a[i][j];
        }
    }
    
    cout << "enter elements of second matrix:\n";
    for(i = 0; i < r2; i++) {
        for(j = 0; j < c2; j++) {
            cin >> b[i][j];
        }
    }
    
    for(i = 0; i < r1; i++) {
        for(j = 0; j < c2; j++) {
            c[i][j] = 0;
            for(k = 0; k < c1; k++) {
                c[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    
    cout << "\nresultant matrix after multiplication:\n";
    for(i = 0; i < r1; i++) {
        for(j = 0; j < c2; j++) {
            cout << c[i][j] << " ";
        }
        cout << endl;
    }
}

void matrixTranspose() {
    int a[10][10], t[10][10];
    int r, c, i, j;
    
    cout << "\n--- matrix transpose ---\n";
    cout << "enter rows and columns of matrix: ";
    cin >> r >> c;
    
    cout << "enter elements of matrix:\n";
    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            cin >> a[i][j];
        }
    }
    
    cout << "\noriginal matrix:\n";
    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    
    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            t[j][i] = a[i][j];
        }
    }
    
    cout << "\ntranspose of matrix:\n";
    for(i = 0; i < c; i++) {
        for(j = 0; j < r; j++) {
            cout << t[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int choice;
    
    do {
        cout << "\n====== menu ======\n";
        cout << "1. reverse array\n";
        cout << "2. matrix multiplication\n";
        cout << "3. matrix transpose\n";
        cout << "4. exit\n";
        cout << "enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                reverseArray();
                break;
            case 2:
                matrixMultiplication();
                break;
            case 3:
                matrixTranspose();
                break;
            case 4:
                cout << "exiting program...\n";
                break;
            default:
                cout << "invalid choice!\n";
        }
    } while(choice != 4);
    
    return 0;
}