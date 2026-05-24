class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int idx;
        for(int i=n-1;i>0;i--){
            if(nums[i]>nums[i-1]){
                idx=i;
                break;
            }
        }

        if(idx!=0){
            int idx2=idx;
            for(int j=n-1;j>=idx;j--){
                if(nums[j]>nums[idx-1]){
                    idx2=j;
                    break;
                }
            }
            swap(nums[idx-1],nums[idx2]);
        }

        reverse(nums.begin()+idx,nums.end());
    }
};