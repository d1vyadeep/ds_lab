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
    
    char peek() {
        if(isEmpty()) {
            return '\0';
        }
        return arr[top];
    }
    
    void display() {
        if(isEmpty()) {
            cout << "stack: [empty]";
            return;
        }
        cout << "stack: [";
        for(int i = 0; i <= top; i++) {
            cout << arr[i];
            if(i < top) cout << ", ";
        }
        cout << "]";
    }
};

bool isOpeningBracket(char ch) {
    return (ch == '(' || ch == '{' || ch == '[');
}

bool isClosingBracket(char ch) {
    return (ch == ')' || ch == '}' || ch == ']');
}

bool isMatchingPair(char opening, char closing) {
    return ((opening == '(' && closing == ')') ||
            (opening == '{' && closing == '}') ||
            (opening == '[' && closing == ']'));
}

bool checkBalancedDetailed(char expr[]) {
    Stack s;
    int len = strlen(expr);
    
    cout << "\nexpression: " << expr << endl;
    cout << "\nchecking step by step:\n";
    cout << "----------------------\n";
    
    for(int i = 0; i < len; i++) {
        char ch = expr[i];
        
        if(isOpeningBracket(ch)) {
            s.push(ch);
            cout << "position " << i << ": '" << ch << "' -> opening bracket, push to stack | ";
            s.display();
            cout << endl;
        }
        else if(isClosingBracket(ch)) {
            cout << "position " << i << ": '" << ch << "' -> closing bracket";
            
            if(s.isEmpty()) {
                cout << " | stack is empty! no matching opening bracket\n";
                cout << "\nresult: not balanced (extra closing bracket)\n";
                return false;
            }
            
            char top = s.pop();
            cout << " | popped '" << top << "' from stack";
            
            if(!isMatchingPair(top, ch)) {
                cout << " | mismatch! '" << top << "' doesn't match '" << ch << "'\n";
                cout << "\nresult: not balanced (mismatched brackets)\n";
                return false;
            }
            
            cout << " | matched! | ";
            s.display();
            cout << endl;
        }
        else {
            cout << "position " << i << ": '" << ch << "' -> other character, skip\n";
        }
    }
    
    if(!s.isEmpty()) {
        cout << "\nstack still contains: ";
        s.display();
        cout << "\nresult: not balanced (extra opening brackets)\n";
        return false;
    }
    
    cout << "\nstack is empty!\n";
    cout << "result: balanced\n";
    return true;
}

bool checkBalancedSimple(char expr[]) {
    Stack s;
    int len = strlen(expr);
    
    for(int i = 0; i < len; i++) {
        char ch = expr[i];
        
        if(isOpeningBracket(ch)) {
            s.push(ch);
        }
        else if(isClosingBracket(ch)) {
            if(s.isEmpty()) {
                return false;
            }
            
            char top = s.pop();
            
            if(!isMatchingPair(top, ch)) {
                return false;
            }
        }
    }
    
    return s.isEmpty();
}

int main() {
    char expr[MAX];
    int choice;
    
    do {
        cout << "\n====== check balanced parentheses ======\n";
        cout << "1. check expression (detailed)\n";
        cout << "2. check expression (simple)\n";
        cout << "3. test multiple expressions\n";
        cout << "4. run predefined examples\n";
        cout << "5. exit\n";
        cout << "enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                cout << "\nenter expression: ";
                cin.ignore();
                cin.getline(expr, MAX);
                checkBalancedDetailed(expr);
                break;
                
            case 2:
                cout << "\nenter expression: ";
                cin.ignore();
                cin.getline(expr, MAX);
                cout << "expression: " << expr << endl;
                if(checkBalancedSimple(expr)) {
                    cout << "result: balanced\n";
                } else {
                    cout << "result: not balanced\n";
                }
                break;
                
            case 3:
                {
                    int n;
                    cout << "\nhow many expressions to check? ";
                    cin >> n;
                    cin.ignore();
                    
                    for(int i = 0; i < n; i++) {
                        cout << "\nexpression " << i+1 << ": ";
                        cin.getline(expr, MAX);
                        cout << "result: " << (checkBalancedSimple(expr) ? "balanced" : "not balanced") << endl;
                    }
                }
                break;
                
            case 4:
                cout << "\n====== predefined examples ======\n";
                
                char* examples[] = {
                    "(a+b)*(c-d)",
                    "{[a+b]*(c-d)}",
                    "[(a+b)*{c-d}]",
                    "(a+b]",
                    "((a+b)",
                    "{[a+b}]",
                    ")a+b(",
                    "a+b+c",
                    "{[(x+y)*(a-b)]}",
                    "((a+b)*[c-d]"
                };
                
                int numExamples = 10;
                
                for(int i = 0; i < numExamples; i++) {
                    cout << "\nexample " << i+1 << ": " << examples[i];
                    cout << " -> " << (checkBalancedSimple(examples[i]) ? "balanced" : "not balanced") << endl;
                }
                break;
                
            case 5:
                cout << "exiting program...\n";
                break;
                
            default:
                cout << "invalid choice!\n";
        }
    } while(choice != 5);
    
    return 0;