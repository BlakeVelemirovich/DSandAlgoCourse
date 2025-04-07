#include <iostream>
#include <stack>
using namespace std;

// Definition of a binary tree node
struct TreeNode {
    int val;        
    TreeNode *left; 
    TreeNode *right;    

    // Constructor
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

void inorderTraversal(TreeNode* root) {
    // Stack
    stack<TreeNode*> st;
    TreeNode* current = root;

    // Traverse the tree iteratively
    while (current != nullptr || !st.empty()) {
        // Go to the leftmost node
        while (current != nullptr) {
            st.push(current);  // Push current node to stack
            current = current->left;
        }
        
        // Retrieve and process the leftmost node
        current = st.top(); 
        // Remove it
        st.pop();           

        cout << current->val << " ";
        
        // Move to the right subtree
        current = current->right;
    }
}

int main() {
    // Create the tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    
    inorderTraversal(root);

    return 0;
}
