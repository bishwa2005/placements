class Solution {
  public:
    void solve(int start,vector<vector<int>> &adj,vector<int> &vis,vector<int> &ans){
        vis[start]=1;
        ans.push_back(start);
        for(auto it : adj[start]){
            if(!vis[it]){
                solve(it,adj,vis,ans);
            }
        }
    }
    
    
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int v=adj.size();
        vector<int> vis(v,0);
        vector<int> ans;
        
        solve(0,adj,vis,ans);
        
        return ans;
    }
};