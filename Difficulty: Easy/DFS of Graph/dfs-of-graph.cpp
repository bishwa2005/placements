class Solution {
  public:
    void dfs(int start,vector<int> &vis,vector<int>& ans,vector<vector<int>>& adj){
        ans.push_back(start);
        for(auto it : adj[start]){
            if(!vis[it]){
                vis[it]=1;
                dfs(it,vis,ans,adj);
            }
        }
    }
    
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n=adj.size();
        vector<int>vis(n,0);
        
        vector<int> ans;
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                vis[i]=1;
                dfs(i,vis,ans,adj);}
        }
        
        return ans;
    }
};