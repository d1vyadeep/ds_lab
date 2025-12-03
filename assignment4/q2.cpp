#include <iostream>
using namespace std;

#define MAX 5

class CircularQueue {
    int front;
    int rear;
    int arr[MAX];
    int count;
    
public:
    CircularQueue() {
        front = -1;
        rear = -1;
        count = 0;
    }
    
    bool isEmpty() {
        return (count == 0);
    }
    
    bool isFull() {
        return (count == MAX);
    }
    
    bool enqueue(int value) {
        if(isFull()) {
            cout << "queue overflow! cannot enqueue " << value << endl;
            return false;
        }
        
        if(front == -1) {
            front = 0;
        }
        
        rear = (rear + 1) % MAX;
        arr[rear] = value;
        count++;
        
        cout << value << " enqueued into circular queue\n";
        return true;
    }
    
    int dequeue() {
        if(isEmpty()) {
            cout << "queue underflow! queue is empty\n";
            return -1;
        }
        
        int value = arr[front];
        
        if(front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX;
        }
        
        count--;
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
        
        cout << "circular queue elements (front to rear):\n";
        cout << "front -> ";
        
        int i = front;
        int elements = 0;
        
        while(elements < count) {
            cout << "[ " << arr[i] << " ] ";
            i = (i + 1) % MAX;
            elements++;
        }
        
        cout << "<- rear\n";
        
        cout << "\narray representation:\n";
        cout << "index: ";
        for(int i = 0; i < MAX; i++) {
            cout << i << "   ";
        }
        cout << "\nvalue: ";
        for(int i = 0; i < MAX; i++) {
            if((front <= rear && i >= front && i <= rear) || 
               (front > rear && (i >= front || i <= rear))) {
                cout << arr[i] << "   ";
            } else {
                cout << "-   ";
            }
        }
        cout << "\n       ";
        for(int i = 0; i < MAX; i++) {
            if(i == front && i == rear) {
                cout << "F,R ";
            } else if(i == front) {
                cout << "F   ";
            } else if(i == rear) {
                cout << "R   ";
            } else {
                cout << "    ";
            }
        }
        cout << endl;
    }
    
    int size() {
        return count;
    }
    
    void showStatus() {
        cout << "\nqueue status:\n";
        cout << "front index: " << front << endl;
        cout << "rear index:  " << rear << endl;
        cout << "size:        " << count << "/" << MAX << endl;
        cout << "is empty:    " << (isEmpty() ? "yes" : "no") << endl;
        cout << "is full:     " << (isFull() ? "yes" : "no") << endl;
    }
};

int main() {
    CircularQueue cq;
    int choice, value, dequeuedValue;
    
    cout << "====== circular queue demonstration ======\n";
    cout << "maximum queue size: " << MAX << endl;
    
    do {
        cout << "\n====== circular queue operations menu ======\n";
        cout << "1. enqueue()\n";
        cout << "2. dequeue()\n";
        cout << "3. isempty()\n";
        cout << "4. isfull()\n";
        cout << "5. display()\n";
        cout << "6. peek()\n";
        cout << "7. size()\n";
        cout << "8. show status\n";
        cout << "9. exit\n";
        cout << "enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                cout << "enter value to enqueue: ";
                cin >> value;
                cq.enqueue(value);
                break;
                
            case 2:
                dequeuedValue = cq.dequeue();
                if(dequeuedValue != -1) {
                    cout << dequeuedValue << " dequeued from circular queue\n";
                }
                break;
                
            case 3:
                if(cq.isEmpty()) {
                    cout << "circular queue is empty\n";
                } else {
                    cout << "circular queue is not empty\n";
                }
                break;
                
            case 4:
                if(cq.isFull()) {
                    cout << "circular queue is full\n";
                } else {
                    cout << "circular queue is not full\n";
                }
                break;
                
            case 5:
                cq.display();
                break;
                
            case 6:
                value = cq.peek();
                if(value != -1) {
                    cout << "front element: " << value << endl;
                }
                break;
                
            case 7:
                cout << "current queue size: " << cq.size() << endl;
                break;
                
            case 8:
                cq.showStatus();
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