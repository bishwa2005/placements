class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        // kadane algo for max sub array sum
        int maxi=INT_MIN;
        int curr=0;
        for(int i=0;i<nums.size();i++){
            curr+=nums[i];
            maxi=max(maxi,curr);
            if(curr<0) curr=0;
        }

        // kadane algo for min subarray sum
        int mini=INT_MAX;
        curr=0;
        for(int i=0;i<nums.size();i++){
            curr+=nums[i];
            mini=min(mini,curr);
            if(curr>0) curr=0;
        }

        
        return max(abs(maxi),abs(mini));
    }
};