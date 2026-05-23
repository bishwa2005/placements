class Solution {
  public:
    void solve(vector<int>& arr,int idx,vector<int>& ans){
        if(idx==arr.size()) return;
        int ar = arr[idx];
        idx++;
        solve(arr,idx,ans);
        ans.push_back(ar);
    }
    void reverseArray(vector<int> &arr) {
        // code here
        vector<int> ans;
        solve(arr,0,ans);
        arr=ans;
    }
};