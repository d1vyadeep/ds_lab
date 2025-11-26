#include <iostream>
using namespace std;

int main() {
    int arr[10][10], r, c, i, j, sum;
    
    cout << "enter number of rows: ";
    cin >> r;
    
    cout << "enter number of columns: ";
    cin >> c;
    
    cout << "enter elements of matrix:\n";
    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            cin >> arr[i][j];
        }
    }
    
    cout << "\nmatrix:\n";
    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    
    cout << "\nsum of each row:\n";
    for(i = 0; i < r; i++) {
        sum = 0;
        for(j = 0; j < c; j++) {
            sum += arr[i][j];
        }
        cout << "row " << i+1 << " = " << sum << endl;
    }
    
    cout << "\nsum of each column:\n";
    for(j = 0; j < c; j++) {
        sum = 0;
        for(i = 0; i < r; i++) {
            sum += arr[i][j];
        }
        cout << "column " << j+1 << " = " << sum << endl;
    }
    
    return 0;
}