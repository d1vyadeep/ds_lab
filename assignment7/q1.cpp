#include <iostream>
using namespace std;

void printArray(int arr[], int n) {
    for(int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void copyArray(int source[], int dest[], int n) {
    for(int i = 0; i < n; i++) {
        dest[i] = source[i];
    }
}

void selectionSort(int arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        int minIndex = i;
        for(int j = i+1; j < n; j++) {
            if(arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if(minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

void selectionSortDetailed(int arr[], int n) {
    cout << "\nselection sort process:\n";
    cout << "-----------------------\n";
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
            cout << "\npass " << i+1 << ": minimum " << arr[minIndex] << " found at index " << minIndex;
            cout << ", swap with " << arr[i] << " at index " << i << endl;
            
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
            
            cout << "array: ";
            printArray(arr, n);
        }
    }
    
    cout << "\nfinal sorted array: ";
    printArray(arr, n);
}

void insertionSort(int arr[], int n) {
    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void insertionSortDetailed(int arr[], int n) {
    cout << "\ninsertion sort process:\n";
    cout << "-----------------------\n";
    cout << "initial array: ";
    printArray(arr, n);
    
    for(int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        
        cout << "\npass " << i << ": inserting " << key << " into sorted portion\n";
        
        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
        
        cout << "array: ";
        printArray(arr, n);
    }
    
    cout << "\nfinal sorted array: ";
    printArray(arr, n);
}

void bubbleSort(int arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        bool swapped = false;
        
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = true;
            }
        }
        
        if(!swapped) {
            break;
        }
    }
}

void bubbleSortDetailed(int arr[], int n) {
    cout << "\nbubble sort process:\n";
    cout << "--------------------\n";
    cout << "initial array: ";
    printArray(arr, n);
    
    for(int i = 0; i < n-1; i++) {
        bool swapped = false;
        cout << "\npass " << i+1 << ":\n";
        
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                cout << "  swap " << arr[j] << " and " << arr[j+1] << endl;
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                swapped = true;
            }
        }
        
        cout << "  array: ";
        printArray(arr, n);
        
        if(!swapped) {
            cout << "  no swaps, array is sorted!\n";
            break;
        }
    }
    
    cout << "\nfinal sorted array: ";
    printArray(arr, n);
}

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    int L[n1], R[n2];
    
    for(int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for(int j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }
    
    int i = 0, j = 0, k = left;
    
    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    
    while(i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    
    while(j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSortHelper(int arr[], int left, int right) {
    if(left < right) {
        int mid = left + (right - left) / 2;
        
        mergeSortHelper(arr, left, mid);
        mergeSortHelper(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void mergeSort(int arr[], int n) {
    mergeSortHelper(arr, 0, n - 1);
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    
    for(int j = low; j < high; j++) {
        if(arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    
    return i + 1;
}

void quickSortHelper(int arr[], int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);
        
        quickSortHelper(arr, low, pi - 1);
        quickSortHelper(arr, pi + 1, high);
    }
}

void quickSort(int arr[], int n) {
    quickSortHelper(arr, 0, n - 1);
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
        cout << "\n====== sorting algorithms ======\n";
        cout << "1. selection sort\n";
        cout << "2. insertion sort\n";
        cout << "3. bubble sort\n";
        cout << "4. merge sort\n";
        cout << "5. quick sort\n";
        cout << "6. compare all sorting methods\n";
        cout << "7. show original array\n";
        cout << "8. enter new array\n";
        cout << "9. exit\n";
        cout << "enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                copyArray(arr, temp, n);
                cout << "\noriginal array: ";
                printArray(temp, n);
                selectionSortDetailed(temp, n);
                cout << "\ntime complexity: O(n^2)\n";
                cout << "space complexity: O(1)\n";
                break;
                
            case 2:
                copyArray(arr, temp, n);
                cout << "\noriginal array: ";
                printArray(temp, n);
                insertionSortDetailed(temp, n);
                cout << "\ntime complexity: O(n^2) worst, O(n) best\n";
                cout << "space complexity: O(1)\n";
                break;
                
            case 3:
                copyArray(arr, temp, n);
                cout << "\noriginal array: ";
                printArray(temp, n);
                bubbleSortDetailed(temp, n);
                cout << "\ntime complexity: O(n^2) worst, O(n) best\n";
                cout << "space complexity: O(1)\n";
                break;
                
            case 4:
                copyArray(arr, temp, n);
                cout << "\noriginal array: ";
                printArray(temp, n);
                cout << "\nmerge sort (divide and conquer):\n";
                mergeSort(temp, n);
                cout << "sorted array: ";
                printArray(temp, n);
                cout << "\ntime complexity: O(n log n)\n";
                cout << "space complexity: O(n)\n";
                break;
                
            case 5:
                copyArray(arr, temp, n);
                cout << "\noriginal array: ";
                printArray(temp, n);
                cout << "\nquick sort (divide and conquer):\n";
                quickSort(temp, n);
                cout << "sorted array: ";
                printArray(temp, n);
                cout << "\ntime complexity: O(n log n) average, O(n^2) worst\n";
                cout << "space complexity: O(log n)\n";
                break;
                
            case 6:
                {
                    cout << "\n====== comparison of all sorting methods ======\n";
                    cout << "\noriginal array: ";
                    printArray(arr, n);
                    
                    cout << "\n1. selection sort:\n";
                    copyArray(arr, temp, n);
                    selectionSort(temp, n);
                    cout << "   result: ";
                    printArray(temp, n);
                    cout << "   time: O(n^2) | space: O(1) | stable: no\n";
                    
                    cout << "\n2. insertion sort:\n";
                    copyArray(arr, temp, n);
                    insertionSort(temp, n);
                    cout << "   result: ";
                    printArray(temp, n);
                    cout << "   time: O(n^2) | space: O(1) | stable: yes\n";
                    
                    cout << "\n3. bubble sort:\n";
                    copyArray(arr, temp, n);
                    bubbleSort(temp, n);
                    cout << "   result: ";
                    printArray(temp, n);
                    cout << "   time: O(n^2) | space: O(1) | stable: yes\n";
                    
                    cout << "\n4. merge sort:\n";
                    copyArray(arr, temp, n);
                    mergeSort(temp, n);
                    cout << "   result: ";
                    printArray(temp, n);
                    cout << "   time: O(n log n) | space: O(n) | stable: yes\n";
                    
                    cout << "\n5. quick sort:\n";
                    copyArray(arr, temp, n);
                    quickSort(temp, n);
                    cout << "   result: ";
                    printArray(temp, n);
                    cout << "   time: O(n log n) avg | space: O(log n) | stable: no\n";
                    
                    cout << "\nrecommendations:\n";
                    cout << "- small arrays: insertion sort\n";
                    cout << "- general purpose: merge sort or quick sort\n";
                    cout << "- nearly sorted: insertion sort or bubble sort\n";
                    cout << "- guaranteed O(n log n): merge sort\n";
                }
                break;
                
            case 7:
                cout << "\noriginal array: ";
                printArray(arr, n);
                break;
                
            case 8:
                cout << "enter number of elements: ";
                cin >> n;
                cout << "enter " << n << " elements:\n";
                for(int i = 0; i < n; i++) {
                    cin >> arr[i];
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