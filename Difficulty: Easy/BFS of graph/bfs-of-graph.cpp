class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        int n=adj.size();
        queue<int> q;
        vector<int> vis(n,0);
        
        q.push(0);
        vis[0]=1;
        
        vector<int> bfs;
        while(q.size()){
            int node=q.front();
            q.pop();
            bfs.push_back(node);
            for(auto ad : adj[node]){
                if(!vis[ad]){
                    vis[ad]=1;
                    q.push(ad);
                }
            }
        }
        
        return bfs;
        
    }
};