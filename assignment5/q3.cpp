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
    
    int findMiddleMethod1() {
        if(head == NULL) {
            cout << "list is empty!\n";
            return -1;
        }
        
        int count = 0;
        Node* temp = head;
        
        while(temp != NULL) {
            count++;
            temp = temp->next;
        }
        
        int middle = count / 2;
        
        temp = head;
        for(int i = 0; i < middle; i++) {
            temp = temp->next;
        }
        
        return temp->data;
    }
    
    int findMiddleMethod1Detailed() {
        if(head == NULL) {
            cout << "list is empty!\n";
            return -1;
        }
        
        cout << "\nmethod 1: count nodes, then traverse to middle\n";
        cout << "----------------------------------------------\n";
        
        int count = 0;
        Node* temp = head;
        
        cout << "step 1: count total nodes\n";
        while(temp != NULL) {
            count++;
            temp = temp->next;
        }
        cout << "  total nodes = " << count << endl;
        
        int middle = count / 2;
        cout << "\nstep 2: find middle position\n";
        cout << "  middle position = " << count << " / 2 = " << middle << endl;
        
        cout << "\nstep 3: traverse to position " << middle << endl;
        temp = head;
        for(int i = 0; i < middle; i++) {
            cout << "  moving to next node (" << temp->data << " -> " << temp->next->data << ")\n";
            temp = temp->next;
        }
        
        cout << "\nmiddle element: " << temp->data << endl;
        return temp->data;
    }
    
    int findMiddleMethod2() {
        if(head == NULL) {
            cout << "list is empty!\n";
            return -1;
        }
        
        Node* slow = head;
        Node* fast = head;
        
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
        return slow->data;
    }
    
    int findMiddleMethod2Detailed() {
        if(head == NULL) {
            cout << "list is empty!\n";
            return -1;
        }
        
        cout << "\nmethod 2: two pointer technique (slow and fast)\n";
        cout << "------------------------------------------------\n";
        cout << "slow pointer moves 1 step, fast pointer moves 2 steps\n";
        cout << "when fast reaches end, slow will be at middle\n\n";
        
        Node* slow = head;
        Node* fast = head;
        int step = 0;
        
        cout << "initial: slow = " << slow->data << ", fast = " << fast->data << endl;
        
        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
            step++;
            
            cout << "step " << step << ": slow = " << slow->data;
            if(fast != NULL) {
                cout << ", fast = " << fast->data;
            } else {
                cout << ", fast = NULL (reached end)";
            }
            cout << endl;
        }
        
        cout << "\nmiddle element: " << slow->data << endl;
        return slow->data;
    }
};

int main() {
    LinkedList ll;
    int choice, n, value;
    
    do {
        cout << "\n====== find middle of linked list ======\n";
        cout << "1. create linked list\n";
        cout << "2. display list\n";
        cout << "3. find middle (method 1: count then traverse)\n";
        cout << "4. find middle (method 2: two pointers)\n";
        cout << "5. compare both methods\n";
        cout << "6. run sample example (1->2->3->4->5)\n";
        cout << "7. run more examples\n";
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
                cout << "linked list: ";
                ll.display();
                value = ll.findMiddleMethod1Detailed();
                break;
                
            case 4:
                cout << "linked list: ";
                ll.display();
                value = ll.findMiddleMethod2Detailed();
                break;
                
            case 5:
                cout << "linked list: ";
                ll.display();
                
                cout << "\n====== comparison ======\n";
                
                cout << "\nmethod 1: count then traverse\n";
                value = ll.findMiddleMethod1();
                cout << "middle: " << value << endl;
                cout << "time: O(n) + O(n/2) = O(n)\n";
                cout << "space: O(1)\n";
                cout << "passes: 2 (one to count, one to reach middle)\n";
                
                cout << "\nmethod 2: two pointers (slow and fast)\n";
                value = ll.findMiddleMethod2();
                cout << "middle: " << value << endl;
                cout << "time: O(n/2) = O(n)\n";
                cout << "space: O(1)\n";
                cout << "passes: 1 (single traversal)\n";
                
                cout << "\nrecommendation: method 2 is more efficient (single pass)\n";
                break;
                
            case 6:
                {
                    LinkedList sample;
                    int sampleData[] = {1, 2, 3, 4, 5};
                    int sampleSize = 5;
                    
                    cout << "\n====== sample example ======\n";
                    cout << "input: ";
                    for(int i = 0; i < sampleSize; i++) {
                        sample.insertAtEnd(sampleData[i]);
                    }
                    sample.display();
                    
                    value = sample.findMiddleMethod2();
                    cout << "output: " << value << endl;
                    cout << "expected: 3\n";
                }
                break;
                
            case 7:
                {
                    cout << "\n====== more examples ======\n";
                    
                    int examples[][10] = {
                        {1, 2, 3, 4, 5},
                        {1, 2, 3, 4, 5, 6},
                        {1, 2, 3},
                        {10, 20},
                        {100}
                    };
                    int sizes[] = {5, 6, 3, 2, 1};
                    int expected[] = {3, 4, 2, 20, 100};
                    
                    for(int i = 0; i < 5; i++) {
                        LinkedList test;
                        cout << "\nexample " << i+1 << ":\n";
                        cout << "input: ";
                        for(int j = 0; j < sizes[i]; j++) {
                            test.insertAtEnd(examples[i][j]);
                        }
                        test.display();
                        
                        value = test.findMiddleMethod2();
                        cout << "middle: " << value << endl;
                        cout << "expected: " << expected[i] << endl;
                        
                        if(sizes[i] % 2 == 0) {
                            cout << "note: even length, returning second middle element\n";
                        }
                    }
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