class Solution {
  public:
    int countDistinctPairs(vector<int> &arr, int target) {
        // Code here
        unordered_set<int> st;
        set<pair<int,int>> pr;
        
        for(int i : arr){
            int rem = target - i;
            if(st.count(rem)){
                pr.insert({min(i,rem),max(i,rem)});
            }
            st.insert(i);
        }
        
        return pr.size();
    }
};