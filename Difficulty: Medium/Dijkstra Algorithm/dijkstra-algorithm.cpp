class Solution {
  public:
    typedef pair<int,int> pr;
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        vector<vector<pair<int,int>>> adj(V);

        // convert edge list -> adjacency list
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        
        priority_queue<pr,vector<pr>,greater<pr>> pq;
        
        vector<int> dis(V,1e8);
        dis[src]=0;
        
        pq.push({0,src});
        
        while(pq.size()){
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto it : adj[node]){
                int edgewt = it.second;
                int adjnode = it.first;
                if(d+edgewt < dis[adjnode]){
                    dis[adjnode] = edgewt+d;
                    pq.push({d+edgewt,adjnode});
                }
            }
        }
        
        return dis;
    }
};