#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};

class BST {
public:

    Node* insert(Node* root, int value) {
        if (root == nullptr)
            return new Node(value);

        if (value < root->data)
            root->left = insert(root->left, value);
        else
            root->right = insert(root->right, value);

        return root;
    }

    Node* searchRecursive(Node* root, int key) {
        if (root == nullptr || root->data == key)
            return root;

        if (key < root->data)
            return searchRecursive(root->left, key);

        return searchRecursive(root->right, key);
    }

    Node* searchIterative(Node* root, int key) {
        while (root != nullptr) {
            if (key == root->data)
                return root;
            else if (key < root->data)
                root = root->left;
            else
                root = root->right;
        }
        return nullptr;
    }


    Node* findMax(Node* root) {
        if (root == nullptr) return nullptr;
        while (root->right != nullptr)
            root = root->right;
        return root;
    }

    Node* findMin(Node* root) {
        if (root == nullptr) return nullptr;
        while (root->left != nullptr)
            root = root->left;
        return root;
    }

    Node* inorderSuccessor(Node* root, Node* node) {
        if (node->right != nullptr)
            return findMin(node->right);

        Node* successor = nullptr;
        while (root != nullptr) {
            if (node->data < root->data) {
                successor = root;
                root = root->left;
            } else if (node->data > root->data) {
                root = root->right;
            } else
                break;
        }
        return successor;
    }

    Node* inorderPredecessor(Node* root, Node* node) {
        if (node->left != nullptr)
            return findMax(node->left);

        Node* predecessor = nullptr;
        while (root != nullptr) {
            if (node->data > root->data) {
                predecessor = root;
                root = root->right;
            } else if (node->data < root->data) {
                root = root->left;
            } else
                break;
        }
        return predecessor;
    }
};

int main() {
    BST tree;
    Node* root = nullptr;

    int values[] = {20, 8, 22, 4, 12, 10, 14};
    for (int v : values)
        root = tree.insert(root, v);

    cout << "BST created.\n";

    Node* result1 = tree.searchRecursive(root, 10);
    cout << "Recursive Search 10: " 
         << (result1 ? "Found" : "Not Found") << endl;

    Node* result2 = tree.searchIterative(root, 14);
    cout << "Iterative Search 14: " 
         << (result2 ? "Found" : "Not Found") << endl;

    cout << "Maximum element: " << tree.findMax(root)->data << endl;

    cout << "Minimum element: " << tree.findMin(root)->data << endl;

    Node* node = tree.searchRecursive(root, 10);
    Node* succ = tree.inorderSuccessor(root, node);
    cout << "Inorder Successor of 10: " 
         << (succ ? to_string(succ->data) : "None") << endl;

    Node* pred = tree.inorderPredecessor(root, node);
    cout << "Inorder Predecessor of 10: " 
         << (pred ? to_string(pred->data) : "None") << endl;

    return 0;
}
