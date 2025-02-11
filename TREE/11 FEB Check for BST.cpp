class Solution {
    public:
    void inorder(Node* root,vector<int>&temp){
        if(!root) return;
        inorder(root->left,temp);
        temp.push_back(root->data);
        inorder(root->right,temp);
    }
      // Function to check whether a Binary Tree is BST or not.
      bool isBST(Node* root) {
          // Your code here
          if(!root->left &&!root->right) return true;
          vector<int>temp;
          inorder(root,temp);
          for(int i=0;i<temp.size()-2;i++){
              if(temp[i]>temp[i+1]) return false;
          }
          return true;
      }
  };
  

/*
class Solution {
  public:
  
  bool check(Node* root,int low,int high){
      if(!root) return true;
      if(root->data<=low || root->data>=high) return false;
      return check(root->left,low,root->data)&& check(root->right,root->data,high);
  }
    // Function to check whether a Binary Tree is BST or not.
    bool isBST(Node* root) {
        // Your code here
        return check(root,INT_MIN,INT_MAX);
    }
};

*/