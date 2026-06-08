class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {   
        int lo=0;
        int hi=nums.size()-1;
        int idx=nums.size();
        while(lo<=hi){
            int mid=(lo+hi)/2;
            if(nums[mid]>=target){
                idx=mid;
                hi=mid-1;
            }
            else lo=mid+1;
        } 

        return idx;  
    }
};