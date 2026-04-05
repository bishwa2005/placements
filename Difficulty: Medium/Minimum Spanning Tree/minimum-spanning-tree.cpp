class Solution {
  public:
    int spanningTree(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<pair<int,int>>> adj(V);
        for(auto &e : edges){
            int u=e[0],v=e[1],w=e[2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        // {w,u}
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        pq.push({0,0});
        
        vector<int> vis(V,0);
        
        int sum=0;
        while(pq.size()){
            auto [w,node] = pq.top();
            pq.pop();
            if(vis[node]) continue;
            sum+=w;
            vis[node]=1;
            for(auto it : adj[node]){
                auto [nd,wt] = it;
                if(!vis[nd]){
                    pq.push({wt,nd});
                }
            }
            
        }
        
        return sum;
    }
};