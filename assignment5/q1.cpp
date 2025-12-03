#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class SinglyLinkedList {
    Node* head;
    
public:
    SinglyLinkedList() {
        head = NULL;
    }
    
    void insertAtBeginning(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
        cout << value << " inserted at beginning\n";
    }
    
    void insertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;
        
        if(head == NULL) {
            head = newNode;
            cout << value << " inserted at end (as first node)\n";
            return;
        }
        
        Node* temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        cout << value << " inserted at end\n";
    }
    
    void insertBefore(int target, int value) {
        if(head == NULL) {
            cout << "list is empty!\n";
            return;
        }
        
        if(head->data == target) {
            insertAtBeginning(value);
            return;
        }
        
        Node* temp = head;
        while(temp->next != NULL && temp->next->data != target) {
            temp = temp->next;
        }
        
        if(temp->next == NULL) {
            cout << "node " << target << " not found!\n";
            return;
        }
        
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = temp->next;
        temp->next = newNode;
        cout << value << " inserted before " << target << endl;
    }
    
    void insertAfter(int target, int value) {
        if(head == NULL) {
            cout << "list is empty!\n";
            return;
        }
        
        Node* temp = head;
        while(temp != NULL && temp->data != target) {
            temp = temp->next;
        }
        
        if(temp == NULL) {
            cout << "node " << target << " not found!\n";
            return;
        }
        
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = temp->next;
        temp->next = newNode;
        cout << value << " inserted after " << target << endl;
    }
    
    void deleteFromBeginning() {
        if(head == NULL) {
            cout << "list is empty!\n";
            return;
        }
        
        Node* temp = head;
        int value = temp->data;
        head = head->next;
        delete temp;
        cout << "node " << value << " deleted from beginning\n";
    }
    
    void deleteFromEnd() {
        if(head == NULL) {
            cout << "list is empty!\n";
            return;
        }
        
        if(head->next == NULL) {
            int value = head->data;
            delete head;
            head = NULL;
            cout << "node " << value << " deleted from end\n";
            return;
        }
        
        Node* temp = head;
        while(temp->next->next != NULL) {
            temp = temp->next;
        }
        
        int value = temp->next->data;
        delete temp->next;
        temp->next = NULL;
        cout << "node " << value << " deleted from end\n";
    }
    
    void deleteNode(int value) {
        if(head == NULL) {
            cout << "list is empty!\n";
            return;
        }
        
        if(head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            cout << "node " << value << " deleted (was head node)\n";
            return;
        }
        
        Node* temp = head;
        while(temp->next != NULL && temp->next->data != value) {
            temp = temp->next;
        }
        
        if(temp->next == NULL) {
            cout << "node " << value << " not found!\n";
            return;
        }
        
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
        cout << "node " << value << " deleted\n";
    }
    
    void search(int value) {
        if(head == NULL) {
            cout << "list is empty!\n";
            return;
        }
        
        Node* temp = head;
        int position = 1;
        
        while(temp != NULL) {
            if(temp->data == value) {
                cout << "node " << value << " found at position " << position << " from head\n";
                return;
            }
            temp = temp->next;
            position++;
        }
        
        cout << "node " << value << " not found in list\n";
    }
    
    void display() {
        if(head == NULL) {
            cout << "list is empty!\n";
            return;
        }
        
        Node* temp = head;
        cout << "linked list: ";
        while(temp != NULL) {
            cout << temp->data;
            if(temp == head) cout << "(head)";
            if(temp->next != NULL) {
                cout << " -> ";
            }
            temp = temp->next;
        }
        cout << " -> NULL\n";
    }
    
    int count() {
        int cnt = 0;
        Node* temp = head;
        while(temp != NULL) {
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }
};

int main() {
    SinglyLinkedList sll;
    int choice, value, target, insertChoice;
    
    do {
        cout << "\n====== singly linked list operations ======\n";
        cout << "1. insertion at beginning\n";
        cout << "2. insertion at end\n";
        cout << "3. insertion before a node\n";
        cout << "4. insertion after a node\n";
        cout << "5. deletion from beginning\n";
        cout << "6. deletion from end\n";
        cout << "7. deletion of specific node\n";
        cout << "8. search for a node\n";
        cout << "9. display all nodes\n";
        cout << "10. count nodes\n";
        cout << "11. exit\n";
        cout << "enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                cout << "enter value to insert: ";
                cin >> value;
                sll.insertAtBeginning(value);
                break;
                
            case 2:
                cout << "enter value to insert: ";
                cin >> value;
                sll.insertAtEnd(value);
                break;
                
            case 3:
                cout << "enter target node value: ";
                cin >> target;
                cout << "enter value to insert before " << target << ": ";
                cin >> value;
                sll.insertBefore(target, value);
                break;
                
            case 4:
                cout << "enter target node value: ";
                cin >> target;
                cout << "enter value to insert after " << target << ": ";
                cin >> value;
                sll.insertAfter(target, value);
                break;
                
            case 5:
                sll.deleteFromBeginning();
                break;
                
            case 6:
                sll.deleteFromEnd();
                break;
                
            case 7:
                cout << "enter node value to delete: ";
                cin >> value;
                sll.deleteNode(value);
                break;
                
            case 8:
                cout << "enter value to search: ";
                cin >> value;
                sll.search(value);
                break;
                
            case 9:
                sll.display();
                break;
                
            case 10:
                cout << "total nodes: " << sll.count() << endl;
                break;
                
            case 11:
                cout << "exiting program...\n";
                break;
                
            default:
                cout << "invalid choice!\n";
        }
    } while(choice != 11);
    
    return 0;
}