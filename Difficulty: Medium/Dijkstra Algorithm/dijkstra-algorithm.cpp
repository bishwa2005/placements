class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int,int>>> adj(V);
        for(auto it : edges){
            int u=it[0];
            int v=it[1];
            int w=it[2];
            
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
            
        }
        
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(V,1e8);
        pq.push({0,src});
        dist[src]=0;
        
        while(pq.size()){
            int n=pq.top().second;
            int d=pq.top().first;
            pq.pop();
            
            for(auto it : adj[n]){
                int edgewt = it.second;
                int node = it.first;
                
                if(dist[node] > d+edgewt){
                    dist[node]=d+edgewt;
                    pq.push({dist[node],node});
                }
            }
        }
        
        return dist;
    }
};