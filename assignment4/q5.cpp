#include <iostream>
using namespace std;

#define MAX 100

class Queue {
public:
    int front;
    int rear;
    int arr[MAX];
    
    Queue() {
        front = -1;
        rear = -1;
    }
    
    bool isEmpty() {
        return (front == -1 || front > rear);
    }
    
    void enqueue(int value) {
        if(front == -1) {
            front = 0;
        }
        arr[++rear] = value;
    }
    
    int dequeue() {
        if(isEmpty()) {
            return -1;
        }
        
        int value = arr[front++];
        
        if(front > rear) {
            front = -1;
            rear = -1;
        }
        
        return value;
    }
    
    int peek() {
        if(isEmpty()) {
            return -1;
        }
        return arr[front];
    }
    
    int size() {
        if(isEmpty()) {
            return 0;
        }
        return rear - front + 1;
    }
};

class StackUsingTwoQueues {
    Queue q1, q2;
    
public:
    void push(int value) {
        q2.enqueue(value);
        
        while(!q1.isEmpty()) {
            q2.enqueue(q1.dequeue());
        }
        
        Queue temp = q1;
        q1 = q2;
        q2 = temp;
        
        cout << value << " pushed to stack (using two queues)\n";
    }
    
    int pop() {
        if(q1.isEmpty()) {
            cout << "stack underflow!\n";
            return -1;
        }
        
        return q1.dequeue();
    }
    
    int top() {
        if(q1.isEmpty()) {
            cout << "stack is empty!\n";
            return -1;
        }
        
        return q1.peek();
    }
    
    bool isEmpty() {
        return q1.isEmpty();
    }
    
    void display() {
        if(q1.isEmpty()) {
            cout << "stack is empty!\n";
            return;
        }
        
        cout << "stack (top to bottom): ";
        for(int i = q1.front; i <= q1.rear; i++) {
            cout << q1.arr[i] << " ";
        }
        cout << endl;
    }
    
    void showQueues() {
        cout << "q1: ";
        if(q1.isEmpty()) {
            cout << "[empty]";
        } else {
            cout << "[";
            for(int i = q1.front; i <= q1.rear; i++) {
                cout << q1.arr[i];
                if(i < q1.rear) cout << ", ";
            }
            cout << "]";
        }
        
        cout << " | q2: ";
        if(q2.isEmpty()) {
            cout << "[empty]";
        } else {
            cout << "[";
            for(int i = q2.front; i <= q2.rear; i++) {
                cout << q2.arr[i];
                if(i < q2.rear) cout << ", ";
            }
            cout << "]";
        }
        cout << endl;
    }
};

class StackUsingOneQueue {
    Queue q;
    
public:
    void push(int value) {
        int size = q.size();
        
        q.enqueue(value);
        
        for(int i = 0; i < size; i++) {
            q.enqueue(q.dequeue());
        }
        
        cout << value << " pushed to stack (using one queue)\n";
    }
    
    int pop() {
        if(q.isEmpty()) {
            cout << "stack underflow!\n";
            return -1;
        }
        
        return q.dequeue();
    }
    
    int top() {
        if(q.isEmpty()) {
            cout << "stack is empty!\n";
            return -1;
        }
        
        return q.peek();
    }
    
    bool isEmpty() {
        return q.isEmpty();
    }
    
    void display() {
        if(q.isEmpty()) {
            cout << "stack is empty!\n";
            return;
        }
        
        cout << "stack (top to bottom): ";
        for(int i = q.front; i <= q.rear; i++) {
            cout << q.arr[i] << " ";
        }
        cout << endl;
    }
    
    void showQueue() {
        cout << "queue state: ";
        if(q.isEmpty()) {
            cout << "[empty]";
        } else {
            cout << "[";
            for(int i = q.front; i <= q.rear; i++) {
                cout << q.arr[i];
                if(i < q.rear) cout << ", ";
            }
            cout << "]";
        }
        cout << endl;
    }
};

int main() {
    StackUsingTwoQueues stack2Q;
    StackUsingOneQueue stack1Q;
    int choice, method, value, poppedValue;
    
    do {
        cout << "\n====== stack using queues ======\n";
        cout << "1. stack using two queues\n";
        cout << "2. stack using one queue\n";
        cout << "3. exit\n";
        cout << "select implementation: ";
        cin >> method;
        
        if(method == 3) {
            cout << "exiting program...\n";
            break;
        }
        
        if(method == 1) {
            do {
                cout << "\n--- stack using two queues ---\n";
                cout << "1. push\n";
                cout << "2. pop\n";
                cout << "3. top\n";
                cout << "4. isempty\n";
                cout << "5. display stack\n";
                cout << "6. show queues state\n";
                cout << "7. demonstration\n";
                cout << "8. back to main menu\n";
                cout << "enter your choice: ";
                cin >> choice;
                
                switch(choice) {
                    case 1:
                        cout << "enter value: ";
                        cin >> value;
                        stack2Q.push(value);
                        break;
                        
                    case 2:
                        poppedValue = stack2Q.pop();
                        if(poppedValue != -1) {
                            cout << poppedValue << " popped from stack\n";
                        }
                        break;
                        
                    case 3:
                        value = stack2Q.top();
                        if(value != -1) {
                            cout << "top element: " << value << endl;
                        }
                        break;
                        
                    case 4:
                        if(stack2Q.isEmpty()) {
                            cout << "stack is empty\n";
                        } else {
                            cout << "stack is not empty\n";
                        }
                        break;
                        
                    case 5:
                        stack2Q.display();
                        break;
                        
                    case 6:
                        stack2Q.showQueues();
                        break;
                        
                    case 7:
                        {
                            cout << "\n====== demonstration: stack using two queues ======\n";
                            StackUsingTwoQueues demo;
                            
                            cout << "\npush(10):\n";
                            demo.push(10);
                            demo.showQueues();
                            
                            cout << "\npush(20):\n";
                            demo.push(20);
                            demo.showQueues();
                            
                            cout << "\npush(30):\n";
                            demo.push(30);
                            demo.showQueues();
                            
                            cout << "\nstack: ";
                            demo.display();
                            
                            cout << "\npop():\n";
                            cout << demo.pop() << " popped\n";
                            demo.showQueues();
                            
                            cout << "\nlogic: push is costly O(n), pop is O(1)\n";
                            cout << "- on push: enqueue to q2, move all from q1 to q2, swap q1 and q2\n";
                            cout << "- on pop: simply dequeue from q1\n";
                        }
                        break;
                        
                    case 8:
                        break;
                        
                    default:
                        cout << "invalid choice!\n";
                }
            } while(choice != 8);
        }
        else if(method == 2) {
            do {
                cout << "\n--- stack using one queue ---\n";
                cout << "1. push\n";
                cout << "2. pop\n";
                cout << "3. top\n";
                cout << "4. isempty\n";
                cout << "5. display stack\n";
                cout << "6. show queue state\n";
                cout << "7. demonstration\n";
                cout << "8. back to main menu\n";
                cout << "enter your choice: ";
                cin >> choice;
                
                switch(choice) {
                    case 1:
                        cout << "enter value: ";
                        cin >> value;
                        stack1Q.push(value);
                        break;
                        
                    case 2:
                        poppedValue = stack1Q.pop();
                        if(poppedValue != -1) {
                            cout << poppedValue << " popped from stack\n";
                        }
                        break;
                        
                    case 3:
                        value = stack1Q.top();
                        if(value != -1) {
                            cout << "top element: " << value << endl;
                        }
                        break;
                        
                    case 4:
                        if(stack1Q.isEmpty()) {
                            cout << "stack is empty\n";
                        } else {
                            cout << "stack is not empty\n";
                        }
                        break;
                        
                    case 5:
                        stack1Q.display();
                        break;
                        
                    case 6:
                        stack1Q.showQueue();
                        break;
                        
                    case 7:
                        {
                            cout << "\n====== demonstration: stack using one queue ======\n";
                            StackUsingOneQueue demo;
                            
                            cout << "\npush(10):\n";
                            cout << "  step 1: enqueue 10 -> [10]\n";
                            cout << "  step 2: no rotation needed (size was 0)\n";
                            demo.push(10);
                            demo.showQueue();
                            
                            cout << "\npush(20):\n";
                            cout << "  step 1: enqueue 20 -> [10, 20]\n";
                            cout << "  step 2: rotate 1 time -> dequeue 10, enqueue 10 -> [20, 10]\n";
                            demo.push(20);
                            demo.showQueue();
                            
                            cout << "\npush(30):\n";
                            cout << "  step 1: enqueue 30 -> [20, 10, 30]\n";
                            cout << "  step 2: rotate 2 times\n";
                            cout << "          dequeue 20, enqueue 20 -> [10, 30, 20]\n";
                            cout << "          dequeue 10, enqueue 10 -> [30, 20, 10]\n";
                            demo.push(30);
                            demo.showQueue();
                            
                            cout << "\nstack: ";
                            demo.display();
                            
                            cout << "\npop():\n";
                            cout << demo.pop() << " popped\n";
                            demo.showQueue();
                            
                            cout << "\nlogic: push is costly O(n), pop is O(1)\n";
                            cout << "- on push: enqueue element, then rotate queue (size-1) times\n";
                            cout << "- on pop: simply dequeue from front\n";
                        }
                        break;
                        
                    case 8:
                        break;
                        
                    default:
                        cout << "invalid choice!\n";
                }
            } while(choice != 8);
        }
        else {
            cout << "invalid method selection!\n";
        }
    } while(method != 3);
    
    return 0;
}