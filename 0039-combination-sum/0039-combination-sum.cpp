class Solution {
public:
    // helper
    void find_combinations(int idx,vector<int>& candidates,int target,vector<vector<int>>& ans,vector<int>&ds){
        if(idx==candidates.size()){
            if(target==0){
                ans.push_back(ds);
            }
            return;
        }

        // pick element
        if(candidates[idx]<=target){
            ds.push_back(candidates[idx]);
            find_combinations(idx,candidates,target-candidates[idx],ans,ds);
            ds.pop_back();
        }

        find_combinations(idx+1,candidates,target,ans,ds);
    };

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> ds;
        find_combinations(0,candidates,target,ans,ds);
        return ans;
    }
};
