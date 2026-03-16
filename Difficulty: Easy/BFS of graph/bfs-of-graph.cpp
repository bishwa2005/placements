class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        int v=adj.size();
        vector<int> vis(v,0);
        vector<int> ans;
        
        for(int i=0;i<v;i++){
            if(!vis[i]){
                queue<int> q;
                q.push(i);
                vis[i]=1;
                while(q.size()){
                    int node=q.front();
                    q.pop();
                    ans.push_back(node);
                    for(auto it : adj[node]){
                        if(!vis[it]){
                            vis[it]=1;
                            q.push(it);
                        }
                        
                    }
                }
            }
        }
        
        return ans;
    }
};