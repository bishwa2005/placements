class Solution {
public:
    vector<bool> checkIfPrerequisite(
        int n,
        vector<vector<int>>& prerequisites,
        vector<vector<int>>& queries) {

        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);

        for(auto &e : prerequisites){
            adj[e[0]].push_back(e[1]);
            indegree[e[1]]++;
        }

        vector<vector<bool>> pre(n, vector<bool>(n,false));

        queue<int> q;

        for(int i=0;i<n;i++){
            if(indegree[i]==0)
                q.push(i);
        }

        while(!q.empty()){
            int u=q.front();
            q.pop();

            for(int v:adj[u]){

                pre[u][v]=true;

                for(int i=0;i<n;i++){
                    if(pre[i][u])
                        pre[i][v]=true;
                }

                indegree[v]--;

                if(indegree[v]==0)
                    q.push(v);
            }
        }

        vector<bool> ans;

        for(auto &qy:queries){
            ans.push_back(pre[qy[0]][qy[1]]);
        }

        return ans;
    }
};