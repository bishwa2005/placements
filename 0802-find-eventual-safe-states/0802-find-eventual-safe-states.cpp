class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();

        vector<vector<int>> rev(n);
        vector<int> outdegree(n);

        for(int i=0;i<n;i++){
            outdegree[i] = graph[i].size();
            for(int v : graph[i]){
                rev[v].push_back(i);
            }
        }

        queue<int> q;

        for(int i=0;i<n;i++){
            if(outdegree[i]==0){
                q.push(i);
            }
        }

        vector<int> safe;

        while(!q.empty()){
            int node = q.front();
            q.pop();

            safe.push_back(node);

            for(int parent : rev[node]){
                outdegree[parent]--;
                if(outdegree[parent]==0){
                    q.push(parent);
                }
            }
        }

        sort(safe.begin(),safe.end());
        return safe;
    }
};