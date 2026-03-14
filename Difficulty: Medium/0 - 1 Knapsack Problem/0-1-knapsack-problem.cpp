class Solution {
public:
    int solve(int n,int W,vector<int>& val,vector<int>& wt,vector<vector<int>>& dp){
        if(n==0 || W==0) return 0;

        if(dp[n][W] != -1) return dp[n][W];

        if(wt[n-1] <= W){
            return dp[n][W] = max(val[n-1] + solve(n-1,W-wt[n-1],val,wt,dp),
                                  solve(n-1,W,val,wt,dp));
        }

        return dp[n][W] = solve(n-1,W,val,wt,dp);
    }

    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        vector<vector<int>> dp(n+1, vector<int>(W+1,-1));

        return solve(n,W,val,wt,dp);
    }
};