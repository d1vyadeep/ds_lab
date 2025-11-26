#include <iostream>
using namespace std;

int findMissingLinear(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        if(arr[i] != i + 1) {
            return i + 1;
        }
    }
    return n + 1;
}

int findMissingBinarySearch(int arr[], int n) {
    int low = 0, high = n - 1, mid;
    
    while(low <= high) {
        mid = (low + high) / 2;
        
        if(arr[mid] == mid + 1) {
            low = mid + 1;
        }
        else {
            if(mid == 0 || arr[mid-1] == mid) {
                return mid + 1;
            }
            high = mid - 1;
        }
    }
    return n + 1;
}

int findMissingSumFormula(int arr[], int n) {
    int total = (n + 1) * (n + 2) / 2;
    int sum = 0;
    
    for(int i = 0; i < n; i++) {
        sum += arr[i];
    }
    
    return total - sum;
}

int main() {
    int arr[100], n, choice, missing;
    
    cout << "enter number of elements (n-1): ";
    cin >> n;
    
    cout << "enter " << n << " sorted elements from range 1 to " << n+1 << ":\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << "\narray: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    do {
        cout << "\n====== find missing number ======\n";
        cout << "1. linear search - O(n)\n";
        cout << "2. binary search - O(log n)\n";
        cout << "3. sum formula - O(n)\n";
        cout << "4. compare all methods\n";
        cout << "5. exit\n";
        cout << "enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                missing = findMissingLinear(arr, n);
                cout << "\nlinear search method:\n";
                cout << "missing number: " << missing << endl;
                cout << "time complexity: O(n)\n";
                cout << "logic: compare each element with expected value (index+1)\n";
                break;
                
            case 2:
                missing = findMissingBinarySearch(arr, n);
                cout << "\nbinary search method:\n";
                cout << "missing number: " << missing << endl;
                cout << "time complexity: O(log n)\n";
                cout << "logic: if arr[mid] == mid+1, missing is in right half\n";
                cout << "       else missing is in left half or at mid\n";
                break;
                
            case 3:
                missing = findMissingSumFormula(arr, n);
                cout << "\nsum formula method:\n";
                cout << "missing number: " << missing << endl;
                cout << "time complexity: O(n)\n";
                cout << "logic: sum(1 to n+1) - sum(array elements)\n";
                cout << "formula: n*(n+1)/2\n";
                break;
                
            case 4:
                cout << "\n====== comparison of all methods ======\n";
                
                missing = findMissingLinear(arr, n);
                cout << "\n1. linear search: " << missing;
                cout << " | O(n) | simple iteration\n";
                
                missing = findMissingBinarySearch(arr, n);
                cout << "2. binary search: " << missing;
                cout << " | O(log n) | fastest for sorted array\n";
                
                missing = findMissingSumFormula(arr, n);
                cout << "3. sum formula: " << missing;
                cout << " | O(n) | mathematical approach\n";
                
                cout << "\nbest method: binary search O(log n)\n";
                break;
                
            case 5:
                cout << "exiting program...\n";
                break;
                
            default:
                cout << "invalid choice!\n";
        }
    } while(choice != 5);
    
    return 0;
}