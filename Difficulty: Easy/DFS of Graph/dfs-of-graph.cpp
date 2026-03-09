class Solution {
  public:
    void dfs(int start,vector<int>& vis,vector<vector<int>>& adj,vector<int>& ans){
        vis[start]=1;
        ans.push_back(start);
        for(auto it : adj[start]){
            if(!vis[it])
                dfs(it,vis,adj,ans);
        }
    }
  
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n=adj.size();
        vector<int> vis(n,0);
        
        vector<int> ans;
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(i,vis,adj,ans);
            }
        }
        
        return ans;
    }
};