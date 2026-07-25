class Solution {
public:
    void solve(int idx, int k, int n, vector<int>& ds,
               vector<vector<int>>& ans) {

        if (n == 0 && ds.size() == k) {
            ans.push_back(ds);
            return;
        }

        if (idx > 9 || n < 0 || ds.size() > k)
            return;

        // Take current number
        ds.push_back(idx);
        solve(idx + 1, k, n - idx, ds, ans);
        ds.pop_back();

        // Skip current number
        solve(idx + 1, k, n, ds, ans);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> ds;
        solve(1, k, n, ds, ans);
        return ans;
    }
};