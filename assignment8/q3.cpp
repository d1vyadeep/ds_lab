#include <iostream>
#include <algorithm>
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
        else if (value > root->data)
            root->right = insert(root->right, value);
        else
            cout << "Duplicate value " << value << " ignored.\n";

        return root;
    }


    Node* findMin(Node* root) {
        while (root && root->left != nullptr)
            root = root->left;
        return root;
    }

    Node* deleteNode(Node* root, int key) {
        if (root == nullptr)
            return root;

        if (key < root->data)
            root->left = deleteNode(root->left, key);

        else if (key > root->data)
            root->right = deleteNode(root->right, key);

        else {

            if (root->left == nullptr) {
                Node* temp = root->right;
                delete root;
                return temp;
            }
            else if (root->right == nullptr) {
                Node* temp = root->left;
                delete root;
                return temp;
            }

            Node* temp = findMin(root->right); 
            root->data = temp->data;
            root->right = deleteNode(root->right, temp->data);
        }

        return root;
    }

    int maxDepth(Node* root) {
        if (root == nullptr)
            return 0;

        return 1 + max(maxDepth(root->left),
                       maxDepth(root->right));
    }

    int minDepth(Node* root) {
        if (root == nullptr)
            return 0;

        if (!root->left && !root->right)
            return 1;

        if (!root->left)
            return 1 + minDepth(root->right);
        if (!root->right)
            return 1 + minDepth(root->left);

        return 1 + min(minDepth(root->left),
                       minDepth(root->right));
    }

    void inorder(Node* root) {
        if (root == nullptr)
            return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
};

int main() {
    BST tree;
    Node* root = nullptr;

    int values[] = {20, 10, 30, 5, 15, 25, 40};
    for (int v : values)
        root = tree.insert(root, v);

    cout << "Inorder traversal of BST: ";
    tree.inorder(root);
    cout << endl;

    cout << "Deleting 10..." << endl;
    root = tree.deleteNode(root, 10);

    cout << "Inorder after deletion: ";
    tree.inorder(root);
    cout << endl;

    cout << "Maximum Depth of BST: " << tree.maxDepth(root) << endl;

    cout << "Minimum Depth of BST: " << tree.minDepth(root) << endl;

    return 0;
}
