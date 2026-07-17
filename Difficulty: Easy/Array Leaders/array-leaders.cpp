class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
        // code here
        int n=arr.size();
        stack<int> st;
        
        for(int i=n-1;i>=0;i--){
            if(st.empty()) st.push(arr[i]);
            else if(st.top()<=arr[i]){
                st.push(arr[i]);
            }
        }
        
        vector<int> ans;
        
        while(st.size()){
            ans.push_back(st.top());
            st.pop();
        }
        
        return ans;
    }
};