class Solution {
public:
    void solve(int idx,vector<int> &nums,vector<int> &d,vector<vector<int>> &ans){
        if(idx==nums.size()){
            ans.push_back(d);
            return;
        }
        d.push_back(nums[idx]);
        solve(idx+1,nums,d,ans);
        d.pop_back();
        solve(idx+1,nums,d,ans);

    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> d;
        vector<vector<int>> ans;
        solve(0,nums,d,ans);
        return ans;
    }
};