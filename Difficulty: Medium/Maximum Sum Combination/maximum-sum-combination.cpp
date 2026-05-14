class Solution {
  public:
    vector<int> topKSumPairs(vector<int>& a, vector<int>& b, int k) {
        // code here
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        
        int n=a.size();
        
        priority_queue<pair<int,pair<int,int>>> pq;
        set<pair<int,int>> vis;
        
        vector<int> ans;
        
        int i=n-1;
        int j=n-1;
        pq.push({a[i]+b[j],{i,j}});
        vis.insert({i,j});
        
        while(k--){
            int sum = pq.top().first;
            int i=pq.top().second.first;
            int j=pq.top().second.second;
            pq.pop();
            
            ans.push_back(sum);
            
            if((i-1 >= 0) && !vis.count({i-1,j})){
                pq.push({a[i-1]+b[j],{i-1,j}});
                vis.insert({i-1,j});
            }
            
            if((j-1 >= 0) && !vis.count({i,j-1})){
                pq.push({a[i]+b[j-1],{i,j-1}});
                vis.insert({i,j-1});
            }
        }
        
        return ans;
    }
};