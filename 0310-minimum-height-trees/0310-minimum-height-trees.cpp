class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {

        if(n == 1) return {0};

        vector<vector<int>> adj(n);
        vector<int> degree(n,0);

        // Build graph
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);

            degree[u]++;
            degree[v]++;
        }

        queue<int> q;

        // Push all leaves
        for(int i=0;i<n;i++){
            if(degree[i] == 1){
                q.push(i);
            }
        }

        int remaining = n;

        // Toposort style BFS
        while(remaining > 2){

            int size = q.size();
            remaining -= size;

            while(size--){
                int node = q.front();
                q.pop();

                for(auto it : adj[node]){
                    degree[it]--;

                    if(degree[it] == 1){
                        q.push(it);
                    }
                }
            }
        }

        vector<int> ans;

        while(!q.empty()){
            ans.push_back(q.front());
            q.pop();
        }

        return ans;
    }
};