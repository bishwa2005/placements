/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root,string path,vector<string>& ans){
        string node = to_string(root->val);

        if(root->left==NULL && root->right==NULL){
            path+=node;
            ans.push_back(path);
            return;
        } 

        if(root->left)
            solve(root->left,path+node+"->",ans);
        if(root->right)
            solve(root->right,path+node+"->",ans);
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;

        solve(root,"",ans);
        return ans;
    }
};