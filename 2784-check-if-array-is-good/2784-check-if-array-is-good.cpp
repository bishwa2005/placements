class Solution {
public:
    bool isGood(vector<int>& nums) {
        unordered_map<int,int> mp;
        int maxi = INT_MIN;
        for(int i : nums){
            if(i>maxi) maxi=i;
            mp[i]++;
        }

        int n=nums.size();
        for(int i=1;i<n-1;i++){
            if(mp[i]!=1) return false;
        }

        return mp[n-1]==2;
    }
};