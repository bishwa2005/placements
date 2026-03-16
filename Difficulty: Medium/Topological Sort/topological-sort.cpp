class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        
        vector<int> indegree(V,0);
        vector<vector<int>> adj(V);
        
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            indegree[v]++;
        }
        
        queue<int> q;
        
        for(int i=0;i<V;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        vector<int> topo;
        
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            topo.push_back(node);
            
            for(auto it : adj[node]){
                indegree[it]--;
                
                if(indegree[it]==0){
                    q.push(it);
                }
            }
        }
        
        return topo;
    }
};