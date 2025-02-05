class Solution {
public:
    void mirror(Node* node) {
        if (!node) return; // Base case: If the node is null, do nothing
        swap(node->left, node->right); // Swap left and right children
        mirror(node->left); // Recurse on the left child
        mirror(node->right); // Recurse on the right child
    }
};
