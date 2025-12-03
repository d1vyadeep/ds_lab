#include <iostream>
#include <cctype>
using namespace std;

struct Node {
    char data;
    Node* next;
    Node* prev;
};

class DoublyLinkedList {
    Node* head;
    
public:
    DoublyLinkedList() {
        head = NULL;
    }
    
    void insertAtEnd(char value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;
        
        if(head == NULL) {
            newNode->prev = NULL;
            head = newNode;
            return;
        }
        
        Node* temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
    
    void display() {
        if(head == NULL) {
            cout << "list is empty!\n";
            return;
        }
        
        Node* temp = head;
        cout << "NULL <-> ";
        while(temp != NULL) {
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL\n";
    }
    
    bool isPalindrome() {
        if(head == NULL) {
            return true;
        }
        
        Node* left = head;
        Node* right = head;
        
        while(right->next != NULL) {
            right = right->next;
        }
        
        while(left != right && left->prev != right) {
            if(tolower(left->data) != tolower(right->data)) {
                return false;
            }
            left = left->next;
            right = right->prev;
        }
        
        return true;
    }
    
    bool isPalindromeDetailed() {
        if(head == NULL) {
            cout << "list is empty! considered palindrome.\n";
            return true;
        }
        
        cout << "\nmethod: two pointer technique\n";
        cout << "------------------------------\n";
        
        Node* left = head;
        Node* right = head;
        
        cout << "step 1: find rightmost node\n";
        while(right->next != NULL) {
            right = right->next;
        }
        cout << "  leftmost: " << left->data << endl;
        cout << "  rightmost: " << right->data << endl;
        
        cout << "\nstep 2: compare from both ends moving towards center\n";
        
        int step = 0;
        while(left != right && left->prev != right) {
            step++;
            cout << "  comparison " << step << ": '" << left->data << "' vs '" << right->data << "'";
            
            if(tolower(left->data) != tolower(right->data)) {
                cout << " -> not equal!\n";
                cout << "\nresult: not a palindrome\n";
                return false;
            }
            
            cout << " -> equal\n";
            left = left->next;
            right = right->prev;
        }
        
        cout << "\nall comparisons matched!\n";
        cout << "result: palindrome\n";
        return true;
    }
    
    bool isPalindromeUsingArray() {
        if(head == NULL) {
            return true;
        }
        
        char arr[100];
        int count = 0;
        
        Node* temp = head;
        while(temp != NULL) {
            arr[count++] = tolower(temp->data);
            temp = temp->next;
        }
        
        for(int i = 0; i < count / 2; i++) {
            if(arr[i] != arr[count - 1 - i]) {
                return false;
            }
        }
        
        return true;
    }
    
    bool isPalindromeUsingArrayDetailed() {
        if(head == NULL) {
            cout << "list is empty! considered palindrome.\n";
            return true;
        }
        
        cout << "\nmethod: using array\n";
        cout << "-------------------\n";
        
        char arr[100];
        int count = 0;
        
        cout << "step 1: store all characters in array\n";
        Node* temp = head;
        while(temp != NULL) {
            arr[count] = tolower(temp->data);
            cout << "  arr[" << count << "] = '" << arr[count] << "'\n";
            count++;
            temp = temp->next;
        }
        
        cout << "\nstep 2: compare first half with second half\n";
        
        for(int i = 0; i < count / 2; i++) {
            cout << "  arr[" << i << "] = '" << arr[i] << "' vs arr[" << (count-1-i) << "] = '" << arr[count-1-i] << "'";
            
            if(arr[i] != arr[count - 1 - i]) {
                cout << " -> not equal!\n";
                cout << "\nresult: not a palindrome\n";
                return false;
            }
            
            cout << " -> equal\n";
        }
        
        cout << "\nall comparisons matched!\n";
        cout << "result: palindrome\n";
        return true;
    }
};

int main() {
    DoublyLinkedList dll;
    int choice, n;
    char ch;
    bool result;
    
    do {
        cout << "\n====== palindrome check in doubly linked list ======\n";
        cout << "1. create list from string\n";
        cout << "2. create list character by character\n";
        cout << "3. display list\n";
        cout << "4. check palindrome (two pointer method)\n";
        cout << "5. check palindrome (array method)\n";
        cout << "6. check palindrome (two pointer - detailed)\n";
        cout << "7. check palindrome (array - detailed)\n";
        cout << "8. run sample examples\n";
        cout << "9. exit\n";
        cout << "enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                {
                    dll = DoublyLinkedList();
                    char str[100];
                    cout << "enter string: ";
                    cin >> str;
                    
                    for(int i = 0; str[i] != '\0'; i++) {
                        dll.insertAtEnd(str[i]);
                    }
                    cout << "doubly linked list created!\n";
                }
                break;
                
            case 2:
                dll = DoublyLinkedList();
                cout << "enter number of characters: ";
                cin >> n;
                
                cout << "enter " << n << " characters:\n";
                for(int i = 0; i < n; i++) {
                    cin >> ch;
                    dll.insertAtEnd(ch);
                }
                cout << "doubly linked list created!\n";
                break;
                
            case 3:
                cout << "doubly linked list: ";
                dll.display();
                break;
                
            case 4:
                cout << "checking if list is palindrome...\n";
                result = dll.isPalindrome();
                cout << "result: " << (result ? "palindrome" : "not a palindrome") << endl;
                break;
                
            case 5:
                cout << "checking if list is palindrome...\n";
                result = dll.isPalindromeUsingArray();
                cout << "result: " << (result ? "palindrome" : "not a palindrome") << endl;
                break;
                
            case 6:
                dll.display();
                dll.isPalindromeDetailed();
                break;
                
            case 7:
                dll.display();
                dll.isPalindromeUsingArrayDetailed();
                break;
                
            case 8:
                {
                    cout << "\n====== sample examples ======\n";
                    
                    struct Example {
                        char str[20];
                        bool expected;
                    };
                    
                    Example examples[] = {
                        {"racecar", true},
                        {"madam", true},
                        {"hello", false},
                        {"noon", true},
                        {"level", true},
                        {"test", false},
                        {"a", true},
                        {"aa", true},
                        {"ab", false},
                        {"abba", true}
                    };
                    
                    int numExamples = 10;
                    
                    for(int i = 0; i < numExamples; i++) {
                        DoublyLinkedList test;
                        
                        cout << "\nexample " << i+1 << ": " << examples[i].str << endl;
                        
                        for(int j = 0; examples[i].str[j] != '\0'; j++) {
                            test.insertAtEnd(examples[i].str[j]);
                        }
                        
                        cout << "list: ";
                        test.display();
                        
                        result = test.isPalindrome();
                        cout << "result: " << (result ? "palindrome" : "not a palindrome") << endl;
                        cout << "expected: " << (examples[i].expected ? "palindrome" : "not a palindrome") << endl;
                        cout << "status: " << (result == examples[i].expected ? "correct ✓" : "incorrect ✗") << endl;
                    }
                }
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