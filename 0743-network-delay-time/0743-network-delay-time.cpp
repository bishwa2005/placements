class Solution {
public:
    typedef pair<int,int> pr;

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        vector<vector<pr>> adj(n+1);
        
        for(auto it : times){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            adj[u].push_back({w,v});
        }

        priority_queue<pr, vector<pr>, greater<pr>> pq;
        pq.push({0,k});

        vector<int> dis(n+1, INT_MAX);
        dis[k] = 0;

        while(!pq.empty()){
            int d = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            for(auto it : adj[node]){
                int wt = it.first;
                int adjnode = it.second;

                if(d + wt < dis[adjnode]){
                    dis[adjnode] = d + wt;
                    pq.push({dis[adjnode], adjnode});
                }
            }
        }

        int ans = 0;

        for(int i = 1; i <= n; i++){
            if(dis[i] == INT_MAX) return -1;
            ans = max(ans, dis[i]);
        }

        return ans;
    }
};