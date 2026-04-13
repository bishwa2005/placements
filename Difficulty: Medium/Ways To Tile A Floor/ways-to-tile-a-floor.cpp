class Solution {
  public:
    int countRecur(int n, vector<int> &dp) {
    
        if (n<0) return 0;
        if (n == 0) return 1;
        
        if (dp[n] != -1) return dp[n];
        
        int ans = 0;
        
        ans = countRecur(n-1, dp);
        ans += countRecur(n-2, dp);
        
        return dp[n] = ans;
    }
    
    int numberOfWays(int n) {
        vector<int> dp(n+1, -1);
        return countRecur(n, dp);
    }
};