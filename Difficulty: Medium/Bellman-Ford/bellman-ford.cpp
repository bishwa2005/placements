// User function Template for C++

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int> dis(V,1e8);
        dis[src]=0;
        
        for(int i=0;i<V-1;i++){
            for(auto it : edges){
                int u=it[0];
                int v=it[1];
                int d=it[2];
                
                if(dis[u]!=1e8 && dis[v]>d+dis[u]){
                    dis[v]=d+dis[u];
                }
            }
            
        }
        
        // checking negative cycles
        for(auto it : edges){
                int u=it[0];
                int v=it[1];
                int d=it[2];
                
                if(dis[u]!=1e8 && dis[v]>d+dis[u]){
                    return {-1};
                }
        }
        
        return dis;
    }
};
