class Solution {
    public:
    void helper(Node* root,vector<int>&res){
        //base case 
        if(!root) return;
        
        helper(root->left,res);
        res.push_back(root->data);
        helper(root->right,res);
    }
      // Function to return a list containing the inorder traversal of the tree.
      vector<int> inOrder(Node* root) {
          // Your code here
          vector<int>res;
          helper(root,res);
          return res;
      }
  };