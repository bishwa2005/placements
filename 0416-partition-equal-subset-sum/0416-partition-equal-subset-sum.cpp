class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int n=nums.size();
        for(int i : nums){
            sum+=i;
        }

        if(sum%2) return false;

        vector<vector<bool>> dp(n+1,vector<bool>(sum/2 + 1));

        for(int i=0;i<=n;i++){
            dp[i][0]=true;
        }
        for(int j=1;j<=sum/2;j++){
            dp[0][j]=false;
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum/2;j++){
                if(nums[i-1]<=j){
                    dp[i][j]=dp[i-1][j-nums[i-1]] || dp[i-1][j];
                }
                else dp[i][j]=dp[i-1][j];
            }
        }

        return dp[n][sum/2];
    }
};