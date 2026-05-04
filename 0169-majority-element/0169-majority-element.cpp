class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int mj = nums[0];
        int cnt = 1;

        for(int i : nums){
            if(i == mj) cnt++;
            else if(i != mj) cnt--;
            if(cnt==0){
                cnt=1;
                mj=i;
            }
            
        }

        return mj;
    }
};