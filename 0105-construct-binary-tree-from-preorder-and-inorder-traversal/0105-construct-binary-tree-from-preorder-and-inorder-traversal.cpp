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
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int start,int end,int &idx){
        if(start>end) return NULL;

        int root=preorder[idx];
        int i=start;

        for(;i<end;i++){
            if(inorder[i]==root) break;
        }

        idx++;

        TreeNode* rt = new TreeNode(root);
        rt->left = solve(preorder,inorder,start,i-1,idx);
        rt->right = solve(preorder,inorder,i+1,end,idx);

        return rt;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int start=0;
        int n=preorder.size();
        int end=n-1;
        int idx=0;

        return solve(preorder,inorder,start,end,idx);
    }
};