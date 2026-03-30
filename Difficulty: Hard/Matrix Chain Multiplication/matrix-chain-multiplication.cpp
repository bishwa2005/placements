class Solution {
public:
    int solve(vector<int> &arr, int i, int j, vector<vector<int>> &dp) {
        // Base case
        if (i >= j) return 0;

        // Check memo
        if (dp[i][j] != -1) return dp[i][j];

        int mn = INT_MAX;

        // Partition
        for (int k = i; k <= j - 1; k++) {
            int left = solve(arr, i, k, dp);
            int right = solve(arr, k + 1, j, dp);

            int cost = arr[i - 1] * arr[k] * arr[j];

            mn = min(mn, left + right + cost);
        }

        return dp[i][j] = mn;
    }

    int matrixMultiplication(vector<int> &arr) {
        int n = arr.size();

        // DP table
        vector<vector<int>> dp(n, vector<int>(n, -1));

        return solve(arr, 1, n - 1, dp);
    }
};