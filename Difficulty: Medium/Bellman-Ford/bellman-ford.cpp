// User function Template for C++

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int> ans(V,1e8);
        ans[src]=0;
       
        for(int i=0;i<V-1;i++){
            
            for(auto &e : edges){
                int u = e[0];
                int v = e[1];
                int w = e[2];
    
                if(ans[u]!=1e8 && ans[v]> w+ans[u]){
                    ans[v]=w+ans[u];
                }
            }
        } 
        
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];

            if(ans[u]!=1e8 && ans[v]> w+ans[u]){
                return {-1};
            }
        }
        
        return ans;
    }
};
