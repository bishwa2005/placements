class Solution {
  public:
    typedef pair<int,pair<int,int>> pr;
    vector<int> mergeArrays(vector<vector<int>> &mat) {
        // Code here
        int k=mat.size();
        priority_queue<pr,vector<pr>,greater<pr>> pq;
        
        for(int i=0;i<k;i++){
            pq.push({mat[i][0],{i,0}});
        }
        
        vector<int> ans;
        
        while(pq.size()){
            int ele = pq.top().first;
            int ar = pq.top().second.first;
            int idx = pq.top().second.second;
            pq.pop();
            
            ans.push_back(ele);
            
            if(idx+1<mat[ar].size()) pq.push({mat[ar][idx+1],{ar,idx+1}});
        }
        
        return ans;
    }
};