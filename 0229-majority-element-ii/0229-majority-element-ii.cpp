class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> mp;

        for(int i : nums){
            mp[i]++;
        }

        vector<int> ans;
        for(auto [key,val] : mp){
            if(val > n/3) ans.push_back(key);
        }

        return ans;
    }
};