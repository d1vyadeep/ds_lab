#include <iostream>
using namespace std;

int countDistinctBrute(int arr[], int n) {
    int count = 0;
    bool isDistinct;
    
    cout << "\ndistinct elements: ";
    
    for(int i = 0; i < n; i++) {
        isDistinct = true;
        
        for(int j = 0; j < i; j++) {
            if(arr[i] == arr[j]) {
                isDistinct = false;
                break;
            }
        }
        
        if(isDistinct) {
            cout << arr[i] << " ";
            count++;
        }
    }
    
    cout << endl;
    return count;
}

int countDistinctSorting(int arr[], int n) {
    int temp[n];
    for(int i = 0; i < n; i++) {
        temp[i] = arr[i];
    }
    
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(temp[j] > temp[j+1]) {
                int swap = temp[j];
                temp[j] = temp[j+1];
                temp[j+1] = swap;
            }
        }
    }
    
    cout << "\nsorted array: ";
    for(int i = 0; i < n; i++) {
        cout << temp[i] << " ";
    }
    cout << endl;
    
    int count = 1;
    cout << "distinct elements: " << temp[0] << " ";
    
    for(int i = 1; i < n; i++) {
        if(temp[i] != temp[i-1]) {
            cout << temp[i] << " ";
            count++;
        }
    }
    
    cout << endl;
    return count;
}

int countDistinctHashing(int arr[], int n) {
    int hash[1000] = {0};
    int count = 0;
    int minVal = arr[0], maxVal = arr[0];
    
    for(int i = 0; i < n; i++) {
        if(arr[i] < minVal) minVal = arr[i];
        if(arr[i] > maxVal) maxVal = arr[i];
    }
    
    if(maxVal - minVal >= 1000) {
        cout << "\nrange too large for hashing method!\n";
        return -1;
    }
    
    for(int i = 0; i < n; i++) {
        hash[arr[i] - minVal] = 1;
    }
    
    cout << "\ndistinct elements: ";
    for(int i = 0; i <= maxVal - minVal; i++) {
        if(hash[i] == 1) {
            cout << (i + minVal) << " ";
            count++;
        }
    }
    
    cout << endl;
    return count;
}

int countDistinctFrequency(int arr[], int n) {
    int freq[100][2];
    int distinctCount = 0;
    
    for(int i = 0; i < n; i++) {
        bool found = false;
        
        for(int j = 0; j < distinctCount; j++) {
            if(freq[j][0] == arr[i]) {
                freq[j][1]++;
                found = true;
                break;
            }
        }
        
        if(!found) {
            freq[distinctCount][0] = arr[i];
            freq[distinctCount][1] = 1;
            distinctCount++;
        }
    }
    
    cout << "\nelement\tfrequency\n";
    cout << "-------------------\n";
    for(int i = 0; i < distinctCount; i++) {
        cout << freq[i][0] << "\t" << freq[i][1] << endl;
    }
    
    return distinctCount;
}

void displayArray(int arr[], int n) {
    cout << "array: ";
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[100], n, choice, distinct;
    
    cout << "enter number of elements: ";
    cin >> n;
    
    cout << "enter elements:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    cout << "\noriginal ";
    displayArray(arr, n);
    
    do {
        cout << "\n====== count distinct elements ======\n";
        cout << "1. brute force method - O(n^2)\n";
        cout << "2. sorting method - O(n^2) [bubble sort]\n";
        cout << "3. hashing method - O(n)\n";
        cout << "4. frequency count method - O(n^2)\n";
        cout << "5. compare all methods\n";
        cout << "6. reset array\n";
        cout << "7. exit\n";
        cout << "enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                cout << "\n--- brute force method ---\n";
                displayArray(arr, n);
                distinct = countDistinctBrute(arr, n);
                cout << "\ntotal distinct elements: " << distinct << endl;
                cout << "time complexity: O(n^2)\n";
                cout << "space complexity: O(1)\n";
                cout << "logic: check each element with all previous elements\n";
                break;
                
            case 2:
                cout << "\n--- sorting method ---\n";
                displayArray(arr, n);
                distinct = countDistinctSorting(arr, n);
                cout << "\ntotal distinct elements: " << distinct << endl;
                cout << "time complexity: O(n^2) [due to bubble sort]\n";
                cout << "space complexity: O(n)\n";
                cout << "logic: sort array, then count consecutive different elements\n";
                break;
                
            case 3:
                cout << "\n--- hashing method ---\n";
                displayArray(arr, n);
                distinct = countDistinctHashing(arr, n);
                if(distinct != -1) {
                    cout << "\ntotal distinct elements: " << distinct << endl;
                    cout << "time complexity: O(n)\n";
                    cout << "space complexity: O(range)\n";
                    cout << "logic: mark presence in hash array\n";
                }
                break;
                
            case 4:
                cout << "\n--- frequency count method ---\n";
                displayArray(arr, n);
                distinct = countDistinctFrequency(arr, n);
                cout << "\ntotal distinct elements: " << distinct << endl;
                cout << "time complexity: O(n^2)\n";
                cout << "space complexity: O(n)\n";
                cout << "logic: maintain frequency array of distinct elements\n";
                break;
                
            case 5:
                cout << "\n====== comparison of all methods ======\n";
                displayArray(arr, n);
                
                cout << "\n1. brute force: ";
                distinct = countDistinctBrute(arr, n);
                cout << "count = " << distinct << " | O(n^2) time | O(1) space\n";
                
                cout << "\n2. sorting: ";
                distinct = countDistinctSorting(arr, n);
                cout << "count = " << distinct << " | O(n^2) time | O(n) space\n";
                
                cout << "\n3. hashing: ";
                distinct = countDistinctHashing(arr, n);
                if(distinct != -1) {
                    cout << "count = " << distinct << " | O(n) time | O(range) space\n";
                }
                
                cout << "\n4. frequency: ";
                distinct = countDistinctFrequency(arr, n);
                cout << "count = " << distinct << " | O(n^2) time | O(n) space\n";
                
                cout << "\nrecommendation:\n";
                cout << "- use hashing for small range of numbers (fastest)\n";
                cout << "- use sorting for general cases with medium efficiency\n";
                cout << "- use brute force for small arrays\n";
                break;
                
            case 6:
                cout << "\nenter number of elements: ";
                cin >> n;
                
                cout << "enter elements:\n";
                for(int i = 0; i < n; i++) {
                    cin >> arr[i];
                }
                
                cout << "\nnew array: ";
                displayArray(arr, n);
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