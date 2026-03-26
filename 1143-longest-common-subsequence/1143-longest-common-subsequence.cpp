class Solution {
public:
    int find(int n,int m,string &t1, string &t2,vector<vector<int>> &dp){
        if(n==0 || m==0) return 0;
        if(dp[n][m]!=-1) return dp[n][m];
        if(t1[n-1]==t2[m-1])
            return dp[n][m] =  1+find(n-1,m-1,t1,t2,dp);
        else
            return dp[n][m] = max(find(n-1,m,t1,t2,dp),find(n,m-1,t1,t2,dp));
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        return find(n,m,text1,text2,dp);
    }
};