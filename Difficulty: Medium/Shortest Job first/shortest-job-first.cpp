class Solution {
  public:
    int solve(vector<int>& bt) {
        int n=bt.size();
        // code here
        sort(bt.begin(),bt.end());
        int t=0;
        int wt=0;
        
        for(int i : bt){
            wt+=t;
            t+=i;
        }
        
        return wt/n;
    }
};