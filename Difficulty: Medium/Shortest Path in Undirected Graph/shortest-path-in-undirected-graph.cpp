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
        
        vector<int> dist(V,-1);
        vector<int> vis(V,0);
        queue<pair<int,int>> q;
        
        q.push({src,0});
        vis[src]=1;
        
        while(q.size()){
            int node=q.front().first;
            int d=q.front().second;
            q.pop();
            dist[node]=d;
            
            for(auto it : adj[node]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push({it,d+1});
                }
            }
        }
        
        return dist;
    }
};
