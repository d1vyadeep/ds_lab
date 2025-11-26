#include <iostream>
using namespace std;

#define MAX 100

class Stack {
    int top;
    int arr[MAX];
    
public:
    Stack() {
        top = -1;
    }
    
    bool isEmpty() {
        return (top < 0);
    }
    
    bool isFull() {
        return (top >= MAX - 1);
    }
    
    bool push(int value) {
        if(isFull()) {
            cout << "stack overflow! cannot push " << value << endl;
            return false;
        }
        arr[++top] = value;
        cout << value << " pushed into stack\n";
        return true;
    }
    
    int pop() {
        if(isEmpty()) {
            cout << "stack underflow! stack is empty\n";
            return -1;
        }
        int value = arr[top--];
        return value;
    }
    
    int peek() {
        if(isEmpty()) {
            cout << "stack is empty! no top element\n";
            return -1;
        }
        return arr[top];
    }
    
    void display() {
        if(isEmpty()) {
            cout << "stack is empty!\n";
            return;
        }
        cout << "stack elements (top to bottom):\n";
        for(int i = top; i >= 0; i--) {
            cout << "| " << arr[i] << " |";
            if(i == top) cout << " <-- top";
            cout << endl;
        }
        cout << "-----\n";
    }
    
    int size() {
        return top + 1;
    }
};

int main() {
    Stack s;
    int choice, value, poppedValue;
    
    do {
        cout << "\n====== stack operations menu ======\n";
        cout << "1. push()\n";
        cout << "2. pop()\n";
        cout << "3. isempty()\n";
        cout << "4. isfull()\n";
        cout << "5. display()\n";
        cout << "6. peek()\n";
        cout << "7. size()\n";
        cout << "8. exit\n";
        cout << "enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                cout << "enter value to push: ";
                cin >> value;
                s.push(value);
                break;
                
            case 2:
                poppedValue = s.pop();
                if(poppedValue != -1) {
                    cout << poppedValue << " popped from stack\n";
                }
                break;
                
            case 3:
                if(s.isEmpty()) {
                    cout << "stack is empty\n";
                } else {
                    cout << "stack is not empty\n";
                }
                break;
                
            case 4:
                if(s.isFull()) {
                    cout << "stack is full\n";
                } else {
                    cout << "stack is not full\n";
                }
                break;
                
            case 5:
                s.display();
                break;
                
            case 6:
                value = s.peek();
                if(value != -1) {
                    cout << "top element: " << value << endl;
                }
                break;
                
            case 7:
                cout << "current stack size: " << s.size() << endl;
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