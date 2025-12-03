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

class BinaryTree {
    Node* prev;  

public:
    BinaryTree() {
        prev = nullptr;
    }

    bool isBST(Node* root) {
        if (root == nullptr)
            return true;

        if (!isBST(root->left))
            return false;

        if (prev != nullptr && root->data <= prev->data)
            return false;

        prev = root;

        return isBST(root->right);
    }
};

int main() {

    Node* root = new Node(10);
    root->left = new Node(5);
    root->right = new Node(20);
    root->left->left = new Node(3);
    root->left->right = new Node(8);

    BinaryTree bt;

    if (bt.isBST(root))
        cout << "The given tree IS a BST.\n";
    else
        cout << "The given tree is NOT a BST.\n";

    return 0;
}
