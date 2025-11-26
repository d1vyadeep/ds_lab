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
            cout << "[empty]";
            return;
        }
        cout << "[";
        for(int i = 0; i <= top; i++) {
            cout << arr[i];
            if(i < top) cout << " ";
        }
        cout << "]";
    }
};

bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '%');
}

bool isOperand(char ch) {
    return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'));
}

int getPrecedence(char ch) {
    if(ch == '^')
        return 3;
    else if(ch == '*' || ch == '/' || ch == '%')
        return 2;
    else if(ch == '+' || ch == '-')
        return 1;
    else
        return 0;
}

bool isRightAssociative(char ch) {
    return (ch == '^');
}

void infixToPostfixDetailed(char infix[], char postfix[]) {
    Stack s;
    int i = 0, j = 0;
    
    cout << "\ninfix expression: " << infix << endl;
    cout << "\nconversion steps:\n";
    cout << "---------------------------------------------------\n";
    cout << "symbol\taction\t\tstack\t\tpostfix\n";
    cout << "---------------------------------------------------\n";
    
    while(infix[i] != '\0') {
        char ch = infix[i];
        
        cout << ch << "\t";
        
        if(ch == ' ') {
            i++;
            continue;
        }
        
        if(isOperand(ch)) {
            postfix[j++] = ch;
            cout << "add to output\t";
            s.display();
            cout << "\t\t" << postfix << endl;
        }
        else if(ch == '(') {
            s.push(ch);
            cout << "push to stack\t";
            s.display();
            cout << "\t\t" << postfix << endl;
        }
        else if(ch == ')') {
            cout << "pop till '('\t";
            while(!s.isEmpty() && s.peek() != '(') {
                postfix[j++] = s.pop();
            }
            if(!s.isEmpty()) {
                s.pop();
            }
            s.display();
            cout << "\t\t" << postfix << endl;
        }
        else if(isOperator(ch)) {
            while(!s.isEmpty() && s.peek() != '(' && 
                  ((getPrecedence(s.peek()) > getPrecedence(ch)) ||
                   (getPrecedence(s.peek()) == getPrecedence(ch) && !isRightAssociative(ch)))) {
                postfix[j++] = s.pop();
            }
            s.push(ch);
            cout << "process op\t";
            s.display();
            cout << "\t\t" << postfix << endl;
        }
        
        i++;
    }
    
    cout << "\npop remaining operators:\n";
    while(!s.isEmpty()) {
        postfix[j++] = s.pop();
        cout << "pop\t\t";
        s.display();
        cout << "\t\t" << postfix << endl;
    }
    
    postfix[j] = '\0';
    cout << "\nfinal postfix expression: " << postfix << endl;
}

void infixToPostfixSimple(char infix[], char postfix[]) {
    Stack s;
    int i = 0, j = 0;
    
    while(infix[i] != '\0') {
        char ch = infix[i];
        
        if(ch == ' ') {
            i++;
            continue;
        }
        
        if(isOperand(ch)) {
            postfix[j++] = ch;
        }
        else if(ch == '(') {
            s.push(ch);
        }
        else if(ch == ')') {
            while(!s.isEmpty() && s.peek() != '(') {
                postfix[j++] = s.pop();
            }
            if(!s.isEmpty()) {
                s.pop();
            }
        }
        else if(isOperator(ch)) {
            while(!s.isEmpty() && s.peek() != '(' && 
                  ((getPrecedence(s.peek()) > getPrecedence(ch)) ||
                   (getPrecedence(s.peek()) == getPrecedence(ch) && !isRightAssociative(ch)))) {
                postfix[j++] = s.pop();
            }
            s.push(ch);
        }
        
        i++;
    }
    
    while(!s.isEmpty()) {
        postfix[j++] = s.pop();
    }
    
    postfix[j] = '\0';
}

int main() {
    char infix[MAX], postfix[MAX];
    int choice;
    
    do {
        cout << "\n====== infix to postfix conversion ======\n";
        cout << "1. convert expression (detailed)\n";
        cout << "2. convert expression (simple)\n";
        cout << "3. convert multiple expressions\n";
        cout << "4. run predefined examples\n";
        cout << "5. operator precedence guide\n";
        cout << "6. exit\n";
        cout << "enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                cout << "\nenter infix expression: ";
                cin.ignore();
                cin.getline(infix, MAX);
                infixToPostfixDetailed(infix, postfix);
                break;
                
            case 2:
                cout << "\nenter infix expression: ";
                cin.ignore();
                cin.getline(infix, MAX);
                infixToPostfixSimple(infix, postfix);
                cout << "\ninfix:   " << infix << endl;
                cout << "postfix: " << postfix << endl;
                break;
                
            case 3:
                {
                    int n;
                    cout << "\nhow many expressions to convert? ";
                    cin >> n;
                    cin.ignore();
                    
                    for(int i = 0; i < n; i++) {
                        cout << "\nexpression " << i+1 << ": ";
                        cin.getline(infix, MAX);
                        infixToPostfixSimple(infix, postfix);
                        cout << "infix:   " << infix << endl;
                        cout << "postfix: " << postfix << endl;
                    }
                }
                break;
                
            case 4:
                {
                    cout << "\n====== predefined examples ======\n";
                    
                    char* examples[][2] = {
                        {"a+b", "ab+"},
                        {"a+b*c", "abc*+"},
                        {"(a+b)*c", "ab+c*"},
                        {"a+b*c-d", "abc*+d-"},
                        {"(a+b)*(c-d)", "ab+cd-*"},
                        {"a^b^c", "abc^^"},
                        {"a+b-c*d/e", "ab+cd*e/-"},
                        {"((a+b)*c-d)/e", "ab+c*d-e/"},
                        {"a*(b+c)/d", "abc+*d/"},
                        {"a+b*(c^d-e)^(f+g*h)-i", "abcd^e-fgh*+^*+i-"}
                    };
                    
                    int numExamples = 10;
                    
                    for(int i = 0; i < numExamples; i++) {
                        infixToPostfixSimple(examples[i][0], postfix);
                        cout << "\nexample " << i+1 << ":\n";
                        cout << "infix:    " << examples[i][0] << endl;
                        cout << "postfix:  " << postfix << endl;
                        cout << "expected: " << examples[i][1] << endl;
                        cout << "status:   " << (strcmp(postfix, examples[i][1]) == 0 ? "correct" : "incorrect") << endl;
                    }
                }
                break;
                
            case 5:
                cout << "\n====== operator precedence guide ======\n";
                cout << "operator\tprecedence\tassociativity\n";
                cout << "----------------------------------------\n";
                cout << "^\t\t3 (highest)\tright to left\n";
                cout << "*, /, %\t\t2\t\tleft to right\n";
                cout << "+, -\t\t1 (lowest)\tleft to right\n";
                cout << "()\t\thighest priority (grouping)\n";
                cout << "\nrules:\n";
                cout << "1. operands go directly to output\n";
                cout << "2. operators are pushed to stack\n";
                cout << "3. higher precedence operators pop lower ones\n";
                cout << "4. '(' has special handling - pop till ')'\n";
                cout << "5. at end, pop all remaining operators\n";
                break;
                
            case 6:
                cout << "exiting program...\n";
                break;
                
            default:
                cout << "invalid choice!\n";
        }
    } while(choice != 6);
    
    return 0;