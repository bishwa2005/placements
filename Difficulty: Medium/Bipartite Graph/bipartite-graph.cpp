class Solution {
public:

    bool dfs(int i, vector<int>& color, vector<vector<int>>& adj){
        for(auto node : adj[i]){
            if(color[node] == -1){
                color[node] = 1 - color[i];
                if(!dfs(node, color, adj)) return false;
            }
            else if(color[node] == color[i]){
                return false;
            }
        }
        return true;
    }

    bool isBipartite(int V, vector<vector<int>> &edges) {

        vector<vector<int>> adj(V);

        for(auto &it : edges){
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> color(V,-1);

        for(int i=0;i<V;i++){
            if(color[i]==-1){
                color[i]=0;
                if(!dfs(i,color,adj)) return false;
            }
        }

        return true;
    }
};