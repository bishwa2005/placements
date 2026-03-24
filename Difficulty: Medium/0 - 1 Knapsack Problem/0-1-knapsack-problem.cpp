class Solution {
public:
    int find(int capacity, vector<int> &val, vector<int> &wt, int n, vector<vector<int>> &dp) {
        if (n == 0 || capacity == 0) return 0;

        if (dp[n][capacity] != -1) return dp[n][capacity];

        if (wt[n - 1] <= capacity) {
            return dp[n][capacity] = max(
                val[n - 1] + find(capacity - wt[n - 1], val, wt, n - 1, dp), // take
                find(capacity, val, wt, n - 1, dp)                           // not take
            );
        } else {
            return dp[n][capacity] = find(capacity, val, wt, n - 1, dp);
        }
    }

    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = val.size();
        vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
        return find(W, val, wt, n, dp);
    }
};