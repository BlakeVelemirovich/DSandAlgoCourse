#include <iostream>

using namespace std;

// Node structure for the BST
struct Node {
    int key;
    Node* left;
    Node* right;
    
    Node(int val) : key(val), left(nullptr), right(nullptr) {}
};

class BinarySearchTree {
public:
    Node* root;
    
    BinarySearchTree() : root(nullptr) {}
    
    void insert(int key) {
        root = insertRec(root, key);
    }
    
    bool search(int key) {
        return searchRec(root, key) != nullptr;
    }
    
    void remove(int key) {
        root = deleteRec(root, key);
    }
    
    void inorder() {
        inorderRec(root);
        cout << endl;
    }
    
    void preorder() {
        preorderRec(root);
        cout << endl;
    }
    
    void postorder() {
        postorderRec(root);
        cout << endl;
    }

private:
    Node* insertRec(Node* node, int key) {
        if (!node) return new Node(key);
        if (key < node->key) node->left = insertRec(node->left, key);
        else if (key > node->key) node->right = insertRec(node->right, key);
        return node;
    }
    
    Node* searchRec(Node* node, int key) {
        if (!node || node->key == key) return node;
        if (key < node->key) return searchRec(node->left, key);
        return searchRec(node->right, key);
    }
    
    Node* deleteRec(Node* node, int key) {
        if (!node) return node;
        if (key < node->key) node->left = deleteRec(node->left, key);
        else if (key > node->key) node->right = deleteRec(node->right, key);
        else {
            if (!node->left) {
                Node* temp = node->right;
                delete node;
                return temp;
            }
            else if (!node->right) {
                Node* temp = node->left;
                delete node;
                return temp;
            }
            Node* temp = minValueNode(node->right);
            node->key = temp->key;
            node->right = deleteRec(node->right, temp->key);
        }
        return node;
    }
    
    Node* minValueNode(Node* node) {
        Node* current = node;
        while (current && current->left) current = current->left;
        return current;
    }
    
    void inorderRec(Node* node) {
        if (!node) return;
        inorderRec(node->left);
        cout << node->key << " ";
        inorderRec(node->right);
    }
    
    void preorderRec(Node* node) {
        if (!node) return;
        cout << node->key << " ";
        preorderRec(node->left);
        preorderRec(node->right);
    }
    
    void postorderRec(Node* node) {
        if (!node) return;
        postorderRec(node->left);
        postorderRec(node->right);
        cout << node->key << " ";
    }
};

int main() {
    BinarySearchTree bst;
    bst.insert(50);
    bst.insert(30);
    bst.insert(70);
    bst.insert(20);
    bst.insert(40);
    bst.insert(60);
    bst.insert(80);
    
    cout << "Inorder traversal: ";
    bst.inorder();
    
    cout << "Preorder traversal: ";
    bst.preorder();
    
    cout << "Postorder traversal: ";
    bst.postorder();
    
    cout << "Searching 40: " << (bst.search(40) ? "Found" : "Not Found") << endl;
    
    bst.remove(50);
    cout << "Inorder after deleting 50: ";
    bst.inorder();
    
    return 0;
}
