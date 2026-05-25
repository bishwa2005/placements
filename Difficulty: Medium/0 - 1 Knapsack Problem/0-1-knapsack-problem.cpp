class Solution {
  public:
    int solve(vector<int> &wt, vector<int> &val, int W,int n,vector<vector<int>> &dp){
        if(n==0 || W==0) return 0;
        if(dp[n][W]!=-1) return dp[n][W];
        if(wt[n-1]<=W){
            return dp[n][W]=max(val[n-1]+solve(wt,val,W-wt[n-1],n-1,dp),solve(wt,val,W,n-1,dp));
        }
        
        else{
            return dp[n][W]=solve(wt,val,W,n-1,dp);
        }
    }
    
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n=val.size();
        vector<vector<int>> dp(n+1,vector<int>(W+1,-1));
        return solve(wt,val,W,n,dp);
    }
};