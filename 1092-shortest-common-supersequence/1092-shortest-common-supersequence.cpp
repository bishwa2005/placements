class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int m = str1.size();
        int n=str2.size();

        vector<vector<int>> dp(m+1,vector<int>(n+1,0));

        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(str1[i-1]==str2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }

        int k=m;
        int l=n;

        string ans="";

        while(k>0 && l>0){
            if(str1[k-1]==str2[l-1]){
                ans+=str1[k-1];
                k--;
                l--;
            }
            else{
                if(dp[k-1][l]>dp[k][l-1]){
                    ans+=str1[k-1];
                    k--;
                }
                else{
                    ans+=str2[l-1];
                    l--;
                }
            }
        }

        while(k>0){
            ans+=str1[k-1];
            k--;
        }
        while(l>0){
            ans+=str2[l-1];
            l--;
        }

        reverse(ans.begin(),ans.end());

        return ans;
    }
};