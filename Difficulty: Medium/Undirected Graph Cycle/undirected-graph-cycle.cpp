class Solution {
public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        
        vector<vector<int>> adj(V);
        for(auto it : edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int> vis(V, 0);
        
        for(int i = 0; i < V; i++){
            if(!vis[i]){  // check every component
                
                queue<pair<int,int>> q;
                q.push({i, -1});
                vis[i] = 1;
                
                while(!q.empty()){
                    int node = q.front().first;
                    int parent = q.front().second;
                    q.pop();
                    
                    for(auto it : adj[node]){
                        if(!vis[it]){
                            vis[it] = 1;
                            q.push({it, node});
                        }
                        else if(parent != it){
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
};