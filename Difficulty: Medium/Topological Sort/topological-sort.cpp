class Solution {
  public:
    void dfs_sort(int i,vector<int>& vis,stack<int>& st,vector<int> adj[]){
        vis[i]=1;
        for(auto it:adj[i]){
            if(!vis[it]) dfs_sort(it,vis,st,adj);
        }
        st.push(i);
        
    }
  
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        vector<int> adj[V];
        for(auto &e:edges){
            int u=e[0];
            int v=e[1];
            adj[u].push_back(v);
        }
        
        vector<int> vis(V,0);
        stack<int> st;
        vector<int> ans;
        
        for(int i=0;i<V;i++){
            if(!vis[i]) dfs_sort(i,vis,st,adj);
        }
        
        while(st.size()){
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
    }
};