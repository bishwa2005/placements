class Solution {
  public:
    void sortStack(stack<int> &st) {
        // code here
        vector<int> ans;
        
        while(st.size()){
            ans.push_back(st.top());
            st.pop();
        }
        
        sort(ans.begin(),ans.end());
        
        for(auto i : ans){
            st.push(i);
        }
    }
};
