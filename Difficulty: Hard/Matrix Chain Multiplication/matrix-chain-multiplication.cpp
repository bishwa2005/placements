class Solution {
  public:
    int solve(int i,int j,vector<int>& arr,vector<vector<int>> &dp){
        if(i>=j) return 0;
        int mini = INT_MAX;
        
        if(dp[i][j]!=-1) return dp[i][j];
        
        for(int k=i;k<=j-1;k++){
            int temp = solve(i,k,arr,dp) + solve(k+1,j,arr,dp) + arr[i-1]*arr[k]*arr[j];
            mini = min(mini,temp);
        }
        
        return dp[i][j] = mini;
        
    }
    
    int matrixMultiplication(vector<int> &arr) {
        // code here
        int i=1;
        int j=arr.size()-1;
        vector<vector<int>> dp(j+1,vector<int>(j+1,-1));
        return solve(i,j,arr,dp);
    }
};