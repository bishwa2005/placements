class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        int n=arr.size();
        // code here
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        
        int plat=1;
        int result=1;
        int i=1;
        int j=0;
        
        while(i<n && j<n){
            if(arr[i]<=dep[j]){
                plat++;
                i++;
            }
            else{
                plat--;
                j++;
            }
            result=max(result,plat);
        }
        
        return result;
    }
};
