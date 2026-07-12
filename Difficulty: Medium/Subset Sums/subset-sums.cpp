class Solution {
  public:
    void solve(int idx,vector<int> &arr,vector<int> &ans,int sums){
        if(idx==arr.size()){
            ans.push_back(sums);
            return;
        }
        
        solve(idx+1,arr,ans,sums+arr[idx]);
        solve(idx+1,arr,ans,sums);
        
    }
  
    vector<int> subsetSums(vector<int>& arr) {
        // code
        vector<int> ans;
        int sums=0;
        solve(0,arr,ans,sums);
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};