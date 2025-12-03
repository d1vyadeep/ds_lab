#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void swap(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

void normalSelectionSort(int arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        int minIndex = i;
        
        for(int j = i+1; j < n; j++) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        
        if(minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
    }
}

void normalSelectionSortDetailed(int arr[], int n) {
    cout << "\nnormal selection sort:\n";
    cout << "----------------------\n";
    cout << "finds minimum in each pass\n\n";
    cout << "initial array: ";
    printArray(arr, n);
    
    for(int i = 0; i < n-1; i++) {
        int minIndex = i;
        
        for(int j = i+1; j < n; j++) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        
        if(minIndex != i) {
            cout << "\npass " << i+1 << ": minimum = " << arr[minIndex];
            cout << " at index " << minIndex << ", swap with " << arr[i] << " at index " << i << endl;
            swap(arr[i], arr[minIndex]);
            cout << "array: ";
            printArray(arr, n);
        }
    }
    
    cout << "\nfinal sorted array: ";
    printArray(arr, n);
}

void improvedSelectionSort(int arr[], int n) {
    int left = 0;
    int right = n - 1;
    
    while(left < right) {
        int minIndex = left;
        int maxIndex = left;
        
        for(int i = left; i <= right; i++) {
            if(arr[i] < arr[minIndex]) {
                minIndex = i;
            }
            if(arr[i] > arr[maxIndex]) {
                maxIndex = i;
            }
        }
        
        if(minIndex != left) {
            swap(arr[left], arr[minIndex]);
        }
        
        if(maxIndex == left) {
            maxIndex = minIndex;
        }
        
        if(maxIndex != right) {
            swap(arr[right], arr[maxIndex]);
        }
        
        left++;
        right--;
    }
}

void improvedSelectionSortDetailed(int arr[], int n) {
    cout << "\nimproved selection sort (min-max):\n";
    cout << "-----------------------------------\n";
    cout << "finds both minimum and maximum in each pass\n";
    cout << "sorts from both ends simultaneously\n\n";
    cout << "initial array: ";
    printArray(arr, n);
    
    int left = 0;
    int right = n - 1;
    int pass = 1;
    
    while(left < right) {
        int minIndex = left;
        int maxIndex = left;
        
        cout << "\npass " << pass << ": searching between indices " << left << " and " << right << endl;
        
        for(int i = left; i <= right; i++) {
            if(arr[i] < arr[minIndex]) {
                minIndex = i;
            }
            if(arr[i] > arr[maxIndex]) {
                maxIndex = i;
            }
        }
        
        cout << "  minimum = " << arr[minIndex] << " at index " << minIndex << endl;
        cout << "  maximum = " << arr[maxIndex] << " at index " << maxIndex << endl;
        
        if(minIndex != left) {
            cout << "  swap minimum " << arr[minIndex] << " with " << arr[left] << " at left position " << left << endl;
            swap(arr[left], arr[minIndex]);
        } else {
            cout << "  minimum already at left position\n";
        }
        
        if(maxIndex == left) {
            maxIndex = minIndex;
            cout << "  (adjusting max index since max was at left position)\n";
        }
        
        if(maxIndex != right) {
            cout << "  swap maximum " << arr[maxIndex] << " with " << arr[right] << " at right position " << right << endl;
            swap(arr[right], arr[maxIndex]);
        } else {
            cout << "  maximum already at right position\n";
        }
        
        cout << "  array: ";
        printArray(arr, n);
        
        left++;
        right--;
        pass++;
    }
    
    cout << "\nfinal sorted array: ";
    printArray(arr, n);
}

void compareAlgorithms(int arr[], int n) {
    int arr1[n], arr2[n];
    
    for(int i = 0; i < n; i++) {
        arr1[i] = arr[i];
        arr2[i] = arr[i];
    }
    
    cout << "\n====== comparison: normal vs improved selection sort ======\n";
    cout << "\noriginal array: ";
    printArray(arr, n);
    
    normalSelectionSortDetailed(arr1, n);
    
    cout << "\n" << string(60, '=') << endl;
    
    improvedSelectionSortDetailed(arr2, n);
    
    cout << "\n" << string(60, '=') << endl;
    cout << "\nanalysis:\n";
    cout << "---------\n";
    cout << "normal selection sort:\n";
    cout << "  - passes required: " << (n-1) << endl;
    cout << "  - finds minimum in each pass\n";
    cout << "  - sorts from left to right\n";
    cout << "  - time complexity: O(n^2)\n";
    
    cout << "\nimproved selection sort:\n";
    cout << "  - passes required: approximately " << (n/2) << " (half)\n";
    cout << "  - finds both minimum and maximum in each pass\n";
    cout << "  - sorts from both ends simultaneously\n";
    cout << "  - time complexity: O(n^2) but with fewer passes\n";
    
    cout << "\nimprovement:\n";
    cout << "  - reduces number of passes by half\n";
    cout << "  - more efficient for large arrays\n";
    cout << "  - same time complexity but better constants\n";
}

int main() {
    int arr[100], n, choice, temp[100];
    
    cout << "enter number of elements: ";
    cin >> n;
    
    cout << "enter " << n << " elements:\n";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    
    do {
        cout << "\n====== selection sort variants ======\n";
        cout << "1. normal selection sort (detailed)\n";
        cout << "2. improved selection sort min-max (detailed)\n";
        cout << "3. normal selection sort (simple)\n";
        cout << "4. improved selection sort min-max (simple)\n";
        cout << "5. compare both algorithms\n";
        cout << "6. show original array\n";
        cout << "7. enter new array\n";
        cout << "8. run example demonstration\n";
        cout << "9. exit\n";
        cout << "enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                for(int i = 0; i < n; i++) temp[i] = arr[i];
                normalSelectionSortDetailed(temp, n);
                break;
                
            case 2:
                for(int i = 0; i < n; i++) temp[i] = arr[i];
                improvedSelectionSortDetailed(temp, n);
                break;
                
            case 3:
                for(int i = 0; i < n; i++) temp[i] = arr[i];
                cout << "\noriginal array: ";
                printArray(temp, n);
                normalSelectionSort(temp, n);
                cout << "sorted array: ";
                printArray(temp, n);
                break;
                
            case 4:
                for(int i = 0; i < n; i++) temp[i] = arr[i];
                cout << "\noriginal array: ";
                printArray(temp, n);
                improvedSelectionSort(temp, n);
                cout << "sorted array: ";
                printArray(temp, n);
                break;
                
            case 5:
                compareAlgorithms(arr, n);
                break;
                
            case 6:
                cout << "\noriginal array: ";
                printArray(arr, n);
                break;
                
            case 7:
                cout << "enter number of elements: ";
                cin >> n;
                cout << "enter " << n << " elements:\n";
                for(int i = 0; i < n; i++) {
                    cin >> arr[i];
                }
                break;
                
            case 8:
                {
                    int example[] = {64, 25, 12, 22, 11, 90, 88, 45, 50, 33};
                    int exampleSize = 10;
                    
                    cout << "\n====== example demonstration ======\n";
                    cout << "array: [64, 25, 12, 22, 11, 90, 88, 45, 50, 33]\n";
                    
                    compareAlgorithms(example, exampleSize);
                }
                break;
                
            case 9:
                cout << "exiting program...\n";
                break;
                
            default:
                cout << "invalid choice!\n";
        }
    } while(choice != 9);
    
    return 0;
}