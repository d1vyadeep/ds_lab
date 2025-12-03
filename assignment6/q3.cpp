#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

class DoublyLinkedList {
    Node* head;
    
public:
    DoublyLinkedList() {
        head = NULL;
    }
    
    void insertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;
        
        if(head == NULL) {
            newNode->prev = NULL;
            head = newNode;
            return;
        }
        
        Node* temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    
    void display() {
        if(head == NULL) {
            cout << "list is empty!\n";
            return;
        }
        
        Node* temp = head;
        cout << "NULL <-> ";
        while(temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
    
    int findSize() {
        int count = 0;
        Node* temp = head;
        
        while(temp != NULL) {
            count++;
            temp = temp->next;
        }
        
        return count;
    }
    
    int findSizeDetailed() {
        int count = 0;
        Node* temp = head;
        
        cout << "\ntraversing doubly linked list to count nodes:\n";
        cout << "---------------------------------------------\n";
        
        if(temp == NULL) {
            cout << "list is empty!\n";
            return 0;
        }
        
        while(temp != NULL) {
            count++;
            cout << "node " << count << ": value = " << temp->data;
            if(temp->prev) cout << ", prev = " << temp->prev->data;
            else cout << ", prev = NULL";
            if(temp->next) cout << ", next = " << temp->next->data;
            else cout << ", next = NULL";
            cout << endl;
            temp = temp->next;
        }
        
        cout << "\ntotal size: " << count << endl;
        return count;
    }
};

class CircularLinkedList {
    Node* head;
    
public:
    CircularLinkedList() {
        head = NULL;
    }
    
    void insertAtEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        
        if(head == NULL) {
            newNode->next = newNode;
            head = newNode;
            return;
        }
        
        Node* temp = head;
        while(temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
    
    void display() {
        if(head == NULL) {
            cout << "list is empty!\n";
            return;
        }
        
        Node* temp = head;
        do {
            cout << temp->data;
            if(temp == head) cout << "(head)";
            cout << " -> ";
            temp = temp->next;
        } while(temp != head);
        cout << "(back to head)\n";
    }
    
    int findSize() {
        if(head == NULL) {
            return 0;
        }
        
        int count = 0;
        Node* temp = head;
        
        do {
            count++;
            temp = temp->next;
        } while(temp != head);
        
        return count;
    }
    
    int findSizeDetailed() {
        if(head == NULL) {
            cout << "list is empty!\n";
            return 0;
        }
        
        int count = 0;
        Node* temp = head;
        
        cout << "\ntraversing circular linked list to count nodes:\n";
        cout << "-----------------------------------------------\n";
        cout << "starting from head, stopping when we reach head again\n\n";
        
        do {
            count++;
            cout << "node " << count << ": value = " << temp->data;
            if(temp == head) cout << " (HEAD)";
            cout << ", next = " << temp->next->data;
            if(temp->next == head) cout << " (points to HEAD)";
            cout << endl;
            temp = temp->next;
        } while(temp != head);
        
        cout << "\nreached head again, traversal complete!\n";
        cout << "total size: " << count << endl;
        return count;
    }
};

int main() {
    DoublyLinkedList dll;
    CircularLinkedList cll;
    int choice, listType, n, value, size;
    
    do {
        cout << "\n====== find size of linked lists ======\n";
        cout << "1. doubly linked list\n";
        cout << "2. circular linked list\n";
        cout << "3. exit\n";
        cout << "select list type: ";
        cin >> listType;
        
        if(listType == 3) {
            cout << "exiting program...\n";
            break;
        }
        
        if(listType == 1) {
            do {
                cout << "\n--- doubly linked list menu ---\n";
                cout << "1. create list\n";
                cout << "2. display list\n";
                cout << "3. find size (simple)\n";
                cout << "4. find size (detailed)\n";
                cout << "5. demonstration\n";
                cout << "6. back to main menu\n";
                cout << "enter your choice: ";
                cin >> choice;
                
                switch(choice) {
                    case 1:
                        dll = DoublyLinkedList();
                        cout << "enter number of nodes: ";
                        cin >> n;
                        cout << "enter " << n << " values:\n";
                        for(int i = 0; i < n; i++) {
                            cin >> value;
                            dll.insertAtEnd(value);
                        }
                        cout << "doubly linked list created!\n";
                        break;
                        
                    case 2:
                        cout << "doubly linked list: ";
                        dll.display();
                        break;
                        
                    case 3:
                        size = dll.findSize();
                        cout << "size of doubly linked list: " << size << endl;
                        break;
                        
                    case 4:
                        dll.findSizeDetailed();
                        break;
                        
                    case 5:
                        {
                            DoublyLinkedList demo;
                            int demoData[] = {10, 20, 30, 40, 50};
                            
                            cout << "\n====== doubly linked list demonstration ======\n";
                            cout << "\ncreating list with values: 10, 20, 30, 40, 50\n";
                            for(int i = 0; i < 5; i++) {
                                demo.insertAtEnd(demoData[i]);
                            }
                            
                            cout << "\nlist: ";
                            demo.display();
                            
                            cout << "\nalgorithm to find size:\n";
                            cout << "1. start from head\n";
                            cout << "2. traverse using 'next' pointer\n";
                            cout << "3. count each node\n";
                            cout << "4. stop when next becomes NULL\n";
                            
                            size = demo.findSizeDetailed();
                            
                            cout << "\ntime complexity: O(n)\n";
                            cout << "space complexity: O(1)\n";
                        }
                        break;
                        
                    case 6:
                        break;
                        
                    default:
                        cout << "invalid choice!\n";
                }
            } while(choice != 6);
        }
        else if(listType == 2) {
            do {
                cout << "\n--- circular linked list menu ---\n";
                cout << "1. create list\n";
                cout << "2. display list\n";
                cout << "3. find size (simple)\n";
                cout << "4. find size (detailed)\n";
                cout << "5. demonstration\n";
                cout << "6. back to main menu\n";
                cout << "enter your choice: ";
                cin >> choice;
                
                switch(choice) {
                    case 1:
                        cll = CircularLinkedList();
                        cout << "enter number of nodes: ";
                        cin >> n;
                        cout << "enter " << n << " values:\n";
                        for(int i = 0; i < n; i++) {
                            cin >> value;
                            cll.insertAtEnd(value);
                        }
                        cout << "circular linked list created!\n";
                        break;
                        
                    case 2:
                        cout << "circular linked list: ";
                        cll.display();
                        break;
                        
                    case 3:
                        size = cll.findSize();
                        cout << "size of circular linked list: " << size << endl;
                        break;
                        
                    case 4:
                        cll.findSizeDetailed();
                        break;
                        
                    case 5:
                        {
                            CircularLinkedList demo;
                            int demoData[] = {5, 10, 15, 20, 25, 30};
                            
                            cout << "\n====== circular linked list demonstration ======\n";
                            cout << "\ncreating list with values: 5, 10, 15, 20, 25, 30\n";
                            for(int i = 0; i < 6; i++) {
                                demo.insertAtEnd(demoData[i]);
                            }
                            
                            cout << "\nlist: ";
                            demo.display();
                            
                            cout << "\nalgorithm to find size:\n";
                            cout << "1. start from head\n";
                            cout << "2. traverse using 'next' pointer\n";
                            cout << "3. count each node\n";
                            cout << "4. stop when we reach head again (circular)\n";
                            cout << "5. use do-while loop to ensure at least one iteration\n";
                            
                            size = demo.findSizeDetailed();
                            
                            cout << "\ntime complexity: O(n)\n";
                            cout << "space complexity: O(1)\n";
                            cout << "\nimportant: must use do-while loop, not while loop!\n";
                            cout << "reason: condition (temp != head) is false initially\n";
                        }
                        break;
                        
                    case 6:
                        break;
                        
                    default:
                        cout << "invalid choice!\n";
                }
            } while(choice != 6);
        }
        else {
            cout << "invalid list type!\n";
        }
    } while(listType != 3);
    
    return 0;
}