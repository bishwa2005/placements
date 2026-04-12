class Solution {
public:
    int palPartition(string &s) {
        int n = s.size();
        
        // Step 1: Precompute palindrome table
        vector<vector<bool>> isPal(n, vector<bool>(n, false));
        
        for(int i = 0; i < n; i++){
            isPal[i][i] = true;
        }
        
        for(int len = 2; len <= n; len++){
            for(int i = 0; i <= n - len; i++){
                int j = i + len - 1;
                
                if(s[i] == s[j]){
                    if(len == 2)
                        isPal[i][j] = true;
                    else
                        isPal[i][j] = isPal[i+1][j-1];
                }
            }
        }
        
        // Step 2: DP array
        vector<int> dp(n, 0);
        
        for(int i = 0; i < n; i++){
            
            // If whole substring (0 → i) is palindrome
            if(isPal[0][i]){
                dp[i] = 0;
                continue;
            }
            
            int mini = INT_MAX;
            
            for(int j = 0; j < i; j++){
                if(isPal[j+1][i]){
                    mini = min(mini, dp[j] + 1);
                }
            }
            
            dp[i] = mini;
        }
        
        return dp[n-1];
    }
};