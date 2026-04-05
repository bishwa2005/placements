class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        int sum = 0;
        for (int x : nums) sum += x;

        // 🔴 Edge case check
        if ((sum + target) % 2 != 0 || abs(target) > sum) return 0;

        int s = (sum + target) / 2;

        vector<vector<long long>> dp(n + 1, vector<long long>(s + 1, 0));

        // base case
        for (int i = 0; i <= n; i++) dp[i][0] = 1;

        // DP
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= s; j++) {
                if (nums[i - 1] <= j)
                    dp[i][j] = dp[i - 1][j - nums[i - 1]] + dp[i - 1][j];
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }

        return dp[n][s];
    }
};