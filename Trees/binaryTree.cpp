#include <iostream>

using namespace std;

class TreeNode {
public:
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) {
        data = value;
        left = right = nullptr;
    }

    void traverseNodeDisplay(TreeNode* node) {
        if (node == nullptr) return;

        traverseNodeDisplay(node->left);
        traverseNodeDisplay(node->right); 
        cout << "Data: " << node->data;
    }
};

int main() {

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    root->traverseNodeDisplay(root);

    return 0;
}