class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        unordered_map<TreeNode*,TreeNode*> parent;

        // BFS to store parent
        queue<TreeNode*> q;
        q.push(root);
        parent[root] = NULL;

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if(node->left){
                parent[node->left] = node;
                q.push(node->left);
            }

            if(node->right){
                parent[node->right] = node;
                q.push(node->right);
            }
        }

        // BFS from target
        unordered_set<TreeNode*> vis;
        queue<pair<TreeNode*,int>> que;

        que.push({target,0});
        vis.insert(target);

        vector<int> ans;

        while(!que.empty()){
            auto node = que.front().first;
            int d = que.front().second;
            que.pop();

            if(d == k){
                ans.push_back(node->val);
                continue;
            }

            if(node->left && !vis.count(node->left)){
                vis.insert(node->left);
                que.push({node->left,d+1});
            }

            if(node->right && !vis.count(node->right)){
                vis.insert(node->right);
                que.push({node->right,d+1});
            }

            if(parent[node] && !vis.count(parent[node])){
                vis.insert(parent[node]);
                que.push({parent[node],d+1});
            }
        }

        return ans;
    }
};