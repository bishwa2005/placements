class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<vector<int>> adj(V);
        for(auto it : edges){
            int u=it[0];
            int v=it[1];
            adj[u].push_back(v);
            
        }
        
        vector<int> indegree(V);
        queue<int> q;
        
        for(int i=0;i<V;i++){
            for(auto it : adj[i])
                indegree[it]++;
        }
        
        for(int i=0;i<V;i++){
            if(indegree[i]==0) q.push(i);
        }
        
        vector<int> ans;
        while(q.size()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(int n : adj[node]){
                indegree[n]--;
                if(indegree[n]==0) q.push(n);
            }
        }
        return ans;
    }
};