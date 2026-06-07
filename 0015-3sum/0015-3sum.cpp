class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());

        for(int i=0;i<nums.size()-1;i++){
            while(i>0 && nums[i]==nums[i-1]) continue;
            int k=i+1;
            int j=nums.size()-1;
            while(k<j){
                if(nums[i]+nums[j]+nums[k]==0){
                    while (k < j && nums[k] == nums[k + 1]) k++;
                    while (k < j && nums[j] == nums[j - 1]) j--;
                    ans.push_back({nums[i],nums[j],nums[k]});
                    k++;
                    j--;
                }
                if(nums[i]+nums[j]+nums[k]>0)
                    j--;
                else
                    k++;
            }
        }

        return ans;
    }
};