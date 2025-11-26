#include <iostream>
using namespace std;

int main() {
    int arr[100], n, i, j, k;
    
    cout << "enter number of elements: ";
    cin >> n;
    
    cout << "enter elements: ";
    for(i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << "\noriginal array: ";
    for(i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    for(i = 0; i < n; i++) {
        for(j = i + 1; j < n; j++) {
            if(arr[i] == arr[j]) {
                for(k = j; k < n - 1; k++) {
                    arr[k] = arr[k + 1];
                }
                n--;
                j--;
            }
        }
    }
    
    cout << "\narray after removing duplicates: ";
    for(i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    cout << "\ntotal unique elements: " << n << endl;
    
    return 0;
}