class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);

        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int ans = 0;
        vector<int> vis(n,0);

        for (int i = 0; i < n; i++) {
            if (vis[i] == 1)
                continue;

            int nodes = 0;
            int edges = 0;

            queue<int> q;
            q.push(i);

            
            vis[i] = 1;

            while (q.size()) {
                int node = q.front();
                q.pop();

                nodes++;
                edges += adj[node].size();

                for (auto it : adj[node]) {
                    if (!vis[it]) {
                        vis[it] = 1;
                        q.push(it);
                    }
                }
            }

            edges/=2;
            ans+= (edges==(nodes*(nodes-1))/2) ? 1 : 0;
        }

        return ans;
    }
};