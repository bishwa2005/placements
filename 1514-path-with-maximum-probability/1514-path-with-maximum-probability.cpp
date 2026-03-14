class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        vector<vector<pair<int,double>>> adj(n);

        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            double p = succProb[i];

            adj[u].push_back({v,p});
            adj[v].push_back({u,p});
        }

        priority_queue<pair<double,int>> pq;

        vector<double> prob(n,0.0);
        prob[start] = 1.0;

        pq.push({1.0,start});

        while(!pq.empty()){
            auto [p,node] = pq.top();
            pq.pop();

            if(node == end) return p;

            for(auto &it : adj[node]){
                int next = it.first;
                double edgeProb = it.second;

                double newProb = p * edgeProb;

                if(newProb > prob[next]){
                    prob[next] = newProb;
                    pq.push({newProb,next});
                }
            }
        }

        return 0.0;
    }
};