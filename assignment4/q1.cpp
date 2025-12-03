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
    
    bool enqueue(int value) {
        if(isFull()) {
            cout << "queue overflow! cannot enqueue " << value << endl;
            return false;
        }
        
        if(front == -1) {
            front = 0;
        }
        
        arr[++rear] = value;
        cout << value << " enqueued into queue\n";
        return true;
    }
    
    int dequeue() {
        if(isEmpty()) {
            cout << "queue underflow! queue is empty\n";
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
            cout << "queue is empty! no front element\n";
            return -1;
        }
        return arr[front];
    }
    
    void display() {
        if(isEmpty()) {
            cout << "queue is empty!\n";
            return;
        }
        
        cout << "queue elements (front to rear):\n";
        cout << "front -> ";
        for(int i = front; i <= rear; i++) {
            cout << "[ " << arr[i] << " ] ";
        }
        cout << "<- rear\n";
    }
    
    int size() {
        if(isEmpty()) {
            return 0;
        }
        return rear - front + 1;
    }
};

int main() {
    Queue q;
    int choice, value, dequeuedValue;
    
    do {
        cout << "\n====== queue operations menu ======\n";
        cout << "1. enqueue()\n";
        cout << "2. dequeue()\n";
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
                cout << "enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;
                
            case 2:
                dequeuedValue = q.dequeue();
                if(dequeuedValue != -1) {
                    cout << dequeuedValue << " dequeued from queue\n";
                }
                break;
                
            case 3:
                if(q.isEmpty()) {
                    cout << "queue is empty\n";
                } else {
                    cout << "queue is not empty\n";
                }
                break;
                
            case 4:
                if(q.isFull()) {
                    cout << "queue is full\n";
                } else {
                    cout << "queue is not full\n";
                }
                break;
                
            case 5:
                q.display();
                break;
                
            case 6:
                value = q.peek();
                if(value != -1) {
                    cout << "front element: " << value << endl;
                }
                break;
                
            case 7:
                cout << "current queue size: " << q.size() << endl;
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