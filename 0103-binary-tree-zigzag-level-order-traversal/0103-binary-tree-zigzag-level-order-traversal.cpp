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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL) return {};
        queue<TreeNode*> q;
        q.push(root);

        vector<vector<int>> ans;
        int lv=0;

        while(q.size()){
            int n=q.size();
            vector<int> level(n);

            for(int i=0;i<n;i++){
                auto node = q.front();
                q.pop();
                
                int idx = (lv%2==0) ? i : n-i-1;
                level[idx]=node->val;

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }

            ans.push_back(level);
            lv++;
        }
        
        return ans;
    }
};