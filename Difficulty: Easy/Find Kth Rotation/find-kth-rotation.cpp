class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int lo=0;
        int hi=arr.size()-1;
        
        int ans=INT_MAX;
        int idx=-1;
        
        while(lo<=hi){
            int mid=(lo+hi)/2;
            
            if(arr[lo]<=arr[mid]){
                if(arr[lo]<ans){
                    ans=arr[lo];
                    idx=lo;
                }
                lo=mid+1;
            }
            
            else{
                if(arr[mid]<ans){
                    ans=arr[mid];
                    idx=mid;
                }
                hi=mid-1;
            }
        }
        
        return idx;
    }
};
