class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        
        int n = nums.size();
        int sum = 0;
        
        for(int x : nums)
            sum += x;

        if(sum < abs(target)) return 0;
        
        if((sum - target) % 2 != 0)
            return 0;

        int diff = (sum - target) / 2;

        vector<vector<int>> dp(n+1, vector<int>(diff+1,0));

        for(int i=0;i<=n;i++)
            dp[i][0] = 1;

        for(int i=1;i<=n;i++){
            for(int j=0;j<=diff;j++){
                
                if(nums[i-1] <= j)
                    dp[i][j] = dp[i-1][j] + dp[i-1][j-nums[i-1]];
                else
                    dp[i][j] = dp[i-1][j];
            }
        }

        return dp[n][diff];
    }
};