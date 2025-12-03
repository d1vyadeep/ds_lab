#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

class CircularLinkedList {
    Node* head;
    
public:
    CircularLinkedList() {
        head = NULL;
    }
    
    void insertFirst(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        
        if(head == NULL) {
            newNode->next = newNode;
            head = newNode;
        } else {
            Node* temp = head;
            while(temp->next != head) {
                temp = temp->next;
            }
            newNode->next = head;
            temp->next = newNode;
            head = newNode;
        }
        cout << value << " inserted at first position\n";
    }
    
    void insertLast(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        
        if(head == NULL) {
            newNode->next = newNode;
            head = newNode;
        } else {
            Node* temp = head;
            while(temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
        cout << value << " inserted at last position\n";
    }
    
    void insertAfter(int target, int value) {
        if(head == NULL) {
            cout << "list is empty!\n";
            return;
        }
        
        Node* temp = head;
        do {
            if(temp->data == target) {
                Node* newNode = new Node();
                newNode->data = value;
                newNode->next = temp->next;
                temp->next = newNode;
                cout << value << " inserted after " << target << endl;
                return;
            }
            temp = temp->next;
        } while(temp != head);
        
        cout << "node " << target << " not found!\n";
    }
    
    void deleteNode(int value) {
        if(head == NULL) {
            cout << "list is empty!\n";
            return;
        }
        
        Node* temp = head;
        Node* prev = NULL;
        
        if(head->data == value && head->next == head) {
            delete head;
            head = NULL;
            cout << "node " << value << " deleted (was only node)\n";
            return;
        }
        
        if(head->data == value) {
            while(temp->next != head) {
                temp = temp->next;
            }
            temp->next = head->next;
            Node* toDelete = head;
            head = head->next;
            delete toDelete;
            cout << "node " << value << " deleted (was head node)\n";
            return;
        }
        
        temp = head;
        do {
            if(temp->next->data == value) {
                Node* toDelete = temp->next;
                temp->next = temp->next->next;
                delete toDelete;
                cout << "node " << value << " deleted\n";
                return;
            }
            temp = temp->next;
        } while(temp != head);
        
        cout << "node " << value << " not found!\n";
    }
    
    bool search(int value) {
        if(head == NULL) {
            return false;
        }
        
        Node* temp = head;
        int position = 1;
        do {
            if(temp->data == value) {
                cout << "node " << value << " found at position " << position << endl;
                return true;
            }
            temp = temp->next;
            position++;
        } while(temp != head);
        
        return false;
    }
    
    void display() {
        if(head == NULL) {
            cout << "list is empty!\n";
            return;
        }
        
        Node* temp = head;
        cout << "circular linked list: ";
        do {
            cout << temp->data;
            if(temp == head) cout << "(head)";
            cout << " -> ";
            temp = temp->next;
        } while(temp != head);
        cout << "(back to head)\n";
    }
    
    void displayWithHeadRepeat() {
        if(head == NULL) {
            cout << "list is empty!\n";
            return;
        }
        
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while(temp != head);
        cout << head->data << endl;
    }
};

class DoublyLinkedList {
    Node* head;
    
public:
    DoublyLinkedList() {
        head = NULL;
    }
    
    void insertFirst(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->prev = NULL;
        newNode->next = head;
        
        if(head != NULL) {
            head->prev = newNode;
        }
        head = newNode;
        cout << value << " inserted at first position\n";
    }
    
    void insertLast(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;
        
        if(head == NULL) {
            newNode->prev = NULL;
            head = newNode;
        } else {
            Node* temp = head;
            while(temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->prev = temp;
        }
        cout << value << " inserted at last position\n";
    }
    
    void insertAfter(int target, int value) {
        if(head == NULL) {
            cout << "list is empty!\n";
            return;
        }
        
        Node* temp = head;
        while(temp != NULL) {
            if(temp->data == target) {
                Node* newNode = new Node();
                newNode->data = value;
                newNode->next = temp->next;
                newNode->prev = temp;
                
                if(temp->next != NULL) {
                    temp->next->prev = newNode;
                }
                temp->next = newNode;
                cout << value << " inserted after " << target << endl;
                return;
            }
            temp = temp->next;
        }
        
        cout << "node " << target << " not found!\n";
    }
    
    void insertBefore(int target, int value) {
        if(head == NULL) {
            cout << "list is empty!\n";
            return;
        }
        
        Node* temp = head;
        while(temp != NULL) {
            if(temp->data == target) {
                Node* newNode = new Node();
                newNode->data = value;
                newNode->next = temp;
                newNode->prev = temp->prev;
                
                if(temp->prev != NULL) {
                    temp->prev->next = newNode;
                } else {
                    head = newNode;
                }
                temp->prev = newNode;
                cout << value << " inserted before " << target << endl;
                return;
            }
            temp = temp->next;
        }
        
        cout << "node " << target << " not found!\n";
    }
    
    void deleteNode(int value) {
        if(head == NULL) {
            cout << "list is empty!\n";
            return;
        }
        
        Node* temp = head;
        
        while(temp != NULL) {
            if(temp->data == value) {
                if(temp->prev != NULL) {
                    temp->prev->next = temp->next;
                } else {
                    head = temp->next;
                }
                
                if(temp->next != NULL) {
                    temp->next->prev = temp->prev;
                }
                
                delete temp;
                cout << "node " << value << " deleted\n";
                return;
            }
            temp = temp->next;
        }
        
        cout << "node " << value << " not found!\n";
    }
    
    bool search(int value) {
        Node* temp = head;
        int position = 1;
        
        while(temp != NULL) {
            if(temp->data == value) {
                cout << "node " << value << " found at position " << position << endl;
                return true;
            }
            temp = temp->next;
            position++;
        }
        
        return false;
    }
    
    void display() {
        if(head == NULL) {
            cout << "list is empty!\n";
            return;
        }
        
        Node* temp = head;
        cout << "doubly linked list (forward): NULL <-> ";
        while(temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
    
    void displayReverse() {
        if(head == NULL) {
            cout << "list is empty!\n";
            return;
        }
        
        Node* temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        
        cout << "doubly linked list (backward): NULL <-> ";
        while(temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->prev;
        }
        cout << "NULL\n";
    }
};

int main() {
    CircularLinkedList cll;
    DoublyLinkedList dll;
    int choice, listType, value, target;
    
    do {
        cout << "\n====== linked list operations ======\n";
        cout << "1. circular linked list\n";
        cout << "2. doubly linked list\n";
        cout << "3. exit\n";
        cout << "select list type: ";
        cin >> listType;
        
        if(listType == 3) {
            cout << "exiting program...\n";
            break;
        }
        
        if(listType == 1) {
            do {
                cout << "\n--- circular linked list menu ---\n";
                cout << "1. insert at first\n";
                cout << "2. insert at last\n";
                cout << "3. insert after specific node\n";
                cout << "4. delete node\n";
                cout << "5. search node\n";
                cout << "6. display list (standard)\n";
                cout << "7. display list (with head repeated at end)\n";
                cout << "8. back to main menu\n";
                cout << "enter your choice: ";
                cin >> choice;
                
                switch(choice) {
                    case 1:
                        cout << "enter value: ";
                        cin >> value;
                        cll.insertFirst(value);
                        break;
                    case 2:
                        cout << "enter value: ";
                        cin >> value;
                        cll.insertLast(value);
                        break;
                    case 3:
                        cout << "enter target node: ";
                        cin >> target;
                        cout << "enter value to insert: ";
                        cin >> value;
                        cll.insertAfter(target, value);
                        break;
                    case 4:
                        cout << "enter node value to delete: ";
                        cin >> value;
                        cll.deleteNode(value);
                        break;
                    case 5:
                        cout << "enter value to search: ";
                        cin >> value;
                        if(!cll.search(value)) {
                            cout << "node " << value << " not found!\n";
                        }
                        break;
                    case 6:
                        cll.display();
                        break;
                    case 7:
                        cout << "output: ";
                        cll.displayWithHeadRepeat();
                        break;
                    case 8:
                        break;
                    default:
                        cout << "invalid choice!\n";
                }
            } while(choice != 8);
        }
        else if(listType == 2) {
            do {
                cout << "\n--- doubly linked list menu ---\n";
                cout << "1. insert at first\n";
                cout << "2. insert at last\n";
                cout << "3. insert after specific node\n";
                cout << "4. insert before specific node\n";
                cout << "5. delete node\n";
                cout << "6. search node\n";
                cout << "7. display list (forward)\n";
                cout << "8. display list (backward)\n";
                cout << "9. back to main menu\n";
                cout << "enter your choice: ";
                cin >> choice;
                
                switch(choice) {
                    case 1:
                        cout << "enter value: ";
                        cin >> value;
                        dll.insertFirst(value);
                        break;
                    case 2:
                        cout << "enter value: ";
                        cin >> value;
                        dll.insertLast(value);
                        break;
                    case 3:
                        cout << "enter target node: ";
                        cin >> target;
                        cout << "enter value to insert: ";
                        cin >> value;
                        dll.insertAfter(target, value);
                        break;
                    case 4:
                        cout << "enter target node: ";
                        cin >> target;
                        cout << "enter value to insert: ";
                        cin >> value;
                        dll.insertBefore(target, value);
                        break;
                    case 5:
                        cout << "enter node value to delete: ";
                        cin >> value;
                        dll.deleteNode(value);
                        break;
                    case 6:
                        cout << "enter value to search: ";
                        cin >> value;
                        if(!dll.search(value)) {
                            cout << "node " << value << " not found!\n";
                        }
                        break;
                    case 7:
                        dll.display();
                        break;
                    case 8:
                        dll.displayReverse();
                        break;
                    case 9:
                        break;
                    default:
                        cout << "invalid choice!\n";
                }
            } while(choice != 9);
        }
        else {
            cout << "invalid list type!\n";
        }
    } while(listType != 3);
    
    return 0;
}