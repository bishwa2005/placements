// User function Template for C++

class Solution {
  public:
    int cutRod(vector<int> &price) {
        // code here
        int n=price.size();
        vector<int> len;
        for(int i=1;i<=n;i++){
            len.push_back(i);
        }        
        
        vector<vector<int>> dp(n+1,vector<int>(n+1,0));
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(len[i-1]<=j){
                    dp[i][j]=max(price[i-1]+dp[i][j-len[i-1]],dp[i-1][j]);
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        
        return dp[n][n];
    }
};
