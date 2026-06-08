class Solution {
  public:
    bool solve(vector<int> &arr,int k,int lo,int hi){
        if(lo>hi) return false;
        int mid=(lo+hi)/2;
        if(arr[mid]==k) return true;
        else if(arr[mid]>k) return solve(arr,k,lo,mid-1);
        else solve(arr,k,mid+1,hi);
    }
    bool binarySearch(vector<int>& arr, int k) {
        // code here
        int lo=0;
        int hi=arr.size()-1;
        
        return solve(arr,k,lo,hi);
    }
};