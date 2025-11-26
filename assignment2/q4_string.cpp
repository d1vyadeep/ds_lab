#include <iostream>
#include <cstring>
using namespace std;

void concatenateStrings() {
    char str1[100], str2[100];
    int i, j;
    
    cout << "\n--- string concatenation ---\n";
    cout << "enter first string: ";
    cin.ignore();
    cin.getline(str1, 100);
    
    cout << "enter second string: ";
    cin.getline(str2, 100);
    
    i = 0;
    while(str1[i] != '\0') {
        i++;
    }
    
    j = 0;
    while(str2[j] != '\0') {
        str1[i] = str2[j];
        i++;
        j++;
    }
    str1[i] = '\0';
    
    cout << "concatenated string: " << str1 << endl;
}

void reverseString() {
    char str[100], temp;
    int i, len;
    
    cout << "\n--- string reverse ---\n";
    cout << "enter string: ";
    cin.ignore();
    cin.getline(str, 100);
    
    len = 0;
    while(str[len] != '\0') {
        len++;
    }
    
    for(i = 0; i < len/2; i++) {
        temp = str[i];
        str[i] = str[len-1-i];
        str[len-1-i] = temp;
    }
    
    cout << "reversed string: " << str << endl;
}

void deleteVowels() {
    char str[100];
    int i, j;
    
    cout << "\n--- delete vowels ---\n";
    cout << "enter string: ";
    cin.ignore();
    cin.getline(str, 100);
    
    cout << "original string: " << str << endl;
    
    for(i = 0; str[i] != '\0'; i++) {
        if(str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || 
           str[i] == 'o' || str[i] == 'u' || str[i] == 'A' || 
           str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || 
           str[i] == 'U') {
            for(j = i; str[j] != '\0'; j++) {
                str[j] = str[j+1];
            }
            i--;
        }
    }
    
    cout << "string after removing vowels: " << str << endl;
}

void sortStrings() {
    char strings[10][100], temp[100];
    int n, i, j;
    
    cout << "\n--- sort strings alphabetically ---\n";
    cout << "enter number of strings: ";
    cin >> n;
    
    cout << "enter " << n << " strings:\n";
    cin.ignore();
    for(i = 0; i < n; i++) {
        cout << "string " << i+1 << ": ";
        cin.getline(strings[i], 100);
    }
    
    for(i = 0; i < n-1; i++) {
        for(j = i+1; j < n; j++) {
            if(strcmp(strings[i], strings[j]) > 0) {
                strcpy(temp, strings[i]);
                strcpy(strings[i], strings[j]);
                strcpy(strings[j], temp);
            }
        }
    }
    
    cout << "\nstrings in alphabetical order:\n";
    for(i = 0; i < n; i++) {
        cout << strings[i] << endl;
    }
}

void convertCase() {
    char str[100];
    int i, choice;
    
    cout << "\n--- case conversion ---\n";
    cout << "enter string: ";
    cin.ignore();
    cin.getline(str, 100);
    
    cout << "1. uppercase to lowercase\n";
    cout << "2. lowercase to uppercase\n";
    cout << "enter choice: ";
    cin >> choice;
    
    if(choice == 1) {
        for(i = 0; str[i] != '\0'; i++) {
            if(str[i] >= 'A' && str[i] <= 'Z') {
                str[i] = str[i] + 32;
            }
        }
        cout << "converted to lowercase: " << str << endl;
    }
    else if(choice == 2) {
        for(i = 0; str[i] != '\0'; i++) {
            if(str[i] >= 'a' && str[i] <= 'z') {
                str[i] = str[i] - 32;
            }
        }
        cout << "converted to uppercase: " << str << endl;
    }
    else {
        cout << "invalid choice!\n";
    }
}

int main() {
    int choice;
    
    do {
        cout << "\n====== string operations menu ======\n";
        cout << "1. concatenate two strings\n";
        cout << "2. reverse a string\n";
        cout << "3. delete all vowels\n";
        cout << "4. sort strings alphabetically\n";
        cout << "5. convert case (upper/lower)\n";
        cout << "6. exit\n";
        cout << "enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                concatenateStrings();
                break;
            case 2:
                reverseString();
                break;
            case 3:
                deleteVowels();
                break;
            case 4:
                sortStrings();
                break;
            case 5:
                convertCase();
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