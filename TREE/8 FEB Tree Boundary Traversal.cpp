class Solution {
    public:
    void getLeft(Node* root,vector<int>&res){
        if(!root || (!root->left && !root->right)) return;
        res.push_back(root->data);
        if(root->left) getLeft(root->left,res);
        else getLeft(root->right,res);
        
    }
    void getLeaf(Node* root,vector<int>&res){
        if(!root) return;
        getLeaf(root->left,res);
        if(!root->left && !root->right )res.push_back(root->data);
        getLeaf(root->right,res);
        
    }
    void getRight(Node* root,vector<int>&res){
         if(!root || (!root->left && !root->right)) return;
         if(root->right) getRight(root->right,res);
         else getRight(root->left,res);
         res.push_back(root->data);
        
    }
      vector<int> boundaryTraversal(Node *root) {
          // code here
          vector<int>res;
          //base case 
          if(!root) return res;
          
          if(root->left || root->right) res.push_back(root->data);
          
          getLeft(root->left,res);
          getLeaf(root,res);
          getRight(root->right,res);
          
          return res;
      }
  };