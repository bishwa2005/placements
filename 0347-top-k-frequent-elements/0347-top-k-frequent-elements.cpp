class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        for(int i : nums){
            mp[i]++;
        }

        priority_queue<pair<int,int>> pq;
        for(auto it:mp){
            int freq = it.second;
            int ele = it.first;
            pq.push({freq,ele});
        }

        vector<int> ans;
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;

    }
};