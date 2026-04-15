class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int a=10001;

        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                a=min(a,abs(i-start));
            }
        }

        return a;
    }
};