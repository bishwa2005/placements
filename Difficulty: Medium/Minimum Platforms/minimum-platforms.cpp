class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        sort(arr.begin(),arr.end());
        sort(dep.begin(),dep.end());
        
        int n=arr.size();
        int platform=1;
        int result=1;
        int i=1;
        int j=0;
        
        while(i<n && j<n){
            if(arr[i]<=dep[j]){
                platform++;
                i++;
            }
            else{
                j++;
                platform--;
            }
            result=max(result,platform);
        }
        
        return result;
        
    }
};
