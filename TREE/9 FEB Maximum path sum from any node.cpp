class Solution {
    public:
      // Function to return maximum path sum from any node in a tree.
      int findMaxSum(Node *root) {
          // code here
          int ans=INT_MIN;
          maxPath(root,ans);
          return ans;
      }
      int  maxPath(Node *root,int& ans){
          if(!root) return 0;
          
        int leftSum=maxPath(root->left,ans);
        leftSum=(leftSum<0)?0:leftSum;
       int rightSum= maxPath(root->right,ans);
       rightSum=(rightSum<0)?0:rightSum;
        
        ans=max(ans,(root->data+leftSum+rightSum));
        return max(leftSum,rightSum)+root->data;
      }
  };