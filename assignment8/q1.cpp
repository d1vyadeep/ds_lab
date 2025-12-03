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
public:

    void preorder(Node* root) {
        if (root == nullptr)
            return;
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }

    void inorder(Node* root) {
        if (root == nullptr)
            return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }

    void postorder(Node* root) {
        if (root == nullptr)
            return;
        postorder(root->left);
        postorder(root->right);
        cout << root->data << " ";
    }
};

int main() {

    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    BinaryTree bt;

    cout << "Preorder Traversal: ";
    bt.preorder(root);
    cout << endl;

    cout << "Inorder Traversal: ";
    bt.inorder(root);
    cout << endl;

    cout << "Postorder Traversal: ";
    bt.postorder(root);
    cout << endl;

    return 0;
}
