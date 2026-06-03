class Solution {
  public:
    void dfs(int start,vector<vector<int>>& edges,stack<int> &st,vector<int> &vis){
        vis[start]=1;
        for(auto it : edges[start]){
            if(!vis[it])
                dfs(it,edges,st,vis);
        }
        st.push(start);
    }
  
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        for(auto it : edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
        }
        
        
        stack<int> st;
        vector<int> vis(V,0);
        
        for(int i=0;i<V;i++){
            if(!vis[i])
                dfs(0,adj,st,vis);
                
        }
        
        vector<int> ans;
        while(st.size()){
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
        
    }
};