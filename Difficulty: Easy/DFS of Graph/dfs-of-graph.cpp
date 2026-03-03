class Solution {
  public:
    void traverse(int start,vector<vector<int>>& adj,vector<int>& ans,vector<int>& vis){
        vis[start]=1;
        ans.push_back(start);
        for(auto node : adj[start]){
            if(!vis[node]){
                traverse(node,adj,ans,vis);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
        vector<int> ans;
        vector<int> vis(n);
        traverse(0,adj,ans,vis);
        return ans;
    }
};