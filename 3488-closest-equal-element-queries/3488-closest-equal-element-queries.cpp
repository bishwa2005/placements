class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        
        unordered_map<int, vector<int>> mp;
        
        // Step 1: store indices
        for(int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        
        vector<int> ans;
        
        for(int q : queries) {
            int val = nums[q];
            auto &vec = mp[val];
            
            // If only one occurrence
            if(vec.size() == 1) {
                ans.push_back(-1);
                continue;
            }
            
            // Binary search
            int idx = lower_bound(vec.begin(), vec.end(), q) - vec.begin();
            
            int res = INT_MAX;
            
            // Check left neighbor
            int left = (idx - 1 + vec.size()) % vec.size();
            int d1 = abs(q - vec[left]);
            d1 = min(d1, n - d1);
            
            // Check right neighbor
            int right = (idx + 1) % vec.size();
            int d2 = abs(q - vec[right]);
            d2 = min(d2, n - d2);
            
            res = min(d1, d2);
            
            ans.push_back(res);
        }
        
        return ans;
    }
};