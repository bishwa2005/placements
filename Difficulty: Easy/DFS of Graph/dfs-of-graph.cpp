class Solution {
  public:
    void solve(int i,vector<vector<int>> &adj,vector<int> &ans,vector<int> &vis){
        vis[i]=1;
        ans.push_back(i);
        for(auto it : adj[i]){
            if(!vis[it]){
                solve(it,adj,ans,vis);
            }
        }
    }
  
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n=adj.size();
        vector<int> ans;
        vector<int> vis(n,0);
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                solve(i,adj,ans,vis);
            }
        }
        
        return ans;
    }
};