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
        cout << " -> NULL\n";
    }

    void reverseIterative() {
        Node* prev = NULL;
        Node* current = head;
        Node* next = NULL;

        while(current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        head = prev;
    }

    void reverseIterativeDetailed() {
        if(head == NULL) {
            cout << "list is empty!\n";
            return;
        }

        cout << "\nmethod 1: iterative reversal\n";
        cout << "-----------------------------\n";
        cout << "using three pointers: prev, current, next\n\n";

        Node* prev = NULL;
        Node* current = head;
        Node* next = NULL;
        int step = 0;

        cout << "initial state:\n";
        cout << "  prev = NULL\n";
        cout << "  current = " << current->data << " (head)\n";
        cout << "  list: ";
        display();

        while(current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            step++;

            cout << "\nstep " << step << ":\n";
            cout << "  next = " << (next ? to_string(next->data) : "NULL") << endl;
            cout << "  reversed link: " << prev->data << " -> " << (prev->next ? to_string(prev->next->data) : "NULL") << endl;
            cout << "  prev = " << prev->data << endl;
            cout << "  current = " << (current ? to_string(current->data) : "NULL") << endl;
        }

        head = prev;
        cout << "\nfinal: head updated to " << head->data << endl;
    }

    Node* reverseRecursiveHelper(Node* node) {
        if(node == NULL || node->next == NULL) {
            return node;
        }

        Node* newHead = reverseRecursiveHelper(node->next);
        node->next->next = node;
        node->next = NULL;

        return newHead;
    }

    void reverseRecursive() {
        head = reverseRecursiveHelper(head);
    }

    void reverseRecursiveDetailed() {
        if(head == NULL) {
            cout << "list is empty!\n";
            return;
        }

        cout << "\nmethod 2: recursive reversal\n";
        cout << "-----------------------------\n";
        cout << "recursively reverse from end, then fix links\n\n";

        cout << "original list: ";
        display();

        cout << "\nrecursion process:\n";
        cout << "1. reach the last node (base case)\n";
        cout << "2. make next node point back to current\n";
        cout << "3. set current's next to NULL\n";
        cout << "4. return new head (last node)\n";

        head = reverseRecursiveHelper(head);

        cout << "\nreversed list: ";
        display();
    }

    void reverseUsingStack() {
        if(head == NULL) {
            return;
        }

        int stack[100];
        int top = -1;

        Node* temp = head;
        while(temp != NULL) {
            stack[++top] = temp->data;
            temp = temp->next;
        }

        temp = head;
        while(temp != NULL) {
            temp->data = stack[top--];
            temp = temp->next;
        }
    }

    void reverseUsingStackDetailed() {
        if(head == NULL) {
            cout << "list is empty!\n";
            return;
        }

        cout << "\nmethod 3: using stack\n";
        cout << "---------------------\n";
        cout << "push all values to stack, then pop back to list\n\n";

        int stack[100];
        int top = -1;

        cout << "step 1: push all values to stack\n";
        Node* temp = head;
        while(temp != NULL) {
            stack[++top] = temp->data;
            cout << "  pushed " << temp->data << " to stack\n";
            temp = temp->next;
        }

        cout << "\nstep 2: pop from stack and assign back to list\n";
        temp = head;
        while(temp != NULL) {
            temp->data = stack[top];
            cout << "  popped " << stack[top] << " from stack, assigned to node\n";
            top--;
            temp = temp->next;
        }
    }
};

int main() {
    LinkedList ll;
    int choice, n, value;

    do {
        cout << "\n====== reverse a linked list ======\n";
        cout << "1. create linked list\n";
        cout << "2. display list\n";
        cout << "3. reverse (iterative - detailed)\n";
        cout << "4. reverse (recursive - detailed)\n";
        cout << "5. reverse using stack (detailed)\n";
        cout << "6. reverse (iterative - simple)\n";
        cout << "7. compare all methods\n";
        cout << "8. run sample example (1->2->3->4->NULL)\n";
        cout << "9. exit\n";
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
                cout << "original list: ";
                ll.display();
                ll.reverseIterativeDetailed();
                cout << "\nreversed list: ";
                ll.display();
                break;

            case 4:
                cout << "original list: ";
                ll.display();
                ll.reverseRecursiveDetailed();
                break;

            case 5:
                cout << "original list: ";
                ll.display();
                ll.reverseUsingStackDetailed();
                cout << "\nreversed list: ";
                ll.display();
                break;

            case 6:
                cout << "original list: ";
                ll.display();
                ll.reverseIterative();
                cout << "reversed list: ";
                ll.display();
                break;

            case 7:
                {
                    LinkedList test1, test2, test3;
                    int testData[] = {1, 2, 3, 4, 5};

                    for(int i = 0; i < 5; i++) {
                        test1.insertAtEnd(testData[i]);
                        test2.insertAtEnd(testData[i]);
                        test3.insertAtEnd(testData[i]);
                    }

                    cout << "\n====== method comparison ======\n";

                    cout << "\nmethod 1: iterative\n";
                    cout << "  time: O(n)\n";
                    cout << "  space: O(1)\n";
                    cout << "  advantages: most efficient, in-place\n";
                    test1.reverseIterative();
                    cout << "  result: ";
                    test1.display();

                    cout << "\nmethod 2: recursive\n";
                    cout << "  time: O(n)\n";
                    cout << "  space: O(n) [recursion stack]\n";
                    cout << "  advantages: elegant, concise code\n";
                    test2.reverseRecursive();
                    cout << "  result: ";
                    test2.display();

                    cout << "\nmethod 3: using stack\n";
                    cout << "  time: O(n)\n";
                    cout << "  space: O(n) [auxiliary stack]\n";
                    cout << "  advantages: straightforward logic\n";
                    test3.reverseUsingStack();
                    cout << "  result: ";
                    test3.display();

                    cout << "\nrecommendation: iterative method (most efficient)\n";
                }
                break;

            case 8:
                {
                    LinkedList sample;
                    int sampleData[] = {1, 2, 3, 4};

                    cout << "\n====== sample example ======\n";
                    cout << "input: ";
                    for(int i = 0; i < 4; i++) {
                        sample.insertAtEnd(sampleData[i]);
                    }
                    sample.display();

                    sample.reverseIterative();

                    cout << "output: ";
                    sample.display();
                    cout << "expected: 4 -> 3 -> 2 -> 1 -> NULL\n";
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