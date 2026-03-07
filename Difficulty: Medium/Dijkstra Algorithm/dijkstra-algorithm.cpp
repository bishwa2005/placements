class Solution {
public:
    typedef pair<int,int> pr;

    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {

        vector<vector<pair<int,int>>> adj(V);

        // convert edge list -> adjacency list
        for(auto &e : edges){
            int u = e[0];
            int v = e[1];
            int w = e[2];

            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        priority_queue<pr, vector<pr>, greater<pr>> pq;
        vector<int> ans(V, INT_MAX);

        ans[src] = 0;
        pq.push({0, src});

        while(!pq.empty()){
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto it : adj[node]){
                int n = it.first;
                int dist = it.second;

                if(ans[n] > d + dist){
                    ans[n] = d + dist;
                    pq.push({ans[n], n});
                }
            }
        }

        return ans;
    }
};