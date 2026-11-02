class Solution {
public:
    int minMoves(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int sum=0;
        int ele=nums[0];

        for(int i : nums){
            sum+=(i-ele);
        }

        return sum;
    }
};