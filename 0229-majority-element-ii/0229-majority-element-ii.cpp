class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i : nums){
            mp[i]++;
        }

        int n=nums.size();
        vector<int> ans;

        for(auto &[key,val] : mp){
            if(val>n/3) ans.push_back(key);
        }

        return ans;
        
    }
};