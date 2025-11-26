#include <iostream>
using namespace std;

int main() {
    int arr[100], n = 0, choice, pos, element, i, found;
    
    do {
        cout << "\n------ menu ------\n";
        cout << "1. create\n";
        cout << "2. display\n";
        cout << "3. insert\n";
        cout << "4. delete\n";
        cout << "5. linear search\n";
        cout << "6. exit\n";
        cout << "enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                cout << "enter number of elements: ";
                cin >> n;
                cout << "enter elements: ";
                for(i = 0; i < n; i++) {
                    cin >> arr[i];
                }
                cout << "array created successfully!\n";
                break;
                
            case 2:
                if(n == 0)
                    cout << "array is empty!\n";
                else {
                    cout << "array elements are: ";
                    for(i = 0; i < n; i++)
                        cout << arr[i] << " ";
                    cout << endl;
                }
                break;
                
            case 3:
                if(n == 0) {
                    cout << "array not created yet!\n";
                } else {
                    cout << "enter position to insert (1 to " << n+1 << "): ";
                    cin >> pos;
                    if(pos < 1 || pos > n + 1) {
                        cout << "invalid position!\n";
                    } else {
                        cout << "enter element to insert: ";
                        cin >> element;
                        for(i = n; i >= pos; i--)
                            arr[i] = arr[i-1];
                        arr[pos-1] = element;
                        n++;
                        cout << "element inserted successfully!\n";
                    }
                }
                break;
                
            case 4:
                if(n == 0) {
                    cout << "array is empty!\n";
                } else {
                    cout << "enter position to delete (1 to " << n << "): ";
                    cin >> pos;
                    if(pos < 1 || pos > n) {
                        cout << "invalid position!\n";
                    } else {
                        element = arr[pos-1];
                        for(i = pos-1; i < n-1; i++)
                            arr[i] = arr[i+1];
                        n--;
                        cout << "element " << element << " deleted successfully!\n";
                    }
                }
                break;
                
            case 5:
                if(n == 0) {
                    cout << "array is empty!\n";
                } else {
                    cout << "enter element to search: ";
                    cin >> element;
                    found = 0;
                    for(i = 0; i < n; i++) {
                        if(arr[i] == element) {
                            cout << "element " << element << " found at position " << i+1 << endl;
                            found = 1;
                            break;
                        }
                    }
                    if(!found)
                        cout << "element not found!\n";
                }
                break;
                
            case 6:
                cout << "exiting program...\n";
                break;
                
            default:
                cout << "invalid choice! please enter 1-6.\n";
        }
    } while(choice != 6);
    
    return 0;
}