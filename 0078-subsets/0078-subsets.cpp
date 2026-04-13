class Solution {
public:
    void helper(int idx,vector<int>& nums,vector<int>& path,vector<vector<int>>& ans){
        if(idx==nums.size()){
            ans.push_back(path);
            return;
        }
        path.push_back(nums[idx]);
        helper(idx+1,nums,path,ans);
        path.pop_back();
        helper(idx+1,nums,path,ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> path;
        vector<vector<int>> ans;
        helper(0,nums,path,ans);
        return ans;

    }
};