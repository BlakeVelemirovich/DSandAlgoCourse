#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) : data(value), left(nullptr), right(nullptr) {}
};

class BinaryTree {
public:
    BinaryTree() : root(nullptr) {}

    void insert(int value) {
        root = insertRec(root, value);
    }

    void preorder() {
        preorderRec(root);
        cout << endl;
    }

    void inorder() {
        inorderRec(root);
        cout << endl;
    }

    void postorder() {
        postorderRec(root);
        cout << endl;
    }

private:
    Node* root;

    Node* insertRec(Node* node, int value) {
        if (node == nullptr) {
            return new Node(value);
        }

        if (value < node->data) {
            node->left = insertRec(node->left, value);
        } else {
            node->right = insertRec(node->right, value);
        }

        return node;
    }

    void preorderRec(Node* node) {
        if (node == nullptr) {
            return;
        }

        cout << node->data << " ";
        preorderRec(node->left);
        preorderRec(node->right);
    }

    void inorderRec(Node* node) {
        if (node == nullptr) {
            return;
        }

        inorderRec(node->left);
        cout << node->data << " ";
        inorderRec(node->right);
    }

    void postorderRec(Node* node) {
        if (node == nullptr) {
            return;
        }

        postorderRec(node->left);
        postorderRec(node->right);
        cout << node->data << " ";
    }
};

int main() {
    BinaryTree tree;
    tree.insert(10);
    tree.insert(5);
    tree.insert(15);
    tree.insert(3);
    tree.insert(7);
    tree.insert(12);
    tree.insert(18);

    cout << "Preorder traversal: ";
    tree.preorder();

    cout << "Inorder traversal: ";
    tree.inorder();

    cout << "Postorder traversal: ";
    tree.postorder();

    return 0;
}