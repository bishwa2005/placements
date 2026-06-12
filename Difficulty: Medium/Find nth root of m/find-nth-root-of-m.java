class Solution {
    public int nthRoot(int n, int m) {
        // code here
        int lo=0;
        int hi=m;
        
        while(lo<=hi){
            int mid=(lo+hi)/2;
            int ans=1;
            
            for(int i=0;i<n;i++){
                ans*=mid;
            }
            
            if(ans==m) return mid;
            if(ans>m) hi=mid-1;
            else lo=mid+1;
        }
        
        return -1;
    }
}