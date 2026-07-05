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
    int maxi = INT_MIN;

    int solve(TreeNode* root){
        if(root==NULL) return 0;

        int l = solve(root->left);
        int r = solve(root->right);

        int neeche = l+r+root->val;
        int koi_ek = max(l,r)+root->val;
        int only_root = root->val;

        maxi=max({neeche,koi_ek,only_root,maxi});
        
        return max(koi_ek,only_root);
    }

    int maxPathSum(TreeNode* root) {
        solve(root);
        return maxi;
    }
};