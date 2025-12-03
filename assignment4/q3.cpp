#include <iostream>
using namespace std;

#define MAX 100

class Queue {
    int front;
    int rear;
    int arr[MAX];
    
public:
    Queue() {
        front = -1;
        rear = -1;
    }
    
    bool isEmpty() {
        return (front == -1 || front > rear);
    }
    
    bool isFull() {
        return (rear == MAX - 1);
    }
    
    void enqueue(int value) {
        if(isFull()) {
            cout << "queue overflow!\n";
            return;
        }
        
        if(front == -1) {
            front = 0;
        }
        
        arr[++rear] = value;
    }
    
    int dequeue() {
        if(isEmpty()) {
            cout << "queue underflow!\n";
            return -1;
        }
        
        int value = arr[front++];
        
        if(front > rear) {
            front = -1;
            rear = -1;
        }
        
        return value;
    }
    
    int size() {
        if(isEmpty()) {
            return 0;
        }
        return rear - front + 1;
    }
    
    void display() {
        if(isEmpty()) {
            cout << "queue is empty!\n";
            return;
        }
        
        for(int i = front; i <= rear; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

class Stack {
    int top;
    int arr[MAX];
    
public:
    Stack() {
        top = -1;
    }
    
    bool isEmpty() {
        return (top == -1);
    }
    
    bool isFull() {
        return (top == MAX - 1);
    }
    
    void push(int value) {
        if(isFull()) {
            return;
        }
        arr[++top] = value;
    }
    
    int pop() {
        if(isEmpty()) {
            return -1;
        }
        return arr[top--];
    }
};

void interleaveQueueDetailed(Queue &q) {
    int n = q.size();
    
    if(n == 0) {
        cout << "queue is empty!\n";
        return;
    }
    
    if(n % 2 != 0) {
        cout << "queue size must be even for interleaving!\n";
        return;
    }
    
    cout << "\noriginal queue: ";
    q.display();
    
    Stack s;
    int halfSize = n / 2;
    
    cout << "\nstep 1: move first half to stack\n";
    for(int i = 0; i < halfSize; i++) {
        int val = q.dequeue();
        s.push(val);
        cout << "  dequeued " << val << " from queue, pushed to stack\n";
    }
    
    cout << "\nstep 2: move from stack back to queue (reverses first half)\n";
    while(!s.isEmpty()) {
        int val = s.pop();
        q.enqueue(val);
        cout << "  popped " << val << " from stack, enqueued to queue\n";
    }
    
    cout << "\nqueue after reversing first half: ";
    q.display();
    
    cout << "\nstep 3: move second half (originally) to end\n";
    for(int i = 0; i < halfSize; i++) {
        int val = q.dequeue();
        q.enqueue(val);
        cout << "  dequeued " << val << ", enqueued back\n";
    }
    
    cout << "\nqueue now: ";
    q.display();
    
    cout << "\nstep 4: move first half again to stack\n";
    for(int i = 0; i < halfSize; i++) {
        int val = q.dequeue();
        s.push(val);
        cout << "  dequeued " << val << " from queue, pushed to stack\n";
    }
    
    cout << "\nstep 5: interleave - pop from stack and dequeue alternately\n";
    for(int i = 0; i < halfSize; i++) {
        int val1 = s.pop();
        q.enqueue(val1);
        cout << "  popped " << val1 << " from stack, enqueued\n";
        
        int val2 = q.dequeue();
        q.enqueue(val2);
        cout << "  dequeued " << val2 << " from queue, enqueued\n";
    }
    
    cout << "\nfinal interleaved queue: ";
    q.display();
}

void interleaveQueueSimple(Queue &q) {
    int n = q.size();
    
    if(n == 0) {
        cout << "queue is empty!\n";
        return;
    }
    
    if(n % 2 != 0) {
        cout << "queue size must be even for interleaving!\n";
        return;
    }
    
    Stack s;
    int halfSize = n / 2;
    
    for(int i = 0; i < halfSize; i++) {
        s.push(q.dequeue());
    }
    
    while(!s.isEmpty()) {
        q.enqueue(s.pop());
    }
    
    for(int i = 0; i < halfSize; i++) {
        q.enqueue(q.dequeue());
    }
    
    for(int i = 0; i < halfSize; i++) {
        s.push(q.dequeue());
    }
    
    for(int i = 0; i < halfSize; i++) {
        q.enqueue(s.pop());
        q.enqueue(q.dequeue());
    }
}

int main() {
    Queue q;
    int choice, n, value;
    
    do {
        cout << "\n====== interleave queue halves ======\n";
        cout << "1. create queue\n";
        cout << "2. display queue\n";
        cout << "3. interleave (detailed steps)\n";
        cout << "4. interleave (simple)\n";
        cout << "5. run sample example (4 7 11 20 5 9)\n";
        cout << "6. exit\n";
        cout << "enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                q = Queue();
                cout << "enter number of elements (must be even): ";
                cin >> n;
                
                if(n % 2 != 0) {
                    cout << "error: number of elements must be even!\n";
                    break;
                }
                
                cout << "enter " << n << " elements:\n";
                for(int i = 0; i < n; i++) {
                    cin >> value;
                    q.enqueue(value);
                }
                cout << "queue created successfully!\n";
                break;
                
            case 2:
                cout << "current queue: ";
                q.display();
                break;
                
            case 3:
                interleaveQueueDetailed(q);
                break;
                
            case 4:
                cout << "\noriginal queue: ";
                q.display();
                interleaveQueueSimple(q);
                cout << "interleaved queue: ";
                q.display();
                break;
                
            case 5:
                {
                    Queue sampleQ;
                    int sample[] = {4, 7, 11, 20, 5, 9};
                    int sampleSize = 6;
                    
                    cout << "\nsample input: ";
                    for(int i = 0; i < sampleSize; i++) {
                        sampleQ.enqueue(sample[i]);
                        cout << sample[i] << " ";
                    }
                    cout << endl;
                    
                    interleaveQueueSimple(sampleQ);
                    
                    cout << "sample output: ";
                    sampleQ.display();
                    cout << "expected:      4 20 7 5 11 9\n";
                }
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