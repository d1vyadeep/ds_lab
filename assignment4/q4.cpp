#include <iostream>
#include <cstring>
using namespace std;

#define MAX 100

class Queue {
    int front;
    int rear;
    char arr[MAX];
    
public:
    Queue() {
        front = -1;
        rear = -1;
    }
    
    bool isEmpty() {
        return (front == -1 || front > rear);
    }
    
    void enqueue(char ch) {
        if(front == -1) {
            front = 0;
        }
        arr[++rear] = ch;
    }
    
    char dequeue() {
        if(isEmpty()) {
            return '\0';
        }
        
        char ch = arr[front++];
        
        if(front > rear) {
            front = -1;
            rear = -1;
        }
        
        return ch;
    }
    
    char peek() {
        if(isEmpty()) {
            return '\0';
        }
        return arr[front];
    }
};

void findFirstNonRepeatingDetailed(char stream[], int n) {
    Queue q;
    int freq[256] = {0};
    
    cout << "\nstream: ";
    for(int i = 0; i < n; i++) {
        cout << stream[i] << " ";
    }
    cout << endl;
    
    cout << "\nprocessing step by step:\n";
    cout << "----------------------------------------\n";
    
    for(int i = 0; i < n; i++) {
        char ch = stream[i];
        
        cout << "\nstep " << i+1 << ": read character '" << ch << "'\n";
        
        freq[ch]++;
        cout << "  frequency of '" << ch << "' = " << freq[ch] << endl;
        
        q.enqueue(ch);
        cout << "  enqueued '" << ch << "' to queue\n";
        
        while(!q.isEmpty() && freq[q.peek()] > 1) {
            char removed = q.dequeue();
            cout << "  removed '" << removed << "' from queue (repeating)\n";
        }
        
        if(q.isEmpty()) {
            cout << "  first non-repeating: -1 (no non-repeating character)\n";
        } else {
            cout << "  first non-repeating: " << q.peek() << endl;
        }
    }
    
    cout << "\nfinal output: ";
    
    Queue q2;
    int freq2[256] = {0};
    
    for(int i = 0; i < n; i++) {
        char ch = stream[i];
        freq2[ch]++;
        q2.enqueue(ch);
        
        while(!q2.isEmpty() && freq2[q2.peek()] > 1) {
            q2.dequeue();
        }
        
        if(q2.isEmpty()) {
            cout << "-1 ";
        } else {
            cout << q2.peek() << " ";
        }
    }
    cout << endl;
}

void findFirstNonRepeatingSimple(char stream[], int n) {
    Queue q;
    int freq[256] = {0};
    
    cout << "\ninput:  ";
    for(int i = 0; i < n; i++) {
        cout << stream[i] << " ";
    }
    
    cout << "\noutput: ";
    
    for(int i = 0; i < n; i++) {
        char ch = stream[i];
        
        freq[ch]++;
        q.enqueue(ch);
        
        while(!q.isEmpty() && freq[q.peek()] > 1) {
            q.dequeue();
        }
        
        if(q.isEmpty()) {
            cout << "-1 ";
        } else {
            cout << q.peek() << " ";
        }
    }
    cout << endl;
}

int main() {
    char stream[MAX];
    int choice, n;
    
    do {
        cout << "\n====== first non-repeating character ======\n";
        cout << "1. enter character stream\n";
        cout << "2. find first non-repeating (detailed)\n";
        cout << "3. find first non-repeating (simple)\n";
        cout << "4. run sample example (a a b c)\n";
        cout << "5. run more examples\n";
        cout << "6. exit\n";
        cout << "enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                cout << "enter number of characters: ";
                cin >> n;
                
                cout << "enter " << n << " characters (space separated):\n";
                for(int i = 0; i < n; i++) {
                    cin >> stream[i];
                }
                cout << "stream saved!\n";
                break;
                
            case 2:
                if(n == 0) {
                    cout << "please enter stream first (option 1)!\n";
                    break;
                }
                findFirstNonRepeatingDetailed(stream, n);
                break;
                
            case 3:
                if(n == 0) {
                    cout << "please enter stream first (option 1)!\n";
                    break;
                }
                findFirstNonRepeatingSimple(stream, n);
                break;
                
            case 4:
                {
                    char sample[] = {'a', 'a', 'b', 'c'};
                    int sampleSize = 4;
                    
                    cout << "\nsample example:\n";
                    findFirstNonRepeatingSimple(sample, sampleSize);
                    cout << "expected: a -1 b b\n";
                }
                break;
                
            case 5:
                {
                    cout << "\n====== more examples ======\n";
                    
                    struct Example {
                        char str[20];
                        int size;
                        char desc[50];
                    };
                    
                    Example examples[] = {
                        {{'a', 'a', 'b', 'c'}, 4, "sample case"},
                        {{'a', 'b', 'c', 'a', 'b', 'c'}, 6, "all repeating eventually"},
                        {{'a', 'b', 'c', 'd'}, 4, "all unique"},
                        {{'a', 'a', 'a', 'a'}, 4, "all same"},
                        {{'a', 'b', 'a', 'c', 'b', 'd'}, 6, "mixed pattern"}
                    };
                    
                    int numExamples = 5;
                    
                    for(int i = 0; i < numExamples; i++) {
                        cout << "\nexample " << i+1 << ": " << examples[i].desc << endl;
                        findFirstNonRepeatingSimple(examples[i].str, examples[i].size);
                    }
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