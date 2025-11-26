#include <iostream>
#include <cstring>
using namespace std;

#define MAX 100

class Stack {
    int top;
    char arr[MAX];

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

    bool push(char ch) {
        if(isFull()) {
            cout << "stack overflow!\n";
            return false;
        }
        arr[++top] = ch;
        return true;
    }

    char pop() {
        if(isEmpty()) {
            return '\0';
        }
        return arr[top--];
    }

    void display() {
        if(isEmpty()) {
            cout << "stack is empty!\n";
            return;
        }
        cout << "stack (top to bottom): ";
        for(int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

void reverseString(char str[]) {
    Stack s;
    int len = strlen(str);

    cout << "\noriginal string: " << str << endl;
    cout << "length: " << len << endl;

    cout << "\n--- pushing characters onto stack ---\n";
    for(int i = 0; i < len; i++) {
        s.push(str[i]);
        cout << "pushed: '" << str[i] << "'\n";
    }

    cout << "\ncurrent ";
    s.display();

    cout << "\n--- popping characters from stack ---\n";
    for(int i = 0; i < len; i++) {
        str[i] = s.pop();
        cout << "popped: '" << str[i] << "'\n";
    }

    cout << "\nreversed string: " << str << endl;
}

void reverseStringSimple(char str[]) {
    Stack s;
    int len = strlen(str);

    for(int i = 0; i < len; i++) {
        s.push(str[i]);
    }

    for(int i = 0; i < len; i++) {
        str[i] = s.pop();
    }
}

int main() {
    char str[MAX];
    int choice;

    do {
        cout << "\n====== reverse string using stack ======\n";
        cout << "1. reverse string (detailed view)\n";
        cout << "2. reverse string (simple)\n";
        cout << "3. reverse multiple strings\n";
        cout << "4. example: reverse 'DataStructure'\n";
        cout << "5. exit\n";
        cout << "enter your choice: ";
        cin >> choice;

        switch(choice) {
            case 1:
                cout << "\nenter string: ";
                cin.ignore();
                cin.getline(str, MAX);
                reverseString(str);
                break;

            case 2:
                cout << "\nenter string: ";
                cin.ignore();
                cin.getline(str, MAX);
                cout << "original string: " << str << endl;
                reverseStringSimple(str);
                cout << "reversed string: " << str << endl;
                break;

            case 3:
                {
                    int n;
                    cout << "\nhow many strings to reverse? ";
                    cin >> n;
                    cin.ignore();

                    for(int i = 0; i < n; i++) {
                        cout << "\nstring " << i+1 << ": ";
                        cin.getline(str, MAX);
                        cout << "original: " << str << endl;
                        reverseStringSimple(str);
                        cout << "reversed: " << str << endl;
                    }
                }
                break;

            case 4:
                strcpy(str, "DataStructure");
                cout << "\nexample demonstration:\n";
                cout << "--------------------\n";
                reverseString(str);

                cout << "\n\nverification:\n";
                cout << "input:  DataStructure\n";
                cout << "output: " << str << endl;
                break;

            case 5:
                cout << "exiting program...\n";
                break;

            default:
                cout << "invalid choice!\n";
        }
    } while(choice != 5);

    return 0;
}