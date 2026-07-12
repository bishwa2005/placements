class Solution {
  public:
  
    void dfs(int i,vector<int> &vis,vector<vector<int>> &adj,stack<int> &st){
        vis[i]=1;
        for(auto it : adj[i]){
            if(!vis[it]){
                dfs(it,vis,adj,st);
            }
        }
        st.push(i);
    }
    
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
        }
        
        vector<int> vis(V,0);
        stack<int> st;
        
        for(int i=0;i<V;i++){
            if(!vis[i]){
                dfs(i,vis,adj,st);
            }
        }
        
        vector<int> ans;
        while(st.size()){
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
    }
};