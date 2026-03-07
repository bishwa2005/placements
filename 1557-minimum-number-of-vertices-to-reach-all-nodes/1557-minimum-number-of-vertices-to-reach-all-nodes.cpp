class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        // find the nodes whose indegree in 0
        vector<int> indegree(n);
        for(auto it : edges){
            indegree[it[1]]++;
        }

        vector<int> ans;

        for(int i=0;i<n;i++){
            if(indegree[i]==0) ans.push_back(i);
        }

        return ans;


    }
};