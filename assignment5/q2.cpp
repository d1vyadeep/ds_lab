#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
    Node* head;
    
public:
    LinkedList() {
        head = NULL;
    }
    
    void insertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;
        
        if(head == NULL) {
            head = newNode;
            return;
        }
        
        Node* temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    
    void display() {
        if(head == NULL) {
            cout << "list is empty!\n";
            return;
        }
        
        Node* temp = head;
        while(temp != NULL) {
            cout << temp->data;
            if(temp->next != NULL) {
                cout << " -> ";
            }
            temp = temp->next;
        }
        cout << endl;
    }
    
    int countOccurrences(int key) {
        int count = 0;
        Node* temp = head;
        
        while(temp != NULL) {
            if(temp->data == key) {
                count++;
            }
            temp = temp->next;
        }
        
        return count;
    }
    
    int countOccurrencesDetailed(int key) {
        int count = 0;
        int position = 1;
        Node* temp = head;
        
        cout << "\nsearching for key " << key << " in list:\n";
        
        while(temp != NULL) {
            if(temp->data == key) {
                count++;
                cout << "  found at position " << position << endl;
            }
            temp = temp->next;
            position++;
        }
        
        return count;
    }
    
    void deleteAllOccurrences(int key) {
        if(head == NULL) {
            return;
        }
        
        while(head != NULL && head->data == key) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        
        Node* current = head;
        while(current != NULL && current->next != NULL) {
            if(current->next->data == key) {
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
            } else {
                current = current->next;
            }
        }
    }
    
    void deleteAllOccurrencesDetailed(int key) {
        if(head == NULL) {
            cout << "list is empty!\n";
            return;
        }
        
        cout << "\ndeleting all occurrences of " << key << ":\n";
        int deleteCount = 0;
        
        while(head != NULL && head->data == key) {
            Node* temp = head;
            head = head->next;
            delete temp;
            deleteCount++;
            cout << "  deleted from head position\n";
        }
        
        Node* current = head;
        while(current != NULL && current->next != NULL) {
            if(current->next->data == key) {
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
                deleteCount++;
                cout << "  deleted occurrence\n";
            } else {
                current = current->next;
            }
        }
        
        cout << "total nodes deleted: " << deleteCount << endl;
    }
    
    void countAndDelete(int key) {
        cout << "\nlinked list: ";
        display();
        cout << "key: " << key << endl;
        
        int count = countOccurrencesDetailed(key);
        
        cout << "\ncount: " << count << endl;
        
        if(count == 0) {
            cout << "no occurrences found. list remains unchanged.\n";
            return;
        }
        
        deleteAllOccurrencesDetailed(key);
        
        cout << "\nupdated linked list: ";
        display();
    }
    
    void countAndDeleteSimple(int key) {
        cout << "linked list: ";
        display();
        
        int count = countOccurrences(key);
        cout << "count: " << count << endl;
        
        if(count > 0) {
            deleteAllOccurrences(key);
            cout << "updated linked list: ";
            display();
        } else {
            cout << "no occurrences found.\n";
        }
    }
};

int main() {
    LinkedList ll;
    int choice, n, value, key;
    
    do {
        cout << "\n====== count and delete occurrences ======\n";
        cout << "1. create linked list\n";
        cout << "2. display list\n";
        cout << "3. count occurrences of key\n";
        cout << "4. delete all occurrences of key\n";
        cout << "5. count and delete (detailed)\n";
        cout << "6. count and delete (simple)\n";
        cout << "7. run sample example (1->2->1->2->1->3->1, key=1)\n";
        cout << "8. exit\n";
        cout << "enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                ll = LinkedList();
                cout << "enter number of nodes: ";
                cin >> n;
                
                cout << "enter " << n << " values:\n";
                for(int i = 0; i < n; i++) {
                    cin >> value;
                    ll.insertAtEnd(value);
                }
                cout << "linked list created!\n";
                break;
                
            case 2:
                cout << "linked list: ";
                ll.display();
                break;
                
            case 3:
                cout << "enter key to count: ";
                cin >> key;
                value = ll.countOccurrences(key);
                cout << "key " << key << " occurs " << value << " times\n";
                break;
                
            case 4:
                cout << "enter key to delete all occurrences: ";
                cin >> key;
                cout << "before deletion: ";
                ll.display();
                ll.deleteAllOccurrences(key);
                cout << "after deletion: ";
                ll.display();
                break;
                
            case 5:
                cout << "enter key: ";
                cin >> key;
                ll.countAndDelete(key);
                break;
                
            case 6:
                cout << "enter key: ";
                cin >> key;
                ll.countAndDeleteSimple(key);
                break;
                
            case 7:
                {
                    LinkedList sample;
                    int sampleData[] = {1, 2, 1, 2, 1, 3, 1};
                    int sampleSize = 7;
                    int sampleKey = 1;
                    
                    cout << "\n====== sample example ======\n";
                    cout << "input:\n";
                    for(int i = 0; i < sampleSize; i++) {
                        sample.insertAtEnd(sampleData[i]);
                    }
                    
                    sample.countAndDeleteSimple(sampleKey);
                    
                    cout << "\nexpected output:\n";
                    cout << "count: 4\n";
                    cout << "updated linked list: 2 -> 2 -> 3\n";
                }
                break;
                
            case 8:
                cout << "exiting program...\n";
                break;
                
            default:
                cout << "invalid choice!\n";
        }
    } while(choice != 8);
    
    return 0;
}