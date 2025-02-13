class Solution {
    public:
    void inorder(Node* root,vector<int>&temp){
        if(!root) return;
        inorder(root->left,temp);
        temp.push_back(root->data);
        inorder(root->right,temp);
    }
      bool findTarget(Node *root, int target) {
          // your code here.
          vector<int>temp;
          inorder(root,temp);
          int s=0,e=temp.size()-1;
          while(s<e){
              if(temp[s]+temp[e]==target) return true;
              else if(temp[s]+temp[e]>target) e--;
              else s++;
          }
          return false;
          
      }
  };