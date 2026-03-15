class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int max_sum=nums[0];
        int curr_sum=0;
        for(int i=0;i<nums.size();i++){
            curr_sum+=nums[i];
            max_sum=max(max_sum,curr_sum);
            if(curr_sum<0) curr_sum=0;
        }
        return max_sum;
    }
    // https://www.youtube.com/watch?v=HCL4_bOd3-4
};