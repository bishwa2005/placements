class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n);

        for(auto it : edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        queue<int> que;
        que.push(source);
        vector<int> vis(n,0);
        vis[source]=1;

        while(que.size()){
            int node=que.front();
            que.pop();

            for(auto i : adj[node]){
                if(!vis[i])
                    que.push(i);
                    vis[i]=1;
            }
        }

        return vis[destination];
    }
};