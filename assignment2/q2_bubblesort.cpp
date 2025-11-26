#include <iostream>
using namespace std;

int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = 7;
    int i, j, temp, swapped;
    
    cout << "original array: ";
    for(i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    cout << "\nbubble sort process:\n";
    cout << "-------------------\n";
    
    for(i = 0; i < n-1; i++) {
        swapped = 0;
        cout << "\npass " << i+1 << ":\n";
        
        for(j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = 1;
                
                cout << "  swapped " << arr[j+1] << " and " << arr[j] << " -> ";
                for(int k = 0; k < n; k++) {
                    cout << arr[k] << " ";
                }
                cout << endl;
            }
        }
        
        if(swapped == 0) {
            cout << "  no swaps needed, array is sorted!\n";
            break;
        }
        
        cout << "  after pass " << i+1 << ": ";
        for(int k = 0; k < n; k++) {
            cout << arr[k] << " ";
        }
        cout << endl;
    }
    
    cout << "\nfinal sorted array: ";
    for(i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    return 0;
}