class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        int m=arr.size();
        sort(arr.begin(),arr.end());
        
        int n=dep.size();
        sort(dep.begin(),dep.end());
        
        int i=1;
        int j=0;
        int final=1;
        int plat=1;
        
        while(i<m && j<n){
            if(arr[i]<=dep[j]){
                plat++;
                i++;
            }
            else{
                plat--;
                j++;
            }
            
            final=max(plat,final);
        }
        
        return final;
    }
};
