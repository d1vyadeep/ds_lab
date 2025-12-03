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

    void makeCircular() {
        if(head == NULL) {
            return;
        }

        Node* temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = head;
        cout << "list converted to circular! last node now points to head.\n";
    }

    void displaySingly() {
        if(head == NULL) {
            cout << "list is empty!\n";
            return;
        }

        Node* temp = head;
        int count = 0;
        cout << "first 10 nodes: ";
        while(temp != NULL && count < 10) {
            cout << temp->data << " -> ";
            temp = temp->next;
            count++;
        }
        cout << (temp == NULL ? "NULL" : "...") << endl;
    }

    void displayCircular() {
        if(head == NULL) {
            cout << "list is empty!\n";
            return;
        }

        Node* temp = head;
        int count = 0;
        cout << "circular list (first 10 nodes): ";
        do {
            cout << temp->data;
            if(temp == head) cout << "(head)";
            cout << " -> ";
            temp = temp->next;
            count++;
        } while(temp != head && count < 10);
        cout << "(back to head)\n";
    }

    bool isCircularMethod1() {
        if(head == NULL) {
            return false;
        }

        Node* temp = head->next;

        while(temp != NULL && temp != head) {
            temp = temp->next;
        }

        return (temp == head);
    }

    bool isCircularMethod1Detailed() {
        if(head == NULL) {
            cout << "list is empty! not circular.\n";
            return false;
        }

        cout << "\nmethod 1: traverse until NULL or back to head\n";
        cout << "----------------------------------------------\n";

        Node* temp = head->next;
        int step = 1;

        cout << "starting from head->next\n";

        while(temp != NULL && temp != head) {
            cout << "step " << step << ": at node " << temp->data << endl;
            temp = temp->next;
            step++;

            if(step > 20) {
                cout << "... traversed 20+ nodes, likely circular\n";
                break;
            }
        }

        if(temp == NULL) {
            cout << "\nreached NULL! list is not circular.\n";
            return false;
        } else {
            cout << "\nreached head again! list is circular.\n";
            return true;
        }
    }

    bool isCircularMethod2() {
        if(head == NULL) {
            return false;
        }

        Node* slow = head;
        Node* fast = head;

        while(fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast) {
                return true;
            }
        }

        return false;
    }

    bool isCircularMethod2Detailed() {
        if(head == NULL) {
            cout << "list is empty! not circular.\n";
            return false;
        }

        cout << "\nmethod 2: floyd's cycle detection (slow & fast pointers)\n";
        cout << "--------------------------------------------------------\n";
        cout << "slow moves 1 step, fast moves 2 steps\n";
        cout << "if circular, they will meet; if not, fast reaches NULL\n\n";

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
                cout << ", fast = NULL";
            }

            if(slow == fast) {
                cout << " -> pointers met!\n";
                cout << "\nlist is circular! (cycle detected)\n";
                return true;
            }
            cout << endl;

            if(step > 15) {
                cout << "... limiting output\n";
                break;
            }
        }

        cout << "\nfast reached NULL! list is not circular.\n";
        return false;
    }
};

int main() {
    LinkedList ll;
    int choice, n, value;
    bool result;

    do {
        cout << "\n====== check if linked list is circular ======\n";
        cout << "1. create singly linked list\n";
        cout << "2. make list circular\n";
        cout << "3. display list\n";
        cout << "4. check if circular (method 1: traverse)\n";
        cout << "5. check if circular (method 2: floyd's cycle)\n";
        cout << "6. check if circular (method 1 - detailed)\n";
        cout << "7. check if circular (method 2 - detailed)\n";
        cout << "8. compare both methods\n";
        cout << "9. run demonstrations\n";
        cout << "10. exit\n";
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
                cout << "singly linked list created!\n";
                break;

            case 2:
                ll.makeCircular();
                break;

            case 3:
                cout << "attempting to display list...\n";
                ll.displaySingly();
                break;

            case 4:
                result = ll.isCircularMethod1();
                cout << "result: list is " << (result ? "circular" : "not circular") << endl;
                break;

            case 5:
                result = ll.isCircularMethod2();
                cout << "result: list is " << (result ? "circular" : "not circular") << endl;
                break;

            case 6:
                ll.isCircularMethod1Detailed();
                break;

            case 7:
                ll.isCircularMethod2Detailed();
                break;

            case 8:
                cout << "\n====== method comparison ======\n";

                cout << "\nmethod 1: traverse until NULL or head\n";
                result = ll.isCircularMethod1();
                cout << "result: " << (result ? "circular" : "not circular") << endl;
                cout << "time: O(n)\n";
                cout << "space: O(1)\n";
                cout << "pros: simple logic, direct check\n";
                cout << "cons: may traverse entire list\n";

                cout << "\nmethod 2: floyd's cycle detection\n";
                result = ll.isCircularMethod2();
                cout << "result: " << (result ? "circular" : "not circular") << endl;
                cout << "time: O(n)\n";
                cout << "space: O(1)\n";
                cout << "pros: efficient, detects any cycle\n";
                cout << "cons: slightly more complex\n";

                cout << "\nrecommendation: both are O(n), method 2 is more robust\n";
                break;

            case 9:
                {
                    cout << "\n====== demonstration 1: singly linked list ======\n";
                    LinkedList demo1;
                    int data1[] = {10, 20, 30, 40, 50};

                    for(int i = 0; i < 5; i++) {
                        demo1.insertAtEnd(data1[i]);
                    }

                    cout << "created list: 10 -> 20 -> 30 -> 40 -> 50 -> NULL\n";
                    demo1.displaySingly();

                    cout << "\nchecking if circular:\n";
                    result = demo1.isCircularMethod2Detailed();

                    cout << "\n====== demonstration 2: circular linked list ======\n";
                    LinkedList demo2;
                    int data2[] = {5, 10, 15, 20, 25};

                    for(int i = 0; i < 5; i++) {
                        demo2.insertAtEnd(data2[i]);
                    }

                    cout << "created list: 5 -> 10 -> 15 -> 20 -> 25 -> NULL\n";
                    demo2.makeCircular();
                    cout << "now: 5 -> 10 -> 15 -> 20 -> 25 -> (back to 5)\n";

                    cout << "\nchecking if circular:\n";
                    result = demo2.isCircularMethod2Detailed();

                    cout << "\n====== demonstration 3: single node circular ======\n";
                    LinkedList demo3;
                    demo3.insertAtEnd(100);
                    demo3.makeCircular();

                    cout << "created list: 100 -> (points to itself)\n";

                    cout << "\nchecking if circular:\n";
                    result = demo3.isCircularMethod1();
                    cout << "result: " << (result ? "circular" : "not circular") << endl;
                }
                break;

            case 10:
                cout << "exiting program...\n";
                break;

            default:
                cout << "invalid choice!\n";
        }
    } while(choice != 10);

    return 0;
}