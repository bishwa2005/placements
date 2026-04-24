class Solution {
  public:
    int countDistinctPairs(vector<int> &arr, int target) {
        // Code here
        unordered_set<int> st;
        set<pair<int,int>> mp;
        
        for(int i=0;i<arr.size();i++){
            int comp = target - arr[i];
            if(st.count(comp)){
                mp.insert({min(comp,arr[i]),max(comp,arr[i])});
            }
            st.insert(arr[i]);
        }
        
        return mp.size();
    }
};