class Solution {
public:
    int solve(int n){
        int ans=0;
        while(n){
            int d=n%10;
            n/=10;
            ans+=d;
        }
        return ans;
    }

    int minElement(vector<int>& nums) {
        int n=nums.size();
        int ans=INT_MAX;

        for(int i=0;i<n;i++){
            int s=solve(nums[i]);
            ans=min(ans,s);
        }

        return ans;
    }
};