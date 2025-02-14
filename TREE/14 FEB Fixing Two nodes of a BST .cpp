class Solution {
    public:
    Node *first,*temp,*prev,*last;
    void inorder(Node* root){
        if(!root) return;
        inorder(root->left);
        
        if(prev && root->data<prev->data){
            if(!first){
                first=prev;
                temp=root; 
            }
           else last=root;
        }
        
        
        prev=root;
        inorder(root->right);
    }
      void correctBST(Node* root) {
          // add code here.
          first=temp=prev=last=NULL;
          inorder(root);
          if(first && last) swap(first->data,last->data);
          else if (first && !last) swap(first->data,temp->data);
      }
  };