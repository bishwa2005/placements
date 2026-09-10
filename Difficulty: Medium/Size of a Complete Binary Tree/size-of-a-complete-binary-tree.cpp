class Solution {
  public:
    int solve(Node* root){
        if(root==NULL) return 0;
        if(root->left==NULL && root->right==NULL) return 1;
        return 1+solve(root->left)+solve(root->right);
        
    }
    int countNodes(Node* root) {
        // code here
        return solve(root);
    }
};