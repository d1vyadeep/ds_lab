#include <iostream>
using namespace std;

struct Triplet {
    int row;
    int col;
    int value;
};

void displayTriplet(Triplet t[], int nonZero) {
    cout << "\nrow\tcol\tvalue\n";
    cout << "-------------------\n";
    for(int i = 0; i <= nonZero; i++) {
        cout << t[i].row << "\t" << t[i].col << "\t" << t[i].value << endl;
    }
}

void displayMatrix(Triplet t[], int nonZero) {
    int rows = t[0].row;
    int cols = t[0].col;
    
    cout << "\nmatrix representation:\n";
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            int found = 0;
            for(int k = 1; k <= nonZero; k++) {
                if(t[k].row == i && t[k].col == j) {
                    cout << t[k].value << " ";
                    found = 1;
                    break;
                }
            }
            if(!found) cout << "0 ";
        }
        cout << endl;
    }
}

void inputSparseMatrix(Triplet t[], int &nonZero) {
    int rows, cols, i, j, value;
    
    cout << "enter number of rows: ";
    cin >> rows;
    cout << "enter number of columns: ";
    cin >> cols;
    
    t[0].row = rows;
    t[0].col = cols;
    
    cout << "enter number of non-zero elements: ";
    cin >> nonZero;
    
    t[0].value = nonZero;
    
    cout << "enter non-zero elements (row col value):\n";
    for(int k = 1; k <= nonZero; k++) {
        cout << "element " << k << ": ";
        cin >> t[k].row >> t[k].col >> t[k].value;
    }
}

void transposeMatrix(Triplet t[], int nonZero, Triplet result[]) {
    int rows = t[0].row;
    int cols = t[0].col;
    
    result[0].row = cols;
    result[0].col = rows;
    result[0].value = nonZero;
    
    int k = 1;
    for(int i = 0; i < cols; i++) {
        for(int j = 1; j <= nonZero; j++) {
            if(t[j].col == i) {
                result[k].row = t[j].col;
                result[k].col = t[j].row;
                result[k].value = t[j].value;
                k++;
            }
        }
    }
}

void addMatrices(Triplet a[], int nonZeroA, Triplet b[], int nonZeroB, Triplet result[], int &nonZeroResult) {
    if(a[0].row != b[0].row || a[0].col != b[0].col) {
        cout << "matrix addition not possible! dimensions must be same.\n";
        nonZeroResult = 0;
        return;
    }
    
    result[0].row = a[0].row;
    result[0].col = a[0].col;
    
    int i = 1, j = 1, k = 1;
    
    while(i <= nonZeroA && j <= nonZeroB) {
        if(a[i].row < b[j].row || (a[i].row == b[j].row && a[i].col < b[j].col)) {
            result[k] = a[i];
            i++;
            k++;
        }
        else if(a[i].row > b[j].row || (a[i].row == b[j].row && a[i].col > b[j].col)) {
            result[k] = b[j];
            j++;
            k++;
        }
        else {
            result[k].row = a[i].row;
            result[k].col = a[i].col;
            result[k].value = a[i].value + b[j].value;
            if(result[k].value != 0) k++;
            i++;
            j++;
        }
    }
    
    while(i <= nonZeroA) {
        result[k] = a[i];
        i++;
        k++;
    }
    
    while(j <= nonZeroB) {
        result[k] = b[j];
        j++;
        k++;
    }
    
    nonZeroResult = k - 1;
    result[0].value = nonZeroResult;
}

void multiplyMatrices(Triplet a[], int nonZeroA, Triplet b[], int nonZeroB, Triplet result[], int &nonZeroResult) {
    if(a[0].col != b[0].row) {
        cout << "matrix multiplication not possible!\n";
        cout << "columns of first matrix must equal rows of second matrix.\n";
        nonZeroResult = 0;
        return;
    }
    
    result[0].row = a[0].row;
    result[0].col = b[0].col;
    
    int temp[10][10] = {0};
    
    for(int i = 1; i <= nonZeroA; i++) {
        for(int j = 1; j <= nonZeroB; j++) {
            if(a[i].col == b[j].row) {
                temp[a[i].row][b[j].col] += a[i].value * b[j].value;
            }
        }
    }
    
    int k = 1;
    for(int i = 0; i < a[0].row; i++) {
        for(int j = 0; j < b[0].col; j++) {
            if(temp[i][j] != 0) {
                result[k].row = i;
                result[k].col = j;
                result[k].value = temp[i][j];
                k++;
            }
        }
    }
    
    nonZeroResult = k - 1;
    result[0].value = nonZeroResult;
}

int main() {
    Triplet mat1[100], mat2[100], result[100];
    int nonZero1 = 0, nonZero2 = 0, nonZeroResult = 0;
    int choice;
    
    do {
        cout << "\n====== sparse matrix operations (triplet form) ======\n";
        cout << "1. input first sparse matrix\n";
        cout << "2. input second sparse matrix\n";
        cout << "3. display matrices\n";
        cout << "4. transpose of first matrix\n";
        cout << "5. addition of two matrices\n";
        cout << "6. multiplication of two matrices\n";
        cout << "7. exit\n";
        cout << "enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                cout << "\n--- input first sparse matrix ---\n";
                inputSparseMatrix(mat1, nonZero1);
                cout << "\nfirst matrix in triplet form:";
                displayTriplet(mat1, nonZero1);
                displayMatrix(mat1, nonZero1);
                break;
                
            case 2:
                cout << "\n--- input second sparse matrix ---\n";
                inputSparseMatrix(mat2, nonZero2);
                cout << "\nsecond matrix in triplet form:";
                displayTriplet(mat2, nonZero2);
                displayMatrix(mat2, nonZero2);
                break;
                
            case 3:
                if(nonZero1 > 0) {
                    cout << "\n--- first matrix ---";
                    displayTriplet(mat1, nonZero1);
                    displayMatrix(mat1, nonZero1);
                }
                if(nonZero2 > 0) {
                    cout << "\n--- second matrix ---";
                    displayTriplet(mat2, nonZero2);
                    displayMatrix(mat2, nonZero2);
                }
                if(nonZero1 == 0 && nonZero2 == 0) {
                    cout << "\nno matrices entered yet!\n";
                }
                break;
                
            case 4:
                if(nonZero1 == 0) {
                    cout << "\nplease input first matrix!\n";
                    break;
                }
                cout << "\n--- transpose of first matrix ---\n";
                transposeMatrix(mat1, nonZero1, result);
                cout << "\ntranspose in triplet form:";
                displayTriplet(result, result[0].value);
                displayMatrix(result, result[0].value);
                break;
                
            case 5:
                if(nonZero1 == 0 || nonZero2 == 0) {
                    cout << "\nplease input both matrices!\n";
                    break;
                }
                cout << "\n--- addition of two matrices ---\n";
                addMatrices(mat1, nonZero1, mat2, nonZero2, result, nonZeroResult);
                if(nonZeroResult > 0) {
                    cout << "\nresultant matrix in triplet form:";
                    displayTriplet(result, nonZeroResult);
                    displayMatrix(result, nonZeroResult);
                }
                break;
                
            case 6:
                if(nonZero1 == 0 || nonZero2 == 0) {
                    cout << "\nplease input both matrices!\n";
                    break;
                }
                cout << "\n--- multiplication of two matrices ---\n";
                multiplyMatrices(mat1, nonZero1, mat2, nonZero2, result, nonZeroResult);
                if(nonZeroResult > 0) {
                    cout << "\nresultant matrix in triplet form:";
                    displayTriplet(result, nonZeroResult);
                    displayMatrix(result, nonZeroResult);
                }
                break;
                
            case 7:
                cout << "exiting program...\n";
                break;
                
            default:
                cout << "invalid choice!\n";
        }
    } while(choice != 7);
    
    return 0;
}