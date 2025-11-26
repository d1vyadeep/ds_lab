#include <iostream>
using namespace std;

void linearSearch(int arr[], int n, int key) {
    int i, found = 0, comparisons = 0;
    
    for(i = 0; i < n; i++) {
        comparisons++;
        if(arr[i] == key) {
            found = 1;
            cout << "\nlinear search: element " << key << " found at position " << i+1 << endl;
            break;
        }
    }
    
    if(!found)
        cout << "\nlinear search: element not found\n";
    
    cout << "comparisons made: " << comparisons << endl;
}

void binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1, mid, found = 0, comparisons = 0;
    
    while(low <= high) {
        mid = (low + high) / 2;
        comparisons++;
        
        if(arr[mid] == key) {
            found = 1;
            cout << "\nbinary search: element " << key << " found at position " << mid+1 << endl;
            break;
        }
        else if(arr[mid] < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    
    if(!found)
        cout << "\nbinary search: element not found\n";
    
    cout << "comparisons made: " << comparisons << endl;
}

void sortArray(int arr[], int n) {
    int i, j, temp;
    
    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int arr[100], n, i, key, choice;
    
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
    
    do {
        cout << "\n====== search menu ======\n";
        cout << "1. linear search\n";
        cout << "2. binary search\n";
        cout << "3. compare both searches\n";
        cout << "4. exit\n";
        cout << "enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                cout << "enter element to search: ";
                cin >> key;
                linearSearch(arr, n, key);
                break;
                
            case 2:
                sortArray(arr, n);
                cout << "\narray sorted for binary search: ";
                for(i = 0; i < n; i++) {
                    cout << arr[i] << " ";
                }
                cout << endl;
                
                cout << "enter element to search: ";
                cin >> key;
                binarySearch(arr, n, key);
                break;
                
            case 3:
                cout << "enter element to search: ";
                cin >> key;
                
                linearSearch(arr, n, key);
                
                sortArray(arr, n);
                cout << "\narray sorted for binary search: ";
                for(i = 0; i < n; i++) {
                    cout << arr[i] << " ";
                }
                cout << endl;
                
                binarySearch(arr, n, key);
                
                cout << "\n--- performance comparison ---\n";
                cout << "linear search: O(n) - checks elements sequentially\n";
                cout << "binary search: O(log n) - divides search space in half\n";
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