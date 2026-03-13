class Solution {
  public:
  
    void dfs(int start, vector<int>& vis, vector<int>& res, vector<vector<int>>& adj){
        vis[start] = 1;
        res.push_back(start);
        
        for(auto it : adj[start]){
            if(!vis[it]){
                dfs(it, vis, res, adj);
            }
        }
    }
  
    vector<vector<int>> getComponents(int V, vector<vector<int>>& edges) {
        
        vector<vector<int>> adj(V);
        
        // build adjacency list
        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int> vis(V,0);
        vector<vector<int>> ans;
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                vector<int> res;
                dfs(i, vis, res, adj);
                ans.push_back(res);
            }
        }
        
        return ans;
    }
};