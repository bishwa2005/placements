class Solution {
  public:
    void solve(int idx,vector<int> &arr,int n,int curr,vector<int> &ans){
        if(idx==n){
            ans.push_back(curr);
            return;
        }
        solve(idx+1,arr,n,curr+arr[idx],ans);
        solve(idx+1,arr,n,curr,ans);   
    }
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        int n=arr.size();
        int idx=0;
        vector<int> ans;
        int curr=0;
        solve(idx,arr,n,curr,ans);
        return ans;
    }
};