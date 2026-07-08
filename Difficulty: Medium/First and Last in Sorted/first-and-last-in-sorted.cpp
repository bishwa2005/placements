class Solution {
  public:
    vector<int> find(vector<int>& arr, int x) {
        // code here
        int idx1=-1;
        int idx2=-1;
        
        int n=arr.size();
        
        for(int i=0;i<n;i++){
            if(idx1==-1 && arr[i]==x) idx1=i;
            if(arr[i]==x) idx2=i;
            
        }
        
        if(idx1==-1) return {-1,-1};
        return {idx1,idx2};
    }
};