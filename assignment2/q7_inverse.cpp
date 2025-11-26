#include <iostream>
using namespace std;

int countInversionsBrute(int arr[], int n) {
    int count = 0;
    
    cout << "\ninversions found:\n";
    cout << "-------------------\n";
    
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            if(arr[i] > arr[j]) {
                cout << "(" << arr[i] << ", " << arr[j] << ") at indices (" << i << ", " << j << ")\n";
                count++;
            }
        }
    }
    
    return count;
}

int mergeAndCount(int arr[], int temp[], int left, int mid, int right) {
    int i = left, j = mid + 1, k = left;
    int invCount = 0;
    
    while(i <= mid && j <= right) {
        if(arr[i] <= arr[j]) {
            temp[k++] = arr[i++];
        }
        else {
            temp[k++] = arr[j++];
            invCount += (mid - i + 1);
        }
    }
    
    while(i <= mid) {
        temp[k++] = arr[i++];
    }
    
    while(j <= right) {
        temp[k++] = arr[j++];
    }
    
    for(i = left; i <= right; i++) {
        arr[i] = temp[i];
    }
    
    return invCount;
}

int mergeSortAndCount(int arr[], int temp[], int left, int right) {
    int invCount = 0;
    
    if(left < right) {
        int mid = (left + right) / 2;
        
        invCount += mergeSortAndCount(arr, temp, left, mid);
        invCount += mergeSortAndCount(arr, temp, mid + 1, right);
        invCount += mergeAndCount(arr, temp, left, mid, right);
    }
    
    return invCount;
}

int countInversionsOptimized(int arr[], int n) {
    int temp[n];
    return mergeSortAndCount(arr, temp, 0, n - 1);
}

void displayArray(int arr[], int n) {
    cout << "array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[100], arrCopy[100], n, choice, inversions;
    
    cout << "enter number of elements: ";
    cin >> n;
    
    cout << "enter elements:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << "\noriginal ";
    displayArray(arr, n);
    
    do {
        cout << "\n====== count inversions ======\n";
        cout << "1. brute force method - O(n^2)\n";
        cout << "2. optimized method (merge sort) - O(n log n)\n";
        cout << "3. compare both methods\n";
        cout << "4. reset array\n";
        cout << "5. exit\n";
        cout << "enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                for(int i = 0; i < n; i++) {
                    arrCopy[i] = arr[i];
                }
                
                cout << "\n--- brute force method ---\n";
                displayArray(arrCopy, n);
                inversions = countInversionsBrute(arrCopy, n);
                cout << "\ntotal number of inversions: " << inversions << endl;
                cout << "time complexity: O(n^2)\n";
                cout << "space complexity: O(1)\n";
                break;
                
            case 2:
                for(int i = 0; i < n; i++) {
                    arrCopy[i] = arr[i];
                }
                
                cout << "\n--- optimized method (merge sort) ---\n";
                displayArray(arrCopy, n);
                inversions = countInversionsOptimized(arrCopy, n);
                cout << "\ntotal number of inversions: " << inversions << endl;
                cout << "time complexity: O(n log n)\n";
                cout << "space complexity: O(n)\n";
                cout << "\nnote: array is sorted after this operation\n";
                displayArray(arrCopy, n);
                break;
                
            case 3:
                cout << "\n--- comparison of both methods ---\n";
                
                for(int i = 0; i < n; i++) {
                    arrCopy[i] = arr[i];
                }
                
                cout << "\nmethod 1: brute force\n";
                inversions = countInversionsBrute(arrCopy, n);
                cout << "inversions: " << inversions;
                cout << " | time: O(n^2) | space: O(1)\n";
                
                for(int i = 0; i < n; i++) {
                    arrCopy[i] = arr[i];
                }
                
                cout << "\nmethod 2: merge sort based\n";
                inversions = countInversionsOptimized(arrCopy, n);
                cout << "inversions: " << inversions;
                cout << " | time: O(n log n) | space: O(n)\n";
                
                cout << "\nrecommendation: use merge sort method for large arrays\n";
                break;
                
            case 4:
                cout << "\nenter number of elements: ";
                cin >> n;
                
                cout << "enter elements:\n";
                for(int i = 0; i < n; i++) {
                    cin >> arr[i];
                }
                
                cout << "\nnew array: ";
                displayArray(arr, n);
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
