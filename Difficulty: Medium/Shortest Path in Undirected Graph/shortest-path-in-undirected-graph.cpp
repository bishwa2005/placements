class Solution {
  public:
    vector<int> shortestPath(int V, vector<vector<int>> &edges, int src) {
        // code here
        vector<vector<int>> adj(V);
        for(auto it : edges){
            int u=it[0];
            int v=it[1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> vis(V,0);
        
        queue<pair<int,int>> q;
        q.push({src,0});
        vis[src]=1;
        
        vector<int> ans(V,-1);
        
        while(q.size()){
            auto [node,d] = q.front();
            q.pop();
            
            ans[node]=d;
            
            for(auto it : adj[node]){
                if(!vis[it]){
                    q.push({it,d+1});
                    vis[it]=1;
                }
            }
        }
        
        return ans;
    }
};
