#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

#define MAX 100

class Stack {
    int top;
    float arr[MAX];
    
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
    
    bool push(float value) {
        if(isFull()) {
            return false;
        }
        arr[++top] = value;
        return true;
    }
    
    float pop() {
        if(isEmpty()) {
            return 0;
        }
        return arr[top--];
    }
    
    float peek() {
        if(isEmpty()) {
            return 0;
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
            if(i < top) cout << ", ";
        }
        cout << "]";
    }
};

bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' || ch == '%');
}

bool isDigit(char ch) {
    return (ch >= '0' && ch <= '9');
}

float performOperation(float operand1, float operand2, char op) {
    switch(op) {
        case '+': return operand1 + operand2;
        case '-': return operand1 - operand2;
        case '*': return operand1 * operand2;
        case '/': 
            if(operand2 == 0) {
                cout << "\nerror: division by zero!\n";
                return 0;
            }
            return operand1 / operand2;
        case '^': return pow(operand1, operand2);
        case '%': return (int)operand1 % (int)operand2;
        default: return 0;
    }
}

float evaluatePostfixDetailed(char postfix[]) {
    Stack s;
    int i = 0;
    
    cout << "\npostfix expression: " << postfix << endl;
    cout << "\nevaluation steps:\n";
    cout << "--------------------------------------------------------\n";
    cout << "symbol\taction\t\t\tstack\n";
    cout << "--------------------------------------------------------\n";
    
    while(postfix[i] != '\0') {
        char ch = postfix[i];
        
        if(ch == ' ') {
            i++;
            continue;
        }
        
        cout << ch << "\t";
        
        if(isDigit(ch)) {
            float num = ch - '0';
            s.push(num);
            cout << "push operand " << num << "\t\t";
            s.display();
            cout << endl;
        }
        else if(isOperator(ch)) {
            if(s.isEmpty()) {
                cout << "error: insufficient operands!\n";
                return 0;
            }
            float operand2 = s.pop();
            
            if(s.isEmpty()) {
                cout << "error: insufficient operands!\n";
                return 0;
            }
            float operand1 = s.pop();
            
            float result = performOperation(operand1, operand2, ch);
            
            cout << "pop " << operand2 << ", pop " << operand1;
            cout << ", compute " << operand1 << ch << operand2 << "=" << result;
            cout << ", push " << result << "\t";
            
            s.push(result);
            s.display();
            cout << endl;
        }
        
        i++;
    }
    
    if(s.isEmpty()) {
        cout << "\nerror: invalid expression!\n";
        return 0;
    }
    
    float finalResult = s.pop();
    
    if(!s.isEmpty()) {
        cout << "\nwarning: extra operands in stack!\n";
    }
    
    cout << "\nfinal result: " << finalResult << endl;
    return finalResult;
}

float evaluatePostfixSimple(char postfix[]) {
    Stack s;
    int i = 0;
    
    while(postfix[i] != '\0') {
        char ch = postfix[i];
        
        if(ch == ' ') {
            i++;
            continue;
        }
        
        if(isDigit(ch)) {
            s.push(ch - '0');
        }
        else if(isOperator(ch)) {
            if(s.isEmpty()) return 0;
            float operand2 = s.pop();
            
            if(s.isEmpty()) return 0;
            float operand1 = s.pop();
            
            float result = performOperation(operand1, operand2, ch);
            s.push(result);
        }
        
        i++;
    }
    
    return s.isEmpty() ? 0 : s.pop();
}

int main() {
    char postfix[MAX];
    int choice;
    float result;
    
    do {
        cout << "\n====== postfix expression evaluation ======\n";
        cout << "1. evaluate expression (detailed)\n";
        cout << "2. evaluate expression (simple)\n";
        cout << "3. evaluate multiple expressions\n";
        cout << "4. run predefined examples\n";
        cout << "5. how postfix evaluation works\n";
        cout << "6. exit\n";
        cout << "enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                cout << "\nenter postfix expression: ";
                cin.ignore();
                cin.getline(postfix, MAX);
                evaluatePostfixDetailed(postfix);
                break;
                
            case 2:
                cout << "\nenter postfix expression: ";
                cin.ignore();
                cin.getline(postfix, MAX);
                result = evaluatePostfixSimple(postfix);
                cout << "\npostfix: " << postfix << endl;
                cout << "result:  " << result << endl;
                break;
                
            case 3:
                {
                    int n;
                    cout << "\nhow many expressions to evaluate? ";
                    cin >> n;
                    cin.ignore();
                    
                    for(int i = 0; i < n; i++) {
                        cout << "\nexpression " << i+1 << ": ";
                        cin.getline(postfix, MAX);
                        result = evaluatePostfixSimple(postfix);
                        cout << "result: " << result << endl;
                    }
                }
                break;
                
            case 4:
                {
                    cout << "\n====== predefined examples ======\n";
                    
                    struct Example {
                        char expr[50];
                        float expected;
                        char infix[50];
                    };
                    
                    Example examples[] = {
                        {"23+", 5, "2+3"},
                        {"23*", 6, "2*3"},
                        {"45-", -1, "4-5"},
                        {"82/", 4, "8/2"},
                        {"23^", 8, "2^3"},
                        {"234*+", 14, "2+(3*4)"},
                        {"23+4*", 20, "(2+3)*4"},
                        {"52/3*", 7.5, "(5/2)*3"},
                        {"923+*", 45, "9*(2+3)"},
                        {"234+*5-", 17, "2*(3+4)-5"}
                    };
                    
                    int numExamples = 10;
                    
                    for(int i = 0; i < numExamples; i++) {
                        result = evaluatePostfixSimple(examples[i].expr);
                        cout << "\nexample " << i+1 << ":\n";
                        cout << "postfix:  " << examples[i].expr << endl;
                        cout << "infix:    " << examples[i].infix << endl;
                        cout << "result:   " << result << endl;
                        cout << "expected: " << examples[i].expected << endl;
                        cout << "status:   " << (result == examples[i].expected ? "correct" : "check") << endl;
                    }
                }
                break;
                
            case 5:
                cout << "\n====== how postfix evaluation works ======\n";
                cout << "\nalgorithm:\n";
                cout << "1. scan the postfix expression left to right\n";
                cout << "2. if symbol is an operand (number):\n";
                cout << "   - push it onto the stack\n";
                cout << "3. if symbol is an operator (+, -, *, /, ^):\n";
                cout << "   - pop two operands from stack\n";
                cout << "   - first pop = operand2, second pop = operand1\n";
                cout << "   - perform operation: operand1 operator operand2\n";
                cout << "   - push result back onto stack\n";
                cout << "4. after scanning entire expression:\n";
                cout << "   - final result is on top of stack\n";
                
                cout << "\nexample: evaluate '234*+'\n";
                cout << "------------------------\n";
                cout << "symbol '2': push 2        -> stack: [2]\n";
                cout << "symbol '3': push 3        -> stack: [2, 3]\n";
                cout << "symbol '4': push 4        -> stack: [2, 3, 4]\n";
                cout << "symbol '*': pop 4, pop 3, 3*4=12, push 12 -> stack: [2, 12]\n";
                cout << "symbol '+': pop 12, pop 2, 2+12=14, push 14 -> stack: [14]\n";
                cout << "result: 14\n";
                
                cout << "\nadvantages of postfix:\n";
                cout << "- no parentheses needed\n";
                cout << "- no operator precedence rules needed\n";
                cout << "- easy to evaluate using stack\n";
                cout << "- efficient for computer evaluation\n";
                break;
                
            case 6:
                cout << "exiting program...\n";
                break;
                
            default:
                cout << "invalid choice!\n";
        }
    } while(choice != 6);
    
    return 0;
}