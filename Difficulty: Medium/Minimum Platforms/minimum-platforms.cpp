class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        int ans=1;
        int plat=1;
        int i=1;
        int j=0;
        
        int n=arr.size();
        
        while(i<n && j<n){
            if(dep[j]>=arr[i]){
                i++;
                plat++;
            }
            else{
                j++;
                plat--;
            }
            ans=max(ans,plat);
        }
        
        return ans;
    }
};
