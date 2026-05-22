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
    int max_sum = INT_MIN;

    int solve(TreeNode* root){
        if(root==NULL) return 0;
        int l=solve(root->left);
        int r=solve(root->right);

        int koi_ek = max(l,r)+root->val;
        int only_root = root->val;
        int neeche = l+r+root->val;

        max_sum=max({max_sum,koi_ek,only_root,neeche});
        return max(koi_ek,only_root);

    }

    int maxPathSum(TreeNode* root) {
        solve(root);
        return max_sum;
    }
};