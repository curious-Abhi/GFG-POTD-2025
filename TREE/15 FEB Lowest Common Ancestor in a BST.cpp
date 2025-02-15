class Solution {
    public:
      Node* LCA(Node* root, Node* n1, Node* n2) {
          // code here
          while(root){
              if(root->data<n1->data && root->data<n2->data)
                root=root->right;
              else  if(root->data>n1->data && root->data>n2->data)
                root=root->left;
                else break;
          }
          return root;
      }
  };