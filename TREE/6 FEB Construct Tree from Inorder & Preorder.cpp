class Solution {
  public:
  
   Node* build(int inStart,int inEnd,vector<int> &preorder,int& preIndex,unordered_map<int,int>& mp){
       
       //base case 
       if(inStart>inEnd) return NULL;
       
       Node* root=new Node(preorder[preIndex++]);
       int rootPos=mp[root->data];
       
       root->left=build(inStart,rootPos-1,preorder,preIndex,mp);
       root->right=build(rootPos+1,inEnd , preorder,preIndex,mp);
       
       return root;
   }
    // Function to build the tree from given inorder and preorder traversals
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        // code here
        unordered_map<int,int>mp;
        for(int i=0;i<inorder.size();i++) mp[inorder[i]]=i;
        int preIndex=0;
        return build(0,inorder.size()-1,preorder,preIndex,mp);
    }
};