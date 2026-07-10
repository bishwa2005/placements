
class Solution {
  public:
    int findClosest(vector<int>& arr, int k) {
        int n=arr.size();
        int i=0;
        int j=n-1;
        int res=arr[0];
        
        while(i<=j){
            int mid=(i+j)/2;
            
            if(abs(arr[mid]-k)<abs(res-k)){
                res=arr[mid];
            }
            else if(abs(arr[mid]-k)==abs(res-k)){
                res=max(res,arr[mid]);
            }
            
            if(arr[mid]==k) 
                return arr[mid];
                
            else if(arr[mid]<k)
                i=mid+1;
            else 
                j=mid-1;
        }
        
        return res;
    }
};